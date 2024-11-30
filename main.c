#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cabecalhos/aux.h"
#include "cabecalhos/arvore.h"

int main() {
    No* raiz = inicializar_arvore();
    int opcao;

    do {
        printf("Pressione enter para limpar o terminal e ver o menu: \n");
        getchar();
        limparTerminal();
        printMenu();
        scanf("%d", &opcao);
        opcaoSelecionada(opcao);
        switch (opcao) {
            case 1: {
                char arquivo[50];
                printf("Nome do arquivo CSV: ");
                scanf(" %s", arquivo);
                if(strstr(arquivo, ".csv") == NULL) {
                    strcat(arquivo, ".csv");
                }
                raiz = carregar_livros(arquivo, raiz);
                getchar();
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
                getchar();
                break;
            }
            case 3: {
                char genero[50];
                printf("Gênero: ");
                scanf(" %[^\n]", genero);
                buscar_por_genero(raiz, genero);
                getchar();
                break;
            }
            case 4:
                exibir_arvore(raiz);
                getchar();
                break;
            case 5:
                listarCSV();
                getchar();
                break;
            case 6:
                printf("Saindo do programa...\n");
                liberar_arvore(raiz);
                sleep(1.5);
                limparTerminal();
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}