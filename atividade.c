#include <stdio.h>
#include <string.h>
int main(){
    float consumo[2][5] = {{0}};
    float somaSetor, totalGeral=0;
    float maior=0;

    int setorMaior, diaMaior;
    int opcao=0;
    int i, j;

    while(1){
        printf("\n=== MENU ===\n");
        printf("1- inserir consumo\n");
        printf("2- mostrar matriz\n");
        printf("3- sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

        if(opcao==1) {
             for (i=0; i<2; i++){
                 somaSetor=0;
                 printf("\n setor %d\n", i+1);
                 for (j=0; j<5; j++){
                    printf("digite o consumo do dia %d: ", j+1);
                    scanf("%f", &consumo[i][j]);
                    somaSetor += consumo[i][j];
                    while(consumo[i][j] < 0) {
                        printf("Consumo inválido. Digite novamente: ");
                        scanf("%f", &consumo[i][j]);
                    }
                }
            }
        }
        else if(opcao==2) {
            printf("\nMatriz de Consumo:\n");
            for (i=0; i<2; i++){
                somaSetor=0;
                for (j=0; j<5; j++){
                    printf("%.1f\t", consumo[i][j]);
                    totalGeral += consumo[i][j];
                    somaSetor += consumo[i][j];
                    if(consumo[i][j] > maior) {
                        maior = consumo[i][j];
                        setorMaior = i+1;
                        diaMaior = j+1;
                    }
                }
                printf("\n");
            }
            printf("\nconsumo maior encontrado: %.2f no setor %d dia %d\n", maior, setorMaior, diaMaior);
        }
        else if(opcao==3){
            printf("deseja realmente encerrar? (s/n): ");
            char resposta;
            scanf(" %c", &resposta);
            if(resposta=='s' || resposta=='S') {
                printf("encerrando...\n");
                break;
            }
            else if (resposta=='n' || resposta=='N') {
                printf("retornando ao menu...\n");
                opcao=0;
            }
        }
        else{
            printf("opcao invalida!\n");
        }
    }
    return 0;
} 