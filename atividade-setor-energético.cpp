#include<string>
#include<stdlib.h>
#include<stdio.h>

int main(){
    float consumo[3][5]={0};
    float somaSetor=0, totalGeral=0;
    float maior=0;
    int setorMaior=0,diaMaior=0;
    int opcao=-1;
    int i, j;

    while(opcao != 0) {
        printf("\n=== MENU ===\n");
        printf("1- inserir consumo\n");
        printf("2-  mostrar matriz\n");
        printf("3- mostrar maior consumo\n");
        printf("0- sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

      switch(opcao) {
        case 1:
             for (i=0; i<3; i++){
                printf("\n setor %d\n", i+1);
                for (j=0; j<5; j++){
                printf("digite o consumo do dia %d: ", j+1);
                scanf("%f", &consumo[i][j]);

                    while(consumo[i][j] < 0) {
                    printf("Consumo inválido. Digite novamente: ");
                scanf("%f", &consumo[i][j]);
                
                    }
                }
             }break;
            
        case 2:
            printf("\nMatriz de Consumo:\n");
            for (i=0; i<3; i++){
                somaSetor=0;
                for (j=0; j<5; j++){
                    printf("%.1f\t", consumo[i][j]);
                    somaSetor += consumo[i][j];
                    totalGeral += consumo[i][j];       
                    }printf("\n"); 
                }break;

        case 3:
        totalGeral=0;
        maior=0;
            for(i=0; i<3; i++){
                for(j=0;j<5;j++){
                    totalGeral += consumo[i][j];
                    if(consumo[i][j] > maior) {
                        maior = consumo[i][j];
                        setorMaior = i+1;
                        diaMaior = j+1;
                    }
                }
            }
            printf("\nMaior consumo: %.1f\n", maior);
            printf("Setor: %d\n", setorMaior);
            printf("Dia: %d\n", diaMaior);
            printf("Total geral: %.1f\n", totalGeral);
                break;
               
        case 0:
            printf("deseja realmente encerrar? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            if(resposta=='s' || resposta=='S') {
                printf("encerrando...\n");
                opcao=0;
            }
            else if (resposta=='n'|| resposta=='N') {
                printf("retornando ao menu...\n");
                opcao=-1;
            }
        default:
            if(opcao < 0 || opcao > 3) {
                printf("opcao invalida!\n");
            }break;
        }
    } return 0;
}