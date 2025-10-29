#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_STRING 30

// --- Estrutura de Território ---
struct Territorio {
    char nome[TAM_STRING];
    char cor[10];
    int tropas;
};

// --- Limpeza de Buffer ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função para exibir todos os territórios ---
void exibirMapa(struct Territorio *mapa, int n) {
    printf("\n\n===== ESTADO ATUAL DO MAPA =====\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s | Exército: %s | Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("================================\n\n");
}

// --- Função de Ataque ---
void atacar(struct Territorio *atacante, struct Territorio *defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n>>> ATAQUE INICIADO <<<\n");
    printf("%s (%s) Joga o dado e tira: %d\n", atacante->nome, atacante->cor, dadoAtacante);
    printf("%s (%s) Joga o dado e tira: %d\n", defensor->nome, defensor->cor, dadoDefensor);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    if (dadoAtacante > dadoDefensor) {
        printf("\nResultado: O atacante venceu a batalha!\n");
        defensor->tropas = 0;
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;
        printf("%s foi conquistado pelo exército %s!\n", defensor->nome, atacante->cor);
    } else {
        printf("\nResultado: O defensor resistiu! O atacante perdeu 1 tropa.\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }
}

// --- Liberação de Memória ---
void liberarMemoria(struct Territorio *mapa) {
    free(mapa);
}

// --- Função Principal ---
int main() {
    srand(time(NULL));

    int qtd;
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n\n\n");
    printf("-=-=-= 🌍🌎🌏 BEM VINDO AO WAR!!! 🌍🌎🌏 -=-=-=-==\n\n" );
    printf("Digite quantos territórios irão participar da guerra: ");
    scanf("%d", &qtd);
    limparBufferEntrada();

    struct Territorio *mapa = (struct Territorio *) calloc(qtd, sizeof(struct Territorio));

    // Cadastro dos territórios
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);
        printf("Nome: ");
        fgets(mapa[i].nome, TAM_STRING, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(mapa[i].cor, 10, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBufferEntrada();
    }

    int opcao;
    do {
        exibirMapa(mapa, qtd);

        printf("🤯 Deseja realizar um ataque? (1 = Sim 💀 / 0 = Encerrar 🥱): ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        if (opcao == 1) {
            int a, d;
            printf(" 😎 Escolha o número de quem vai atacar: ");
            scanf("%d", &a);
            printf(" 😮 Escolha o número de quem vai defender: ");
            scanf("%d", &d);
            limparBufferEntrada();

            a--; d--;

            if (a < 0 || a >= qtd || d < 0 || d >= qtd) {
                printf("😒 Território inválido! 😒\n");
                continue;
            }
            if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
                printf("🚩 Você não pode atacar este território. Ele já é seu!!! 🚩\n");
                continue;
            }
            if (mapa[a].tropas <= 0) {
                printf("😖 O território atacante não possui tropas suficientes!\n");
                continue;
            }

            atacar(&mapa[a], &mapa[d]);
        }

    } while (opcao != 0);

    liberarMemoria(mapa);
    printf("\n🎮 Fim do jogo! Memória liberada. 🎮\n");
    printf("\n -=-=-=-= 🏳️🏳️🏳️    NOS VEMOS EM BREVE!! 🏳️🏳️🏳️   -=-=-=-=\n\n\n\n");

    return 0;
}
