#include <stdio.h>/*para entradas e saídas */
#include <stdlib.h>/*ferramentas gerais como alocação de memória */
#include <string.h> /*manipular textos como o nome do sensor*/
#include <time.h> /*hora do sistema*/

#define MAX_POSTES 5 /*definir o número de sensores para analise*/

/*intenção de monitoramento de segurança da iluminação pública*/
/*se poste apagar, notificar empresa de energia*/
/*se houver apagão em determinada área, notificar empresa de energia*/
/*desnecessario cliente avisar a empresa sobre a falta de energia*/
/*sensores inteligentes, sistema de comunicação, registro e armazenamento de dados, controle e automação*/
/*criar um arquivo de texto para armazenar os dados de monitoramento*/

typedef struct {
    int  id_do_poste, status;
    float limiteNBR5410, valorAtual;
    char tipo[30];
} Sensor;

void registrarEvento(Sensor sensores[], int numSensores) {
    FILE *arquivo = fopen("monitoramento_iluminacao.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de monitoramento.\n");
        return;
    }
    time_t t=time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(arquivo, "Data: %02d/%02d/%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);


    fclose(arquivo);
}