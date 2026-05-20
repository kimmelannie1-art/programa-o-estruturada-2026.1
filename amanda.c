#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(){
    int opcao=0, idade;

    while (1){
        printf("\n=== MENU ===\n");
        printf("1- Dizer Ola\n");
        printf("2-  Calcular\n");
        printf("3- sair\n");
        printf("escolha: ");
        scanf("%d", &opcao);

        if(opcao==1) {
            printf("Ola turma!\n");
        } else if(opcao==2) {
            printf("aqui você vai calcular!!\n");
             printf("Digite a idade: ");
             scanf("%d", &idade);
            while(idade < 0 || idade > 100) {
                printf("Idade inválida. Digite novamente: ");
                scanf("%d", &idade);
            }

            if (idade >= 0 && idade <= 150) {
                printf("Idade válida: %d\n", idade);
            }

            if (idade < 18) {
                printf("Você é menor de idade.\n");
            }
            else if (idade >= 18 && idade < 65) {
                printf("Você é adulto.\n");
            }
            else if (idade >= 65) {
                printf("Você é idoso.\n");
            }
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
                opcao=0; // Volta para o menu
            }
        }
        else{
            printf("opcao invalida!\n");
        }
    }
    return 0;
}