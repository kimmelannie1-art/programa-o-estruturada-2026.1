#include <stdio.h>
#include <string.h>

int main(){
    char dados[3][50];
    int ra[8];
    int i;

    for(i=0; i<3; i++){
    printf("digite seu nome %d: ", i+1);
    fgets(dados[i], 50, stdin);

    printf("digite sua ra: ");
    scanf("%d", &ra[i]);

    printf("situação da matricula:");
    scanf("%s", dados[i]);

    getchar();
    }
    printf("\n");
    printf("%d foram cadastrados", i);

    return 0;
}