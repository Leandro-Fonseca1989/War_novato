#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIO 5
#define TAM_STRING 30

// --- Estrutura que representa um território ---
struct Territorio {
    char nome[TAM_STRING];
    char cor[10];
    int tropas;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal ---
int main() {
    struct Territorio war[MAX_TERRITORIO];

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("   CADASTRO DE TERRITÓRIOS - WAR\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    // Cadastro dos 5 territórios
    for (int i = 0; i < MAX_TERRITORIO; i++) {
        printf(">>> Cadastro do Território %d <<<\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(war[i].nome, TAM_STRING, stdin);
        war[i].nome[strcspn(war[i].nome, "\n")] = '\0';

        printf("Digite a cor das suas tropas: ");
        fgets(war[i].cor, TAM_STRING, stdin);
        war[i].cor[strcspn(war[i].cor, "\n")] = '\0';

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &war[i].tropas);
        limparBufferEntrada();

        printf("\nTerritório %d cadastrado com sucesso!\n\n", i + 1);
    }

    // Exibição dos territórios cadastrados
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(" -=-=  MAPA DO MUNDO - ESTADO ATUAL -=-= \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    for (int i = 0; i < MAX_TERRITORIO; i++) {
        printf("TERRITÓRIO %d\n", i + 1);
        printf("Nome: %s\n", war[i].nome);
        printf("Dominado pelas Tropas: %s\n", war[i].cor);
        printf("Tropas: %d\n", war[i].tropas);
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }

    return 0;
}
