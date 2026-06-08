#include <stdio.h>/*para entradas e saídas */
#include <stdlib.h>/*ferramentas gerais como alocação de memória */
#include <string.h> /*manipular textos como o nome do sensor*/
#include <time.h> /*hora do sistema*/

#define MAX_POSTES 5 /*definir o número de sensores para analise*/

/* monitoramento de segurança da iluminação pública*/
/*se poste apagar, notificar empresa de energia*/
/*se houver apagão em determinada área, notificar empresa de energia*/
/*desnecessário cliente avisar a empresa sobre a falta de energia*/
/*sensores inteligentes, sistema de comunicação, registro e armazenamento de dados, controle e automação*/
/*criar um arquivo de texto para armazenar os dados de monitoramento*/
/*a variação de queda de energia ocorre devido a problemas de tensão elétrica */
/*voltagem que chega aos imovéis fica abaixo ou acima do padrão regulamentado*/

/*id_poste (Texto / String): Identificador único de cada poste (ex: "P-10243").
id_zona ou id_bairro (Texto / String): Agrupamento regional dos postes (ex: "ZONA_LESTE").
id_transformador (Texto / String): Vincula o poste ao transformador da região. Se vários postes do mesmo transformador falharem,
 o sistema identifica o apagão setorial.
coordenadas (Texto ou Float): Latidude e longitude para localização exata no mapa.*/

/*tensao_eletrica (Numérico / Float): Mede a voltagem atual que chega ao poste/imóvel (ex: 220.5, 180.2, 0.0).

corrente_eletrica (Numérico / Float): Mede o consumo de corrente (Ampères). Ajuda a saber se há energia na linha, mas a lâmpada está quebrada.

status_lampada (Booleano / True-False): Indica se a lâmpada está fisicamente acesa ou apagada (gerada pelo sensor de luminosidade LDR).

True = Acesa / False = Apagada.*/
/*status_rede (Texto ou Inteiro): Define o estado atual daquela região. Pode ser um sistema de códigos ou texto:

"NORMAL": Tensão e funcionamento dentro do padrão.

"OSCILACAO": Tensão fora do padrão regulamentado (subtensão ou sobretensão).

"APAGAO_LOCAL": O poste específico parou de funcionar ou receber energia.

"APAGAO_GERAL": O setor/transformador inteiro perdeu energia.

limiar_subtensao e limiar_sobretensao (Constantes / Float): Os valores limites regulamentados para acionar o alerta de variação de tensão (ex: se a rede é 220V, o limiar inferior pode ser 201.0 e o superior 231.0).*/
/*timestamp (Data e Hora): Registra o momento exato do evento (ex: 2026-06-08 10:45:00).

mensagem_alerta (Texto / String): O texto final que será gravado no arquivo .txt notificando a empresa (ex: "Notificar concessionária: Subtensão detectada").timestamp (Data e Hora): Registra o momento exato do evento (ex: 2026-06-08 10:45:00).

mensagem_alerta (Texto / String): O texto final que será gravado no arquivo .txt notificando a empresa (ex: "Notificar concessionária: Subtensão detectada").*/



typedef struct {
    char id_poste[20];
    char id_zona[20];
    char id_transformador[20];
    float tensao_eletrica;
    float corrente_eletrica;
    char status_rede[20];
    char timestamp[20];
} SensorPoste;

void registrarEvento(SensorPoste poste) {
    FILE *arquivo = fopen("monitoramento_iluminacao.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de monitoramento.\n");
        return;
    }
    fprintf(arquivo, "ID Poste: %s | Zona: %s | Transformador: %s| Tensão: %.2fV | Corrente: %.2fA | Status Rede: %s | Timestamp: %s\n",
            poste.id_poste, poste.id_zona, poste.id_transformador,
            poste.tensao_eletrica, poste.corrente_eletrica,
            poste.status_rede, poste.timestamp);
    fclose(arquivo);
}   
int main() {
    int opcao = -1;
    while (opcao != 0) {
        printf("=== MENU ===\n");
        printf("1- inserir dados do poste\n");
        printf("0- sair\n");
        printf("escolha: ");
        if (scanf("%d", &opcao) != 1) break;

        if (opcao == 1) {
            SensorPoste poste;
            /* valores padrão */
            strcpy(poste.id_poste, "P-00000");
            strcpy(poste.id_zona, "ZONA_X");
            strcpy(poste.id_transformador, "T-00000");
            poste.coordenadas_lat = 0.0f;
            poste.coordenadas_long = 0.0f;
            poste.tensao_eletrica = 0.0f;
            poste.corrente_eletrica = 0.0f;
            poste.status_lampada = 0;
            strcpy(poste.status_rede, "NORMAL");
            strcpy(poste.timestamp, "0000-00-00 00:00:00");

            printf("Digite o ID do poste: ");
            scanf("%19s", poste.id_poste);
            printf("Digite a zona do poste: ");
            scanf("%19s", poste.id_zona);
            printf("Digite o ID do transformador: ");
            scanf("%19s", poste.id_transformador);
            printf("Digite a latitude: ");
            scanf("%f", &poste.coordenadas_lat);
            printf("Digite a longitude: ");
            scanf("%f", &poste.coordenadas_long);
            printf("Digite a tensão elétrica (V): ");
            scanf("%f", &poste.tensao_eletrica);
            printf("Digite a corrente elétrica (A): ");
            scanf("%f", &poste.corrente_eletrica);
            printf("A lâmpada está acesa? (1 para sim, 0 para não): ");
            scanf("%d", &poste.status_lampada);

            /* Verificar status da rede com base na tensão */
            if (poste.tensao_eletrica == 0.0f) {
                strcpy(poste.status_rede, "APAGAO_LOCAL");
                registrarEvento(poste);
                printf("Notificar concessionária: Apagão local detectado.\n");
            } else if (poste.tensao_eletrica < 201.0f || poste.tensao_eletrica > 231.0f) {
                strcpy(poste.status_rede, "OSCILACAO");
                registrarEvento(poste);
                printf("Notificar concessionária: Oscilação de tensão detectada.\n");
            } else {
                strcpy(poste.status_rede, "NORMAL");
                registrarEvento(poste);
                printf("Status normal registrado.\n");
            }
        }
    }
    return 0;
}