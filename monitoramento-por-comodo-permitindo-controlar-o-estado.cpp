#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void monitorarComodo(int *estadoComodo, char nomeComodo[20], char nomeAparelho[20], float consumoEnergia) {
    printf("\n--- ALERTA DE ENERGIA ---\n");
    printf("\n--- menu ---\n");
    printf("1- verificar energia consumida\n");
    printf("2- desligar o aparelho\n");
    printf("0- sair\n");
    int opcao;
    printf("escolha: ");
    if (scanf("%d", &opcao) != 1){
        printf("Entrada invalida. Encerrando o monitoramento.\n");
        return;
    }
    if (opcao==1){
        if (*estadoComodo == 0){
            printf("o comodo não esta consumindo energia\n");
        } else {
            printf("O aparelho %s na %s esta ligado\n", nomeAparelho, nomeComodo);
            printf("O aparelho %s na %s esta consumindo %.2f kWh\n", nomeAparelho, nomeComodo, consumoEnergia);
        }
    } else if (opcao==2){
        if (*estadoComodo == 1){
            *estadoComodo = 0;
            printf("sucesso ao desligar o aparelho %s na %s\n", nomeAparelho, nomeComodo);
        } else {
            printf("O aparelho %s na %s já está desligado\n", nomeAparelho, nomeComodo);
        }
    } else if (opcao==0){
        printf("Encerrando o monitoramento...\n");
    } else {
        printf("Opcao invalida. Tente novamente.\n");
    }
}
int main() {
    int estadoComodo = 1; // 1 para ligado, 0 para desligado
    char nomeComodo[20] = "Sala de Estar";
    char nomeAparelho[20] = "TV";
    float consumoEnergia = 0.5; // consumo em kWh
    int continuar =1;
    while (continuar==1) {
        monitorarComodo(&estadoComodo, nomeComodo, nomeAparelho, consumoEnergia);
        printf("deseja voltar ao menu de monitoramento? (1 - sim, 0 - nao): ");
        if (scanf("%d", &continuar) != 1){
            printf("Entrada invalida. Encerrando o programa.\n");
            break;
        }
    }
    return 0;
}