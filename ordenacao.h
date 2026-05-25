#ifndef ORDENACO_H
#define ORDENACO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item; // define o tipo item como int
#define exch(a, b) { item t = a; a = b; b = t; } // troca os valores de a e b

int crescente(int a, int b);
int decrescente(int a, int b);
int *alocaEspaco(int n);
void bubblesort(int v[], int tam, int (*compara)(int, int));
void selectionsort(int v[], int tam, int (*compara)(int, int));
void insertionsort(int v[], int tam, int (*compara)(int, int));
int lomutopartition(int v[], int begin, int end);
void quicksort(int v[], int begin, int end);
void buscaseq(int v[], int tam, int found);
bool ordenado(int v[], int tam);
void buscabin(int v[], int tam, int found);
void mostrarDados(int v[], int tam);
void menu();
void menu1();
void menu2();
void menu3();
int leropcao();

#endif
