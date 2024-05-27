#include "library.h"

void bucle (FILE *f, int *i_count, int *f_count, int *d_count, int *z_count){
    int count=0; //acá vamos a almacenar la cantidad de tipo int que continua despues de la letra
    char dataType;  //variable para verificar si la letra encontrada es una 'i', 'f', 'd' o 'z'
     while(fread(&dataType, sizeof(char), 1, f)){  //No solo hallamos el primer byte que nos indica el tipo de dato que 
                                                     //continua sino que bucleamos hasta alcanzar el final del archivo
        count=0;
        fread(&count, sizeof(int), 1, f); //como fread nos mueve el puntero del archivo, aprovechamos a saber la cantidad de elementos que hay de ese mismo tipo
        if(dataType=='i'){
            *i_count+=count;
            fseek(f, sizeof(int)*count, SEEK_CUR);
        }
        if(dataType=='f'){
            *f_count += count;
            fseek(f, sizeof(float)*count, SEEK_CUR);
        }
        if(dataType=='d'){
            *d_count += count; 
            fseek(f, sizeof(double)*count, SEEK_CUR);
        }
        if(dataType=='z'){
            *z_count += count; 
            fseek(f, sizeof(struct cmplx)*count, SEEK_CUR);
        }
    }
    rewind(f);
}

void show_and_write (FILE *f1, int *i_array, int i_count, float *f_array, int f_count, double *d_array, int d_count, struct cmplx *z_array, int z_count){
    fprintf(f1, "\n Cantidad de tipo enteros %d", i_count);
    fprintf(f1, "\n Int:");
    printf("\n Int:");
    for (int i = 0; i < i_count; i++) {
        printf(" %d\t", i_array[i]);
        fprintf(f1,"%d\t", i_array[i]);
    }
    fprintf(f1, "\n\n Cantidad de tipo float: %d", f_count);
    fprintf(f1, "\n Float: ");
    printf("\n");
    printf("\n Float: ");
    for (int i = 0; i < f_count; i++) {
        printf(" %f\t", f_array[i]);
        fprintf(f1,"%f\t", f_array[i]);
    }
    fprintf(f1, "\n\n Cantidad de tipo Double: %d", d_count);
    fprintf(f1, "\n Double:");
    printf("\n");
    printf("\n Double:");
    for (int i = 0; i < d_count; i++) {
        printf(" %.3lf\t", d_array[i]);
        fprintf(f1, "%.3lf\t", d_array[i]);
    }
    fprintf(f1, "\n\n Cantidad de tipo Complejo: %d", z_count);
    fprintf(f1, "\n Complex:");
    printf("\n");
    printf("\n Complex: ");
    for (int i = 0; i < z_count; i++) {
        if(z_array[i].im>0){
             printf(" %.3f +%.3fj \t", z_array[i].re, z_array[i].im);
             fprintf(f1, " %.3f +%.3fj\t", z_array[i].re, z_array[i].im);

        } else{
             printf(" %.3f  %.3fj \t", z_array[i].re, z_array[i].im);
             fprintf(f1, " %.3f  %.3fj\t", z_array[i].re, z_array[i].im);
        }   
    }
}

void llenar (FILE *f, int *i_array, float *f_array, double *d_array, struct cmplx *z_array){
    int i_count=0, f_count=0, d_count=0, z_count=0 ;
    char dataType;
    int count=0; 
    while(fread(&dataType, sizeof(char), 1, f)!=0){
        fread(&count, sizeof(int), 1, f);
        if(dataType=='i'){
            fread(&i_array[i_count], sizeof(int), count, f);
            i_count += count;
        }
        if (dataType=='f')
        {
            fread(&f_array[f_count], sizeof(float), count, f);
            f_count += count;
        }
        if (dataType=='d')
        {
            fread(&d_array[d_count], sizeof(double), count, f);
            d_count+= count;
        }
        if (dataType=='z')
        {
            fread(&z_array[z_count], sizeof(struct cmplx), count, f);
            z_count+=count;
        }       
    }
    rewind(f);
}