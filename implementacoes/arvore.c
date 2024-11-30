#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cabecalhos/arvore.h"

No* inicializar_arvore() {
    return NULL;
}

void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        *raiz = (No*)malloc(sizeof(No));
        (*raiz)->livro = livro;
        (*raiz)->esquerda = (*raiz)->direita = NULL;
    } else if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->esquerda, livro);
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->direita, livro);
    } else {
        printf("Código já existente!\n");
    }
}

void buscar_por_genero(No* raiz, char genero[]) {
    if (raiz != NULL) {
        buscar_por_genero(raiz->esquerda, genero);
        if (strcmp(raiz->livro.genero, genero) == 0) {
            printf("Código: %d, Título: %s, Autor: %s\n",
                   raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor);
        }
        buscar_por_genero(raiz->direita, genero);
    }
}

No* carregar_livros(char* nome_arquivo, No* raiz) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return raiz;
    } else {
        printf("O arquivo %s foi carregado com sucesso\n", nome_arquivo);
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Livro livro;
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%49[^,],%d",
               &livro.codigo, livro.titulo, livro.autor,
               livro.genero, &livro.ano, livro.editora, &livro.numero_paginas);
        inserir_livro(&raiz, livro);
    }
    fclose(arquivo);
    return raiz;
}

void exibir_arvore(No* raiz) {
    if (raiz != NULL) {
        exibir_arvore(raiz->esquerda);
        printf("Código: %d, Título: %s, Autor: %s\n",
               raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor);
        exibir_arvore(raiz->direita);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}