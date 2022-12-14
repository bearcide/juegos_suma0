#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

struct matriz_file{
    char nombre;
    int fila;
    int columna;
    int A;
};

void print_matriz(int fila,int columna,int A[fila][columna]);
void scan_matriz(int fila,int columna,int A[fila][columna], int tipo);
int fila = 0, columna = 0;

int main()
{
    int a[fila][columna], tipo=0;
    
    printf("Que tipo de matriz quiere? 1. Guardadas 2. Al azar 3. Escrita\n");
    scanf("%d", &tipo);
    scan_matriz(fila, columna, a, tipo);
    print_matriz(fila, columna, a);
    return 0;
}

void print_matriz(int fila,int columna, int A[fila][columna])
{
    printf("\n[");
    printf("%d ", fila);
    printf("%d ", columna);
    int x,y;
    for (x=0;x<fila;x++)
        {  
            printf("["); 
            printf("pppppp, ");

            for (y=0;y<columna;y++)
            {   
                printf("hvfsckdm, ");
            }   
            printf("] \n");
        }   
        printf("]\n");
}

void scan_matriz(int fila,int columna,int A[fila][columna], int tipo){
    int x, y;
        switch(tipo){
                case 1:
                    //Da los contenidos de la carpeta matrizes y le pregunta al usuario cual quiere cargar
                    //Primero carga las filas, despues las columnas y al final la matriz
                    struct dirent *de;
                    DIR *dr = opendir("./matrizes");
                    printf("Las matrizes guardadas son: \n");
                    if (dr == NULL) {
                        printf("Could not open current directory" );
                    }
                    while ((de = readdir(dr)) != NULL){
                        printf("\t%s\n", de->d_name);
                    }
                    closedir(dr);
                    printf("¿Cual quieres cargar?");
                    char t[260], p[250];
                    scanf("%s", t);
                    FILE *des;
                    sprintf(p, "./matrizes/%s.txt", t);
                    des = fopen(p, "r");
                    if(des==NULL){
                        printf("No existe esa matriz");
                    }else{
                        fscanf(des, "%d", &fila);
                        fscanf(des, "%d", &columna);
                        for(x=0;x<fila;x++){
                            for(y=0;y<columna;y++){
                                fscanf(des, "%d", &A[x][y]);
                            }
                        }
                    }
                break;

                case 2:
                    //La matriz es creada con numeros al azar de (-3 a 3)
                    printf("Cuantas filas son?\n");
                    scanf("%d", &fila);
                    printf("Cuantas columnas son?\n");
                    scanf("%d", &columna);
                    srand(time(NULL));
                    for(x=0;x<fila;x++){
                        for(y=0;y<columna;y++){
                            A[x][y] = (rand() % 7)-3;
                        }   
                    }
                break;

                case 3:
                    //El usuario da los valores de la matriz
                    printf("Cuantas filas son?\n");
                    scanf("%d", &fila);
                    printf("Cuantas columnas son?\n");
                    scanf("%d", &columna);
                    char s, n[250];
                    for(x=0;x<fila;x++){
                        for(y=0;y<columna;y++){
                            printf("De el valor para la posicion [%d][%d]", x, y);
                            scanf("%d", &A[x][y]);
                        }   
                    }
                    printf("La quieres guardar?(y/n)\n");
                    scanf("%s", &s);
                    if(s =='y'){
                        //Crea un . con el nombre por el usuario. El formato esta echo para que le primer numero sea
                        // la fila, el segundo la columna y los que restan seam el arreglo
                        printf("Cual es su nombre?\n");
                        scanf("%s", n);
                        char nw_file[260];
                        sprintf(nw_file, "./matrizes/%s.txt", n);
                        FILE *file; 
                        file = fopen(nw_file, "w");
                        fprintf(file,"%d ",fila);
                        printf("%d ", fila);
                        fprintf(file,"%d ", columna);
                        printf("%d ", columna);
                        for(x=0;x<columna;x++){
                            for(y=0;y<fila;y++){
                                fprintf(file,"%d ",A[x][y]);
                            }
                        }
                        fclose(file);
                    }else{
                        printf("Ok");
                    }
                break;

                default:
                    printf("El numero que usted marco no es posible");
                break;
        }   
}