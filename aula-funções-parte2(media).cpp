#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float media(float n1, float n2, float n3){
    return (n1+n2+n3)/3;
}
int main(){
    float n1,n2,n3;
    printf("digite a nota 1: \n");
    scanf("%f",&n1);

    printf("digite a nota 2: \n");
    scanf("%f",&n2);

    printf("digite a nota 3: \n ");  
    scanf("%f",&n3);

    printf("a media é: %f\n",media(n1,n2,n3));
    return 0;
 }