#include <stdio.h>
#include<stdlib.h> 
int mediana(int filas, int columnas, int matriz[filas][columnas], int tipo, float ***xerez_analisis, float ***yerez_analisis){
    if(tipo==0){
        //Xerez
        *xerez_analisis = (float **)malloc(sizeof(int *)*filas);
        for(int i=0; i<filas; i++){
            (*xerez_analisis)[i] = (float *)malloc(sizeof(int)*8);
        }
        /////////////////// Mediana ////////////////////////////////////
        int espejo[filas], temp;
        float temp2;
        for(int x=0;x<filas;x++){
            for(int y=0;y<columnas;y++){
                espejo[y] = matriz[x][y];
            }
        
            for (int y = 0 ; y < columnas - 1; y++){
                for (int val2 = 0 ; val2 < columnas - y - 1; val2++){
                    if (espejo[val2] > espejo[val2+1]){
                        temp = espejo[val2];
                        espejo[val2] = espejo[val2+1];
                        espejo[val2+1] = temp;
                        }
                }
            }
            if(columnas%2==0){
                temp2 = (float)(espejo[(columnas/2)-1] + espejo[(columnas/2)])/2;
                (*xerez_analisis)[x][4] = temp2;
                //printf("%f, \n", (*xerez_analisis)[x][4]);
                //printf("%d, \n", espejo[(columnas/2)-1]);
                //printf("%d, \n", espejo[(columnas/2)]);

            }
            if(columnas%2!=0){
                temp2 = (float)espejo[((columnas-1)/2)];
                (*xerez_analisis)[x][4] = temp2;
                //printf("%f, \n", (*xerez_analisis)[x][4]);
                //printf("%d, \n", espejo[columnas-1]);

            }
        }
        /////////////////// Mediana ////////////////////////////////////
    }
    if(tipo==1){
        //Yerez
        *yerez_analisis = (float **)malloc(sizeof(int *)*8);
        for(int i=0; i<columnas; i++){
            (*yerez_analisis)[i] = (float *)malloc(sizeof(int)*columnas);
        }
        /////////////////// Mediana ////////////////////////////////////
        int espejo[columnas], temp;
        float temp2;
        for(int y=0;y<columnas;y++){
            for(int x=0;x<filas;x++){
                espejo[x] = matriz[x][y];
            }
        
            for (int x = 0 ; x < filas - 1; x++){
                for (int val2 = 0 ; val2 < filas - x - 1; val2++){
                    if (espejo[val2] > espejo[val2+1]){
                        temp = espejo[val2];
                        espejo[val2] = espejo[val2+1];
                        espejo[val2+1] = temp;
                        }
                }
            }
            if(filas%2==0){
                temp2 = (float)(espejo[(filas/2)-1] + espejo[(filas/2)])/2;
                (*yerez_analisis)[4][y] = 4;
                //printf("%f, ", (*yerez_analisis)[4][y]);
            }
            if(filas%2!=0){
                temp2 = (float)espejo[((columnas-1)/2)];
                (*yerez_analisis)[4][y] = temp2;
                //printf("%f,, ", (*yerez_analisis)[4][y]);

            }
        }
        /////////////////// Mediana ////////////////////////////////////
    }
}

int main(){
    int columnas = 6, filas = 5, x, y, val2;
    float **xerez_analisis, **yerez_analisis;
    int matriz[][6] = {{1, 2, 6, 7, 7, 9}, 
                       {3, 3, 8, 8, 9, 13}, 
                       {4, 4, 9, 10, 11, 12},
                       {5, 5, 10, 12, 12, 17},
                       {6, 7, 11, 14, 13, 25}
    };
    mediana(filas, columnas, matriz, 1, &xerez_analisis, &yerez_analisis);
    for(int i; i<6;i++){
        printf("%f, ", yerez_analisis[4][i]);  
        for(int u; u<8; u++){
              
        }
    }
    
}
