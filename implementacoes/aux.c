#include <stdlib.h>
#include <stdio.h>
#include "../cabecalhos/aux.h"

#ifdef __unix__         
    #include <unistd.h>

#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h>

#endif

void printMenu() {
        printf ("\n******************************************");
        printf ("\n**     Escolha abaixo uma das opções    **\n");
        printf ("******************************************\n\n");
        printf("\n1. Carregar Livros do CSV\n");
        printf("2. Inserir Livro\n");
        printf("3. Buscar por Gênero\n");
        printf("4. Exibir Árvore\n");
        printf("5. Listar arquivos CSV\n");
        printf("6. Sair\n");
   
}

void limparTerminal() {
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
}

void opcaoSelecionada(int opcao) {
    printf ("\n******************************************");
    printf ("\n**          OPCAO SELECIONADA: %d        **\n", opcao);
    printf ("******************************************\n\n");   
}

void listarCSV() {
    printf("Arquivos CSV no diretorio atual: \n");
    system("ls *.csv");
    printf("\n");
}