#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <chrono>
#include <iostream>
#include "sortalg.h"
void print(long t[],long n,FILE *outpt)
{
    for(long i=1;i<=n;i++)
    {
        printf("%ld ",t[i]);
        fprintf(outpt,"%ld ",t[i]);
    }
    printf("\n");
}
int main()
{
    FILE *inpt=fopen("Intrare01.txt","r"),*outpt=fopen("Iesire01.txt","w");
    if(inpt==NULL || outpt==NULL)
    {
        printf("Can't reach file");
        return 1;
    }
    long t[1000];
    long i,n;
    fscanf(inpt,"%ld",&n);
    for(i=1;i<=n;i++)
        fscanf(inpt,"%ld ",&t[i]);
    printf("\n");
    auto start=std::chrono::high_resolution_clock::now();
    selection_sort(t,n); //Aici se longroduce prototipul functiei de sortare dorita
    print(t,n,outpt);
    auto end=std::chrono::high_resolution_clock::now();
    auto durata=std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    double l=(double)durata.count()/1000000;
    std::cout<<"Timpul de rulare al algoritmului este de "<<l<<" secunde";
    fclose(inpt);
    fclose(outpt);
    return 0;
}