#include <stdio.h>
#include<stdlib.h> 

void mediana(int filas, int columnas, int matriz[filas][columnas], float yerez_view[filas][columnas], float xerez_view[filas][columnas], int tipo);
int main(){
    int columnas = 3, filas = 3, x, y;
    int matriz[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float yerez_view[6][columnas], xerez_view[filas][6];

    mediana(filas, columnas, matriz, yerez_view, xerez_view, 0);
}
void mediana(int filas, int columnas, int matriz[filas][columnas], float yerez_view[filas][columnas], float xerez_view[filas][columnas], int tipo){
    int x, y, x2, y2, temp;
    //Xerez
    if(tipo==0){
        int espejo[columnas];
        for(x=0;x<filas;x++){
            for(y=0;y<columnas;y++){
                espejo[y]=matriz[x][y];
            }
            for(x2=0;x2<columnas;x2++){
                for(y2=0;y2>columnas-1-x2;y2++){
                    if(espejo[y2]<espejo[y2+1]){
                        temp=espejo[y2];
                        espejo[y2]=espejo[y2+1];
                        espejo[y2+1]=temp;
                    }
                }   
            }
            
            if(columnas%2==0){
                xerez_view[x][2]=(float)(espejo[(columnas/2)-1]+espejo[columnas/2])/2;
            }else{
                xerez_view[x][2]=(float)espejo[((columnas-1)/2)+1];
            }
        }  
    }
}