#pragma once
#include <stdlib.h>
#include <stdio.h>

struct cmplx
{
    float re;
    float im;
};

void bucle (FILE *f, int *i_count, int *f_count, int *d_count, int *z_count);
void show_and_write (FILE *f1, int *i_array, int i_count, float *f_array, int f_count, double *d_array, int d_count, struct cmplx *z_array, int z_count);
void llenar (FILE *f, int *i_array, float *f_array, double *d_array, struct cmplx *z_array);