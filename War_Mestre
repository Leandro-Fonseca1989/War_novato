#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_STRING 30
#define TOTAL_MISSOES 5
#define TOTAL_JOGADORES 2

// --- Estrutura de Território ---
typedef struct {
    char nome[TAM_STRING];
    char cor[10];
    int tropas;
} Territorio;

// --- Estrutura de Jogador ---
typedef struct {
    char nome[30];
    char cor[10];
    char *missao; // armazenada dinamicamente
} Jogador;

// --- Protótipos ---
void limparBufferEntrada();
void exibirMapa(Territorio *mapa, int n);
void atacar(Territorio *atacante, Territorio *defensor);
void atribuirMissao(char *destino, char *missoes[], int totalMissoes);
int verificarMissao(char *missao, Territorio *mapa, int tamanho, char *corJogador);
void exibirMissao(const char *missao);
void liberarMemoria(Territorio *mapa, Jogador *jogadores, int qtdJogadores);

// --- Função para limpar buffer ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Exibição do Mapa ---
void exibirMapa(Territorio *mapa, int n) {
    printf("\n\n===== ESTADO ATUAL DO MAPA =====\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s | Exército: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("================================\n\n");
}

// --- Função de Ataque ---
void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf(">>> ATAQUE INICIADO <<<\n");
    printf("%s (%s) joga o dado e tira: %d\n", atacante->nome, atacante->cor, dadoAtacante);
    printf("%s (%s) joga o dado e tira: %d\n", defensor->nome, defensor->cor, dadoDefensor);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");

    if (dadoAtacante > dadoDefensor) {
        printf("Resultado: O atacante venceu a batalha!\n");
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;
        strcpy(defensor->cor, atacante->cor);
        printf("%s foi conquistado pelo exército %s!\n", defensor->nome, atacante->cor);
    } else {
        printf("Resultado: O defensor resistiu! O atacante perdeu 1 tropa.\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0)
            atacante->tropas = 0;
    }
}

// --- Função que sorteia e atribui missão ---
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// --- Função para exibir missão (somente no início do jogo) ---
void exibirMissao(const char *missao) {
    printf("\n🎯 Sua missão é: %s\n\n", missao);
}

// --- Função para verificar se a missão foi cumprida ---
int verificarMissao(char *missao, Territorio *mapa, int tamanho, char *corJogador) {
    // Lógica simplificada — apenas como exemplo:
    // “Conquistar 3 territórios seguidos” → verifica se o jogador tem 3 territórios
    int territoriosConquistados = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, corJogador) == 0)
            territoriosConquistados++;
    }

    if (strstr(missao, "3 territórios") && territoriosConquistados >= 3)
        return 1;

    if (strstr(missao, "todos os territórios") && territoriosConquistados == tamanho)
        return 1;

    // Outras verificações podem ser adicionadas
    return 0;
}

// --- Liberação de memória dinâmica ---
void liberarMemoria(Territorio *mapa, Jogador *jogadores, int qtdJogadores) {
    free(mapa);
    for (int i = 0; i < qtdJogadores; i++) {
        free(jogadores[i].missao);
    }
    free(jogadores);
}

// --- Função Principal ---
int main() {
    srand(time(NULL));
    int qtdTerritorios;

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("🌍🌎🌏 BEM-VINDO AO WAR  🌏🌎🌍\n\n");
    printf("Digite quantos territórios irão para a guerra: ");
    scanf("%d", &qtdTerritorios);
    limparBufferEntrada();

    // Alocação dos territórios
    Territorio *mapa = (Territorio *) calloc(qtdTerritorios, sizeof(Territorio));

    // Cadastro dos territórios
    for (int i = 0; i < qtdTerritorios; i++) {
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

    // Criação dos jogadores
    Jogador *jogadores = (Jogador *) calloc(TOTAL_JOGADORES, sizeof(Jogador));
    for (int i = 0; i < TOTAL_JOGADORES; i++) {
        printf("\nDigite o nome do jogador %d: ", i + 1);
        fgets(jogadores[i].nome, 30, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';

        printf("Cor do exército (igual à usada nos territórios): ");
        fgets(jogadores[i].cor, 10, stdin);
        jogadores[i].cor[strcspn(jogadores[i].cor, "\n")] = '\0';
    }

    // Missões possíveis
    char *missoes[TOTAL_MISSOES] = {
        "Conquistar 3 territórios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Dominar todos os territórios do mapa",
        "Possuir pelo menos 5 tropas em dois territórios",
        "Conquistar um território inimigo e mantê-lo"
    };

    // Atribuir missões
    for (int i = 0; i < TOTAL_JOGADORES; i++) {
        jogadores[i].missao = (char *) malloc(100 * sizeof(char));
        atribuirMissao(jogadores[i].missao, missoes, TOTAL_MISSOES);
        printf("\nJogador %s recebeu uma missão secreta!\n", jogadores[i].nome);
        exibirMissao(jogadores[i].missao);
    }

    int opcao;
    int vencedor = -1;

    do {
        exibirMapa(mapa, qtdTerritorios);

        // Verifica automaticamente se alguém venceu
        for (int i = 0; i < TOTAL_JOGADORES; i++) {
            if (verificarMissao(jogadores[i].missao, mapa, qtdTerritorios, jogadores[i].cor)) {
                vencedor = i;
                break;
            }
        }

        if (vencedor != -1) {
            printf("\n🏆 PARABÉNS! %s cumpriu sua missão e venceu o jogo! 🏆\n", jogadores[vencedor].nome);
            break;
        }

        printf("\nDeseja realizar um ataque? (1 = Sim 💀/ 0 = Encerrar 🥱): ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        if (opcao == 1) {
            int a, d;
            printf("Escolha o número do território que vai atacar: ");
            scanf("%d", &a);
            printf("Escolha o número do território que vai defender: ");
            scanf("%d", &d);
            limparBufferEntrada();

            a--; d--;

            if (a < 0 || a >= qtdTerritorios || d < 0 || d >= qtdTerritorios) {
                printf("😒 Território inválido! 😒\n");
                continue;
            }
            if (strcmp(mapa[a].cor, mapa[d].cor) == 0) {
                printf("🚩 Você não pode atacar seu próprio território! 🚩\n");
                continue;
            }
            if (mapa[a].tropas <= 0) {
                printf("😖 O território atacante não possui tropas suficientes!\n");
                continue;
            }

            atacar(&mapa[a], &mapa[d]);
        }

    } while (opcao != 0 && vencedor == -1);

    liberarMemoria(mapa, jogadores, TOTAL_JOGADORES);
    printf("\n-=-=-=-=-=Memória liberada com sucesso! -=-=-=-=-= \n");
    printf("\n\n-=-=-=-=-=-=-=-=-=🎮 Fim do jogo!🎮 -=-=-=-=-=-=-=-=-=\n\n\n\n\n\n" );

    return 0;
}

