#include <stdio.h> 
int pot(int base, int acima){
    int resultado=1;
    for (int i=0; i<acima; i++){
        resultado = resultado*base;
    }
    return resultado;
}
int main(){
    printf("%d", pot(2,3));
    return 0;
}