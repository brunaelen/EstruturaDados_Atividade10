#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PECA 50

// Definição da estrutura da pilha
typedef struct {
    char pecas[MAX_PECA][50];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return (pilha->topo == -1);
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *pilha) {
    return (pilha->topo == MAX_PECA - 1);
}

// Função para empilhar uma peça
void empilhar(Pilha *pilha, char peca[]) {
    if (estaCheia(pilha)) {
        printf("A pilha está cheia. Não é possível empilhar mais peças.\n");
    } else {
        pilha->topo++;
        strcpy(pilha->pecas[pilha->topo], peca);
    }
}

// Função para desempilhar uma peça
void desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("A pilha está vazia. Não há peças para desempilhar.\n");
    } else {
        printf("Peça desempilhada: %s\n", pilha->pecas[pilha->topo]);
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

    printf("Digite a quantidade de peças a serem montadas: ");
    scanf("%d", &quantidade);

    for (int i = 1; i <= quantidade; i++) {
        char peca[50];
        printf("Digite o nome da peça %d: ", i);
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

