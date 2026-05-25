#include "ordenacao.h"

int crescente(int a, int b) {// retorna o numero em ordem crescente
    return a > b;
}

int decrescente(int a, int b) {// retorna o numero em ordem decrescente
    return a < b;
}

int *alocaEspaco(int n) { // aloca espaco para um vetor de dimensao n
    int *v = (int *) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    return v;
}

void bubblesort(int v[], int tam, int (*compara)(int, int)) { // bubble sort otimizado

    int i, j, trocou;
    i = 0;

    do {
        trocou = 0;
        for(j = 0; j < tam - 1 - i; j++) {
            if ((*compara)(v[j], v[j + 1])) { 
                exch(v[j], v[j + 1]);
                trocou = 1;
            }
        }
        i++;
    } while (trocou == 1);
}

void selectionsort(int v[], int tam, int (*compara)(int, int)) { // selection sort

    int i, j, min;

    for(i = 0; i < tam; i++) {
        min = i;
        for(j = i + 1; j < tam; j++) {
            if ((*compara)(v[min], v[j])) {
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}   

void insertionsort(int v[], int tam, int (*compara)(int, int)) { // insertion sort

    int i, j, chave;

    for(i = 1; i < tam; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && (*compara)(v[j], chave)) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int lomutopartition(int v[], int begin, int end) { // particao de lomuto
    int pos,pivot,i;

    pivot = v[begin];
    pos = begin;

    for(i = begin + 1; i <= end; i++)
    if(v[i] < pivot){
        pos++;
        if (i != pos) exch(v[i], v[pos]);
    }
    exch (v[begin],v[pos]);
        return pos;
}

void quicksort(int v[], int begin, int end) {
    int pivot;
    
    if(begin <= end) {
        pivot = lomutopartition(v, begin, end);
        quicksort(v, begin, pivot - 1);
        quicksort(v, pivot + 1, end);
    }
}

void buscaseq(int v[], int tam, int search) {
    int found = 0;
    int i;

    for(i = 0; i < tam; i++) {
        if(v[i] == search) {
            printf("Valor procurado: %d\n", v[i]);
            found = 1;
        }
    } 

    if(found == 0) {
        printf("O valor pesquisado nao foi encontrado\n");
    }
}

bool ordenado(int v[], int tam) {
    int i;

    for (i = 0; i < tam - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;  
        }
    }
    return true;  
}

void buscabin(int v[], int tam, int search) {
    int inicio = 0;
    int fim = tam - 1;
    int found = 0;
    int i, meio;

    for(i = 0; i < tam; i++) {
        meio = (inicio +fim) / 2;
        
        if(v[meio] == search) {
            printf("Valor %d procurado na posicao %d\n", v[meio], meio);
            found = 1;
        }else if(v[meio] < search) {
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }

    if(found == 0) {
        printf("O valor pesquisado nao foi encontrado\n");
    }

}


void mostrarDados(int v[], int tam) { //mostra os dados do vetor
    int i;

    for(i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

void menu() { // menu de opcoes
    printf("\n------ MENU ------\n");
    printf("1. Ordenacao Dados\n");
    printf("2. Pesquisa Dados\n");
    printf("3. Sair\n");
}

void menu1() { // menu de opcoes
    printf("\nEscolha o algoritmo de ordenacao:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Quick Sort(Lomuto Partition)\n");
    printf("6. Merge Sort\n");
    printf("7. Heap Sort\n");
    printf("8. Sair\n");
}

void menu2() { // menu de opcoes
    printf("\nMetodo de ordenacao: \n");
    printf("1. Decrescente\n");
    printf("2. Crescente\n");
}

void menu3() {
    printf("\nTipos de pesquisa:\n");
    printf("1. Sequencial(linear)\n");
    printf("2. Binaria\n");
    printf("3. k e simo menor valor\n");
    printf("4. Sair\n");
}

int leropcao() { // le a opcao do usuario
    int op;
    printf("Escolha uma opcao: ");
    scanf("%d", &op);
    putchar('\n');
    return op;
}

