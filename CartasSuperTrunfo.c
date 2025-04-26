#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} CartaCidade;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler o nome da cidade, removendo o '\n'
void lerNomeCidade(char *nomeCidade) {
    fgets(nomeCidade, 50, stdin);
    for (int i = 0; nomeCidade[i] != '\0'; i++) {
        if (nomeCidade[i] == '\n') {
            nomeCidade[i] = '\0';
            break;
        }
    }
}

// Função para calcular Densidade Populacional e PIB per capita
void calcularAtributosDerivados(CartaCidade *carta) {
    carta->densidadePopulacional = carta->area != 0 ? carta->populacao / carta->area : 0;
    carta->pibPerCapita = carta->populacao != 0 ? carta->pib / carta->populacao : 0;
}

// Função para calcular o Super Poder
void calcularSuperPoder(CartaCidade *carta) {
    float inversoDensidade = (carta->densidadePopulacional != 0) ? (1 / carta->densidadePopulacional) : 0;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib + carta->pontosTuristicos + inversoDensidade + carta->pibPerCapita;
}

// Função para ler uma carta
void lerCarta(CartaCidade *carta) {
    printf("Estado (A-H): ");
    scanf(" %2s", carta->estado);

    printf("Código da carta (ex: A01): ");
    scanf(" %3s", carta->codigo);

    limparBuffer();

    printf("Nome da cidade: ");
    lerNomeCidade(carta->nomeCidade);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    limparBuffer();

    calcularAtributosDerivados(carta);
    calcularSuperPoder(carta);
}

// Função para exibir uma carta
void exibirCarta(const CartaCidade *carta) {
    printf("\n--- Carta ---\n");
    printf("Estado: %s\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta->pibPerCapita);
    printf("Super Poder: %.2f\n", carta->superPoder);
}

// Função para comparar dois valores e mostrar quem venceu
void compararValor(float valor1, float valor2, int menorGanha) {
    if ((menorGanha && valor1 < valor2) || (!menorGanha && valor1 > valor2)) {
        printf("Resultado: Carta 1 venceu!\n");
    } else if ((menorGanha && valor1 > valor2) || (!menorGanha && valor1 < valor2)) {
        printf("Resultado: Carta 2 venceu!\n");
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    CartaCidade carta1 = {"", "", "", 0, 0, 0, 0, 0, 0, 0};
    CartaCidade carta2 = {"", "", "", 0, 0, 0, 0, 0, 0, 0};

    printf("\n--- Cadastro da Primeira Carta ---\n");
    lerCarta(&carta1);

    printf("\n--- Cadastro da Segunda Carta ---\n");
    lerCarta(&carta2);

    printf("\n========= Cartas Digitadas =========\n");
    exibirCarta(&carta1);
    exibirCarta(&carta2);

    printf("\n========= Comparações =========\n");
    printf("População:\n");
    compararValor(carta1.populacao, carta2.populacao, 0);

    printf("Área:\n");
    compararValor(carta1.area, carta2.area, 0);

    printf("PIB:\n");
    compararValor(carta1.pib, carta2.pib, 0);

    printf("Pontos Turísticos:\n");
    compararValor(carta1.pontosTuristicos, carta2.pontosTuristicos, 0);

    printf("Densidade Populacional:\n");
    compararValor(carta1.densidadePopulacional, carta2.densidadePopulacional, 1);

    printf("PIB per Capita:\n");
    compararValor(carta1.pibPerCapita, carta2.pibPerCapita, 0);

    printf("Super Poder:\n");
    compararValor(carta1.superPoder, carta2.superPoder, 0);

    return 0;
}

