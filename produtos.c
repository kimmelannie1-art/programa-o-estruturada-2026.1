#include <stdio.h>
#include <string.h>
int main(){
    char produtos[5][20];
    int i;
    for(i=0; i<5; i++){
        printf("Digite o produto %d: \n", i+1);
        scanf("%s", produtos[i]);
    }
    for(i=0; i<5; i++){

        printf("Produto %d: %s\n", i+1, produtos[i]);
    }
    return 0;
}