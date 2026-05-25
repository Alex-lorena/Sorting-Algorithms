#include "ordenacao.h"

int main(int argc, char *argv[]) {

    int i = 0, n = atoi (argv[1]), sw = atoi (argv[2]), escolha;

    int *v = alocaEspaco(n);
    if (v == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        exit(1);
    }

    if(sw) {
        for(i = 0; i < n; i++) {
            v[i] = 1000 * (1.0 * rand() / RAND_MAX);
        }
    }else {
        while (i < n && scanf("%d", &v[i]) == 1) i++;
        
    }

    do{
        menu();
        escolha = leropcao();
        int op, ch;

        if(escolha == 1) {
            do {
                menu1();
                op = leropcao();
                
                switch(op) {
                    case 1:
                        menu2();
                        ch = leropcao();

                        if(ch == 1) {
                            puts("Decresente: ");
                            bubblesort(v, n, decrescente);
                            mostrarDados(v, n);
                        } else if(ch == 2) {
                            puts("Crescente: ");
                            bubblesort(v, n, crescente);
                            mostrarDados(v, n);
                        }
                        
                        break;
    
                    case 2:
                        menu2();
                        ch = leropcao();

                        if(ch == 1) {
                            puts("Decresente: ");
                            selectionsort(v, n, decrescente);
                            mostrarDados(v, n);
                        } else if(ch == 2) {
                            puts("Crescente: ");
                            selectionsort(v, n, crescente);
                            mostrarDados(v, n);
                        }
                        
                        break;
    
                    case 3:
                        menu2();
                        ch = leropcao();

                        if(ch == 1) {
                            puts("Decresente: ");
                            insertionsort(v, n, decrescente);
                            mostrarDados(v, n);
                        } else if(ch == 2) {
                            puts("Crescente: ");
                            insertionsort(v, n, crescente);
                            mostrarDados(v, n);
                        }
                        
                        break;
    
                    case 4:
                        quicksort(v, 0, n - 1);
                        mostrarDados(v, n);

                        break;
                }
            }while(op != 8);
        }else if(escolha == 2) {
            do {
                menu3();
                op = leropcao();
                int search;
                
                switch(op) {
                    case 1:
                        printf("Introduz um valor a ser procurado: ");
                        scanf("%d", &search);
                        putchar('\n');

                        buscaseq(v, n, search);

                        break;

                    case 2:
                        printf("Introduz um valor a ser procurado: ");
                        scanf("%d", &search);
                        putchar('\n');

                        if (!ordenado(v, n)) {
                            puts("Vetor não está ordenado.\n");
                            puts("Ordene o vetor antes de faze a pesqusa binaria...");
                            op = 4;
                        } else {
                            printf("Vetor já está ordenado.\n");
                            buscabin(v, n, search);
                        }

                        break;

                    case 3:
                        
                        break;
                        
                }
            }while(op != 4);
        }else
            printf("Opcao invalida");

    } while(escolha != 3);

    free(v);

    return 0;
}