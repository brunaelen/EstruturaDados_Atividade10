#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PECA 50

// Defini��o da estrutura da pilha
typedef struct {
    char pecas[MAX_PECA][50];
    int topo;
} Pilha;

// Fun��o para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Fun��o para verificar se a pilha est� vazia
int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

// Fun��o para verificar se a pilha est� cheia
int estaCheia(Pilha *pilha) {
    return (pilha->topo == MAX_PECA - 1);
}

// Fun��o para empilhar uma pe�a
void empilhar(Pilha *pilha, char peca[]) {
    if (estaCheia(pilha)) {
        printf("A pilha est� cheia. N�o � poss�vel empilhar mais pe�as.\n");
    } else {
        pilha->topo++;
        strcpy(pilha->pecas[pilha->topo], peca);
    }
}

// Fun��o para desempilhar uma pe�a
void desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha est� vazia. N�o h� pe�as para desempilhar.\n");
    } else {
        printf("Pe�a desempilhada: %s\n", pilha->pecas[pilha->topo]);
        pilha->topo--;
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    char objeto[50];
    int quantidade;

    printf("Digite o nome do objeto: ");
    scanf("%s", objeto);

    printf("Digite a quantidade de pe�as a serem montadas: ");
    scanf("%d", &quantidade);

    for (int i = 1; i <= quantidade; i++) {
        char peca[50];
        printf("Digite o nome da pe�a %d: ", i);
        scanf("%s", peca);
        empilhar(&pilha, peca);
    }

    printf("\nObjeto %s montado com sucesso!\n\n", objeto);

    while (!estaVazia(&pilha)) {
        desempilhar(&pilha);
    }

    printf("\nObjeto %s desmontado com sucesso!\n", objeto);

    return 0;
}

