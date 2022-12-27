#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
int create_matrix(int *filas, int *columnas, int ***matrix, int tipo){
    switch(tipo){
        int temp;
        case 1:
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
            char t[260], p[280];
            scanf("%s", t);
            FILE *des;
            sprintf(p, "./matrizes/%s.txt", t);
            des = fopen(p, "r");
            if(des==NULL){
                printf("No existe esa matriz");
            }else{
                fscanf(des, "%d", filas);
                fscanf(des, "%d", columnas);
                *matrix = (int **)malloc(sizeof(int *)**filas);
                for(int i=0; i<*filas; i++){
                    (*matrix)[i] = (int *)malloc(sizeof(int)**columnas);
                }
                for(int x=0;x<*filas;x++){
                    for(int y=0;y<*columnas;y++){
                        fscanf(des, "%d", &temp);
                        (*matrix)[x][y] = temp;
                    }
                }
            }
        break;

        case 2:
            printf("Cuantas filas son?\n");
            scanf("%d", filas);
            printf("Cuantas columnas son?\n");
            scanf("%d", columnas);
            *matrix = (int **)malloc(sizeof(int *)**filas);
            for(int i=0; i<*filas; i++){
                (*matrix)[i] = (int *)malloc(sizeof(int)**columnas);
            }
            for(int x=0;x<*filas;x++){
                for(int y=0;y<*columnas;y++){
                    temp = (rand() % 11)-5;
                    (*matrix)[x][y] = temp;
                }   
            }
        break;

        case 3:
            printf("Cuantas filas son?\n");
            scanf("%d", filas);
            printf("Cuantas columnas son?\n");
            scanf("%d", columnas);
            *matrix = (int **)malloc(sizeof(int *)**filas);
            for(int i=0; i<*filas; i++){
                (*matrix)[i] = (int *)malloc(sizeof(int)**columnas);
            }
            for(int x=0;x<*filas;x++){
                for(int y=0;y<*columnas;y++){
                    printf("De el valor para la posicion [%d][%d]", x, y);
                    scanf("%d", &temp);
                    (*matrix)[x][y] = temp;

                }   
            }
            char s, n[250];
            printf("La quieres guardar?(y/n)\n");
            scanf("%s", &s);
            if(s =='y'){
                printf("Cual es su nombre?\n");
                scanf("%s", n);
                char nw_file[280];
                sprintf(nw_file, "./matrizes/%s.txt", n);
                FILE *file; 
                file = fopen(nw_file, "w");
                fprintf(file,"%d ", *filas);
                fprintf(file,"%d ", *columnas);
                for(int x=0;x<*columnas;x++){
                    for(int y=0;y<*filas;y++){
                        fprintf(file,"%d ",(*matrix)[x][y]);
                    }
                }
                fclose(file);
            }else{
                printf("Ok");
            }
        break;
    }
}

int main(){
    int filas, columnas, **matrix; 
    create_matrix(&filas, &columnas, &matrix, 3);
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i<filas; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
