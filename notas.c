#include <stdio.h>
 
int main(){
    int notas[3],i;
    printf("Digite as notas: \n");
    scanf("%d %d %d", &notas[0], &notas[1], &notas[2]);
    for(i=0; i<3; i++){
        printf("nota %d: %d\n", i+1, notas[i]);
    }
    printf("Media: %d\n", (notas[0]+notas[1]+notas[2])/3);
    return 0;
}