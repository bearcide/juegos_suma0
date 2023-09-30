#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
int create_matrix(int *filas,int *columnas,int ***matrix,int tipo)
{
    switch(tipo)
    {
        int temp;
        case 1:
            printf("\n\tCUAL QUIERES CARGAR:\t");
            char t[260],p[280];
            scanf("%s",t);
            FILE *des;
            sprintf(p,"./matrizes/%s.txt",t);
            des=fopen(p,"r");
            if(des==NULL)
                    printf("\n\tNO EXISTE EL ARCHIVO\n\t") ;
            else
                {
                    fscanf(des,"%d",filas);
                    fscanf(des,"%d",columnas);
                    *matrix=(int **)malloc(sizeof(int *)**filas);
                    for(int i=0;i<*filas;i++)
                            (*matrix)[i]=(int *)malloc(sizeof(int)**columnas);

                        for(int x=0;x<*filas;x++)
                        {
                                for(int y=0;y<*columnas;y++)
                                {
                                    fscanf(des,"%d",&temp);
                                    (*matrix)[x][y]=temp;
                                }
                        }
                 }
        break;
        case 2:
            printf("\n\tCUANTAS FILAS SON:\t");
            scanf("%d",filas);
            printf("\n\tCUANTAS COLUMNAS SON:\t");
            scanf("%d",columnas);
            *matrix=(int **)malloc(sizeof(int *)**filas);
            for(int i=0;i<*filas;i++)
                (*matrix)[i]=(int *)malloc(sizeof(int)**columnas);
                srand(time(0));
                for(int x=0;x<*filas;x++)
                {
                    for(int y=0;y<*columnas;y++)
                    {
                        temp=(rand()%11)-5;
                        (*matrix)[x][y]=temp;
                    }
                }
         break;
         case 3:
             printf("\n\tCUANTAS FILAS SON:\t");
             scanf("%d",filas);
             printf("\n\tCUANTAS COLUMNAS SON:\t");
             scanf("%d",columnas);
             if(filas>0&&columnas>0)
             {
                 *matrix=(int **)malloc(sizeof(int *)**filas);
                 for(int i=0;i<*filas;i++){
                    (*matrix)[i]=(int *)malloc(sizeof(int)**columnas);
                 }
                 for(int x=0;x<*filas;x++)
                 {
                     for(int y=0;y<*columnas;y++)
                     {
                         printf("\n\tINTERVALO:-5 a 5\t\n");
                         printf("\n\tDE EL VALOR PARA LA POSICION [%d][%d]:\t",x,y);
                         scanf("%d",&temp);
                         if(temp>=-5&&temp<=5)
                             (*matrix)[x][y]=temp;
                         else
                         {
                             srand(time(NULL));
                             temp=-5+rand()%((5+1)-5);
                         }
                     }
                 }
                 char s,n[250];
                 printf("\n\tQUIERES GUARDARLA(Si/No):\t");
                 scanf("%s",&s);
                 if(s=='S'||s=='s')
                 {
                     printf("\n\tCUAL ES SU NOMBRE:\t");
                     scanf("%s",n);
                     char nw_file[280];
                     sprintf(nw_file,"./matrizes/%s.txt",n);
                     FILE *file;
                     file=fopen(nw_file,"w");
                     fprintf(file,"%d",*filas);
                     fprintf(file,"%d",*columnas);
                     for(int x=0;x<*columnas;x++)
                     {
                         for(int y=0;y<*filas;y++)
                             fprintf(file,"%d ",(*matrix)[x][y]);
                     }
                     fclose(file);
                 }
                 else
                    printf("\n\tOK\t\n");
             }
             else
             {
                 printf("\n\tNO ES POSIBLE GENERAR LA MATRIZ\t\n");
                 exit(0);
             }
         break;
         default:
             printf("\n\tOPCION INVALIDA\t\n");
         break;
    }
}
int escribir_matriz(int filas,int columnas,int ***matriz)
{
    for(int x=0;x<filas;x++)
    {
        printf("|");
        for(int y=0;y<columnas;y++)
            printf("%d, ",(*matriz)[x][y]);
        printf("|\n");
    }
}
int float_escribir_matriz(int filas,int columnas,float ***matriz){
    for(int x=0;x<filas;x++){
        printf("|");
        for(int y=0;y<columnas;y++)
            printf("%.2f, ",(*matriz)[x][y]);
        printf("|\n");
    }
}
int analisis(int filas,int columnas,int ***matriz,int tipo,float ***xerez_analisis,float ***yerez_analisis)
{
    if(tipo==0)
    {
        //Xerez
        *xerez_analisis=(float **)malloc(sizeof(int *)*filas);
        for(int i=0;i<filas;i++)
            (*xerez_analisis)[i]=(float *)malloc(sizeof(int)*9);
        /////////////////// Numeracion y Promedio ////////////////////////
        float prom=0;
        for(int x=0;x<filas;x++)
        {
            for(int y=0;y<columnas;y++)
                prom+=(*matriz)[x][y];
            (*xerez_analisis)[x][0]=x+1;
            (*xerez_analisis)[x][1]=prom/columnas;
             prom=0;
        }
        /////////////////// Numeracion y Promedio //////////////////////

        /////////////////// Mediana ////////////////////////////////////
        int espejo[filas],temp;
        float temp2;
        for(int x=0;x<filas;x++)
        {
            for(int y=0;y<columnas;y++)
                espejo[y]=(*matriz)[x][y];
                for(int y=0;y<columnas-1;y++)
                {
                    for(int val2=0;val2<columnas-y-1;val2++)
                    {
                        if(espejo[val2]>espejo[val2+1])
                        {
                            temp=espejo[val2];
                            espejo[val2]=espejo[val2+1];
                            espejo[val2+1]=temp;
                        }
                    }
                }
                if(columnas%2==0)
                {
                    temp2=(float)(espejo[(columnas/2)-1]+espejo[(columnas/2)])/2;
                    (*xerez_analisis)[x][2]=temp2;
                }
                else
                {
                    temp2=(float)espejo[((columnas-1)/2)];
                    (*xerez_analisis)[x][2]=temp2;
                }
         }
         /////////////////// Mediana ////////////////////////////////////

         /////////////////// +, - y 0 ///////////////////////////////////
         int plus=0,neg=0,zero=0;
         for(int x=0;x<filas;x++)
         {
             for(int y=0;y<columnas;y++)
             {
                 if((*matriz)[x][y]==0)
                     zero+=1;
                 else
                 {
                     if((*matriz)[x][y]>0)
                        plus+=1;
                     else
                        neg+=1;
                 }
             }
             (*xerez_analisis)[x][3]=plus;
             (*xerez_analisis)[x][4]=zero;
             (*xerez_analisis)[x][5]=neg;
             plus=0;
             zero=0;
             neg=0;
          }
        /////////////////// +, - y 0 ///////////////////////////////////

        /////////////////// Calculo Final //////////////////////////////
        for(int x=0;x<filas;x++)
        {
            float calc =  0.5*((*xerez_analisis)[x][1]) + 0.2*(*xerez_analisis)[x][3] -0.2*(*xerez_analisis)[x][5]+0.1*(*xerez_analisis)[x][4];
            (*xerez_analisis)[x][6]=calc;
        }
        /////////////////// Calculo Final //////////////////////////////
    }

    if(tipo==1)
    {
        //Yerez
        *yerez_analisis=(float **)malloc(sizeof(int *)*9);
        for(int i=0;i<9;i++)
            (*yerez_analisis)[i]=(float *)malloc(sizeof(int)*columnas);
        /////////////////// Numeracion y Promedio //////////////////////
        float prom=0;
        for(int y=0;y<columnas;y++)
        {
            for(int x=0;x<filas;x++)
                prom+=(*matriz)[x][y];
            (*yerez_analisis)[0][y]=y+1;
            (*yerez_analisis)[1][y]=prom/filas;
            prom=0;
        }
        /////////////////// Numeracion y Promedio //////////////////////

        /////////////////// +, - y 0 ///////////////////////////////////
        int plus=0,neg=0,zero=0;
        for(int y=0;y<columnas;y++)
        {
            for(int x=0;x<filas;x++)
            {
                if((*matriz)[x][y]==0)
                    zero+=1;
                else
                {
                    if((*matriz)[x][y]>0)
                       plus+=1;
                    else
                       neg+=1;
                }
             }
             (*yerez_analisis)[3][y]=plus;
             (*yerez_analisis)[4][y]=zero;
             (*yerez_analisis)[5][y]=neg;
             plus=0;
             zero=0;
             neg=0;
          }

        /////////////////// +, - y 0 ///////////////////////////////////

        /////////////////// Mediana ////////////////////////////////////
        int espejo[columnas],temp;
        float temp2;
        for(int y=0;y<columnas;y++)
        {
            for(int x=0;x<filas;x++)
                espejo[x]=(*matriz)[x][y];
            for (int x=0;x<filas-1;x++)
            {
                for (int val2=0;val2<filas-x-1;val2++)
                {

                    if (espejo[val2]>espejo[val2+1])
                    {
                        temp=espejo[val2];
                        espejo[val2]=espejo[val2+1];
                        espejo[val2+1]=temp;
                    }
                }
            }
            if(filas%2==0)
            {
                temp2=(float)(espejo[(filas/2)-1]+espejo[(filas/2)])/2;
                (*yerez_analisis)[2][y]=4;
            }
            else
            {
                temp2=(float)espejo[((columnas-1)/2)];
                (*yerez_analisis)[2][y]=temp2;
            }
        }
        /////////////////// Mediana ////////////////////////////////////

        /////////////////// Calculo Final //////////////////////////////
        for(int y=0;y<columnas;y++)
        {
            float calc = 0.5*((*yerez_analisis)[1][y]) - 0.2*(*yerez_analisis)[3][y]+0.2*(*yerez_analisis)[5][y]+0.1*(*yerez_analisis)[4][y];
            (*yerez_analisis)[6][y]=calc;
        }
        /////////////////// Calculo Final //////////////////////////////
    }
}
int dec(int *dec_x,int *dec_y,int filas,int columnas,float ***xerez_analisis,float ***yerez_analisis,int tipo)
{
    int calpr;
    int calpr2;
    for(int p=0;p<3;p++)
        calpr=rand()%2;
    for(int p=0;p<3;p++)
        calpr2=rand()%2;
    if(calpr==0)
    {
        //Calculo
        float espejo[filas];
        int posicion[filas],temp2,temp3;
        for(int x=0;x<filas;x++)
        {
            espejo[x]=(*xerez_analisis)[x][6];
            posicion[x]=x;
        }
        for (int y=0;y<columnas-1;y++)
        {
            for (int val2=0;val2<columnas-y-1;val2++)
            {
                if(espejo[val2]<espejo[val2+1])
                {
                    temp2=espejo[val2];
                    espejo[val2]=espejo[val2+1];
                    espejo[val2+1]=temp2;
                    temp3=posicion[val2];
                    posicion[val2]=posicion[val2+1];
                    posicion[val2+1]=temp2;
                }
             }
        }
        *dec_x=posicion[0];
     }
     if(calpr==1)
     {
         //Promedio
         float espejo[filas];
         int posicion[filas],temp2,temp3;
            for(int x=0;x<filas;x++)
            {
                espejo[x]=(*xerez_analisis)[x][1];
                posicion[x]=x;
            }
            for (int y=0;y<columnas-1;y++)
            {
                for (int val2=0;val2<columnas-y-1;val2++)
                {
                    if (espejo[val2]<espejo[val2+1])
                    {
                        temp2=espejo[val2];
                        espejo[val2]=espejo[val2+1];
                        espejo[val2+1]=temp2;
                        temp3=posicion[val2];
                        posicion[val2]=posicion[val2+1];
                        posicion[val2+1]=temp2;
                    }
                 }
             }
            *dec_x=posicion[0];
        }
        //Calculo
        if(calpr2==0)
        {
            float espejo[columnas];
            int posicion[columnas],temp2,temp3;
            for(int y=0;y<columnas;y++)
            {
                espejo[y]=(*yerez_analisis)[6][y];
                posicion[y]=y;
            }
            for(int x=0;x<filas-1;x++)
            {
                for(int val2=0;val2<filas-x-1;val2++)
                {
                    if (espejo[val2]>espejo[val2+1])
                    {
                        temp2=espejo[val2];
                        espejo[val2]=espejo[val2+1];
                        espejo[val2+1]=temp2;
                        temp3=posicion[val2];
                        posicion[val2]=posicion[val2+1];
                        posicion[val2+1]=temp2;
                    }
                }
             }
             *dec_y=posicion[0];
         }
        if(calpr2==1)
        {
            //Promedio
            float espejo[columnas];
            int posicion[columnas],temp2,temp3;
            for(int y=0;y<columnas;y++)
            {
                espejo[y]=(*yerez_analisis)[1][y];
                posicion[y]=y;
            }
            for (int x=0;x<filas-1;x++)
            {
                for (int val2=0;val2<filas-x-1;val2++)
                {
                    if (espejo[val2]>espejo[val2+1])
                    {
                        temp2=espejo[val2];
                        espejo[val2]=espejo[val2+1];
                        espejo[val2+1]=temp2;
                        temp3=posicion[val2];
                        posicion[val2]=posicion[val2+1];
                        posicion[val2+1]=temp2;
                    }
                 }
             }
             *dec_y = posicion[0];
         }
}
struct puntos {
  int x_val;
  int y_val;
};


int main()
{
    int op,filas,dec_x,dec_y,columnas,**matrix,tipo,r;
    float **xerez_analisis,**yerez_analisis;
    struct puntos pn;
    pn.x_val = 15;
    pn.y_val = 15;
    printf("\n\n\n\t\t\t\t\t\t\tTEORIA DE JUEGOS\t\t\t\t\t\t\t\n\n\n");
    do
    {
        printf("\n\t\t\tPULSE 1 PARA JUGAR\t\t\t\t\t\tPULSE 2 PARA SALIR\t\n");
        printf("\n\t\t\t\t\t\tQUE DESEA HACER:\t");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                system("cls");
                printf("\n\tFORMAS DE GENERAR LA MATRIZ:\n\t1-CARGADA DESDE ARCHIVO\t\t2-CREADA AL AZAR\t\t3-ESCRITA POR TI\t\n");
                printf("\n\tDE QUE MANERA DESEAS QUE SE GENERE LA MATRIZ:\t");
                scanf("%d",&tipo);
                create_matrix(&filas,&columnas,&matrix,tipo);
                analisis(filas,columnas,&matrix,0,&xerez_analisis,&yerez_analisis);
                analisis(filas,columnas,&matrix,1,&xerez_analisis,&yerez_analisis);
                escribir_matriz(filas,columnas,&matrix);
                printf("\n\tVERSUS DISPONIBLES:\n\t1.HUMANO-HUMANO\t\t2.HUMANO-MAQUINA\t\t3.MAQUINA-MAQUINA\t\n");
                printf("\n\tQUE VERSUS DESEA:\t");
                scanf("%d",&tipo);
                if(tipo==1)
                {
                    do
                    {
                        printf("\n\n\n\t\t\t\t\t\t\tSCORES\t\t\t\t\t\t\t\n\n\n");
                        printf("\n\tLOS PUNTOS DE X:\t%d\t\t\t\t\tLOS PUNTOS DE Y:\t%d\n",pn.x_val,pn.y_val);
                        printf("\n\tMATRIZ:\t\n");
                        escribir_matriz(filas,columnas,&matrix);
                        printf("\n\tANALISIS DE COLUMNA Y FILA ESTA ESTRUCTURADA DE FORMA\t\n\tNUMERO DE FILA/COLUMNA\t\n\tPROMEDIO\t\n\tMEDIANA\t\n\tCANTIDAD DE NUMEROS POSITIVOS\t\n\tCANTIDAD DE 0'S\t\n\tCANTIDAD DE NUMERO'S NEGATIVOS\t\n");
                        printf("\n\tANALISIS DE FILAS:\t\n");
                        float_escribir_matriz(filas,8,&xerez_analisis);
                        printf("\n\tANALISIS DE COLUMNAS:\t\n");
                        float_escribir_matriz(8,columnas,&yerez_analisis);
                        printf("\n\tCOLUMNA ESCOJIDA:\t");
                        scanf("%d",&dec_x);
                        printf("\n\tFILA ESCOJIDA:\t");
                        scanf("%d",&dec_y);
                        if(dec_x<=0||dec_y<=0||dec_x>columnas||dec_y>filas)
                        {
                            printf("\n\tLOS VALORES DADOS NO SON CORRECTOS\t\n");
                            exit(0);
                        }
                        printf("\n\tLA OPCION DE X:\t%d\t\t\t\t\tLA OPCION DE Y:\t%d\t\t\t\t\tEL VALOR DE LA MATRIZ:\t%d\t\n",dec_y,dec_x,matrix[dec_x-1][dec_y-1]);
                        pn.x_val+=matrix[dec_x-1][dec_y-1];
                        pn.y_val-=matrix[dec_x-1][dec_y-1];
                     }while(pn.x_val>0&&pn.y_val>0);
                }
                if(tipo==2)
                {
                    printf("\n\tFORMAS DE JUGAR:\n\t1-COLUMNAS\t\t\t\t2-FILAS\t\n");
                    printf("\n\tQUIRES JUGAR COMO:\t");
                    int tipo_jug;
                    scanf("%d",&tipo_jug);
                    if(tipo_jug==1)
                    {
                        do
                        {
                            printf("\tLOS PUNTOS DE X:\t%d\t\t\t\t\tLOS PUNTOS DE Y:\t%d\t\n",pn.x_val,pn.y_val);
                            printf("\n\tMATRIZ:\t\n");
                            escribir_matriz(filas,columnas,&matrix);
                            printf("\n\tANALISIS DE COLUMNA Y FILA ESTA ESTRUCTURADA DE FORMA\t\n\tNUMERO DE FILA/COLUMNA\t\n\tPROMEDIO\t\n\tMEDIANA\t\n\tCANTIDAD DE NUMEROS POSITIVOS\t\n\tCANTIDAD DE 0'S\t\n\tCANTIDAD DE NUMERO'S NEGATIVOS\t\n");
                            printf("\n\tANALISIS DE FILAS:\t\n");
                            float_escribir_matriz(filas,6,&xerez_analisis);
                            printf("\n\tANALISIS DE COLUMNAS:\t\n");
                            float_escribir_matriz(6,columnas,&yerez_analisis);
                            printf("\n\tCOLUMNA ESCOJIDA:\t");
                            scanf("%d",&dec_y);
                            if(dec_y<=0||dec_y>filas)
                            {
                                printf("\n\tLOS VALORES DADOS NO SON CORRECTOS\t\n");
                                exit(0);
                            }
                            dec(&dec_x,&dec_y,filas,columnas,&xerez_analisis,&yerez_analisis,0);
                            printf("\n\tLA OPCION DE x:\t%d\t\t\t\t\tLA OPCION DE Y:\t%d\t\t\t\t\tEL VALOR DE LA MATRIZ:\t%d\t\n",dec_y,dec_x,matrix[dec_x][dec_y-1]);
                            pn.x_val+=matrix[dec_x][dec_y-1];
                            pn.y_val-=matrix[dec_x][dec_y-1];
                            }while(pn.x_val>0&&pn.y_val>0);
                    }
                    if(tipo_jug==2)
                    {
                        do
                        {
                            printf("\n\tLOS PUNTOS DE X:\t%d\t\t\t\t\tLOS PUNTOS DE Y:\t%d\t\n",pn.x_val,pn.y_val);
                            printf("\n\tMATRIZ\t\n");
                            escribir_matriz(filas,columnas,&matrix);
                            printf("\n\tANALISIS DE COLUMNA Y FILA ESTA ESTRUCTURADA DE FORMA\t\n\tNUMERO DE FILA/COLUMNA\t\n\tPROMEDIO\t\n\tMEDIANA\t\n\tCANTIDAD DE NUMEROS POSITIVOS\t\n\tCANTIDAD DE 0'S\t\n\tCANTIDAD DE NUMERO'S NEGATIVOS\t\n");
                            printf("\n\tANALISIS DE FILAS:\t\n");
                            float_escribir_matriz(filas,6,&xerez_analisis);
                            printf("\n\tANALISIS DE COLUMNAS:\t\n");
                            float_escribir_matriz(6,columnas,&yerez_analisis);
                            printf("\n\tFILA ESCOJIDA\t\n");
                            scanf("%d",&dec_x);
                            if(dec_x<=0||dec_x>columnas)
                            {
                                printf("\n\tLOS VALORES DADOS NO SON CORRECTOS\t\n");
                                exit(0);
                            }
                            dec(&dec_x,&dec_y,filas,columnas,&xerez_analisis,&yerez_analisis,1);
                            printf("\n\tLA OPCION DE X:\t%d\t\t\t\t\tLA OPCION DE Y:\t%d\t\t\t\t\tEL VALOR DE LA MATRIZ:\t%d\t\n",dec_y, dec_x,matrix[dec_x-1][dec_y]);
                            pn.x_val+=matrix[dec_x-1][dec_y];
                            pn.y_val-=matrix[dec_x-1][dec_y];
                        }while(pn.x_val>0&&pn.y_val>0);
                    }
                }
                if(tipo==3)
                {
                    do
                    {
                        printf("\n\tLOS PUNTOS DE X:\t%d\t\t\t\t\tLOS PUNTOS DE Y:\t%d\t\n",pn.x_val,pn.y_val);
                        printf("\n\tMATRIZ:\t\n");
                        escribir_matriz(filas,columnas,&matrix);
                        printf("\n\tANALISIS DE FILAS:\t\n");
                        float_escribir_matriz(filas,6,&xerez_analisis);
                        printf("\n\tANALISIS DE COLUMNAS:\t\n");
                        float_escribir_matriz(6,columnas,&yerez_analisis);
                        dec(&dec_x,&dec_y,filas,columnas,&xerez_analisis,&yerez_analisis,1);
                        printf("\n\tLA OPCION DE X:\t%d\t\t\t\t\tLA OPCION DE Y:\t%d\t\t\t\t\tEL VALOR DE LA MATRIZ:\t%d\t\n",dec_y,dec_x,matrix[dec_x][dec_y]);
                        pn.x_val+=matrix[dec_x][dec_y];
                        pn.y_val-=matrix[dec_x][dec_y];
                    }while(pn.x_val>0&&pn.y_val>0);
                }
                if(tipo!=1&&tipo!=2&&tipo!=3)
                    printf("\n\tOPCION INVALIDA\t\n");
                for(int i=0;i<filas;i++)
                    free(matrix[i]);
                free(matrix);
        break;
        case 2:
            printf("\n\n\n\t\t\t\t\tGRACIAS POR SU PARTICIPACION\tVUELVA PRONTO!\t\t\t\t\t\t\t\n\n\n");
        break;
        default:
            printf("\n\t\t\t\t\t\tOPCION INVALIDA\t\n");
        break;
        printf("\n\t\t\t\t\t\tQUE DESEA HACER:\t");
        scanf("%d",&r);
    }
  }while(r==1);
}