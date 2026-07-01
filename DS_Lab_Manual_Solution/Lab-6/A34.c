#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main(){
    int *i;
    char *c;
    float *f;
    i=(int *)malloc(sizeof(int));
    c=(char *)malloc(sizeof(char));
    f=(float *)malloc(sizeof(float));
    free(i);
    free(c);
    free(f);
}