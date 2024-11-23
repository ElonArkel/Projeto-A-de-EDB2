#include <stdio.h>
#include <stdlib.h>
#include "headers/aux.h"
#include "headers/arvore.h"

int main() {
    No* raiz = inicializar_arvore();
    int opcao;

    do {
        printMenu();
        scanf("%d", &opcao);
        limparTerminal();
        opcaoSelecionada(opcao);
        switch (opcao) {
            case 1: {
                char arquivo[50];
                printf("Nome do arquivo CSV: ");
                scanf("%s", arquivo);
                raiz = carregar_livros(arquivo, raiz);
                break;
            }
            case 2: {
                Livro livro;
                printf("Código: ");
                scanf("%d", &livro.codigo);
                printf("Título: ");
                scanf(" %[^\n]", livro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]", livro.autor);
                printf("Gênero: ");
                scanf(" %[^\n]", livro.genero);
                printf("Ano: ");
                scanf("%d", &livro.ano);
                printf("Editora: ");
                scanf(" %[^\n]", livro.editora);
                printf("Número de Páginas: ");
                scanf("%d", &livro.numero_paginas);
                inserir_livro(&raiz, livro);
                break;
            }
            case 3: {
                char genero[50];
                printf("Gênero: ");
                scanf(" %[^\n]", genero);
                buscar_por_genero(raiz, genero);
                break;
            }
            case 4:
                exibir_arvore(raiz);
                break;
            case 5:
                liberar_arvore(raiz);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}