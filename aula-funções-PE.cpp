#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int soma(int a, int b){
    int result;
   // result = a + b;
    return a+b;
}
int media (int a, int b){
    int result;
   // result= result/2;
    return (a+b)/2;

}
int main(){
    int a, b;
    printf("digite o valor de a: ");
    scanf("%d", &a);
    printf("digite o valor de b: ");
    scanf("%d", &b);
    printf("%d \n", soma(a,b));
    printf("%d\n",media(a,b));
    return 0;
}