#include <stdio.h>

int main() {
    // Declaração das variáveis para a primeira carta
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    float populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Declaração das variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    float populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Entrada de dados para a primeira carta
    printf("Insira os dados da primeira carta:\n");
    printf("Estado (A ou H): ");
    scanf(" %c", &estado1);
    printf("Código da carta: ");
    scanf(" %s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %49s", nomeCidade1);
    printf("População: ");
    scanf(" %f", &populacao1);
    printf("Área (km²): ");
    scanf(" %f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf(" %f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf(" %d", &pontosTuristicos1);

    // Entrada de dados para a segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    printf("Estado (A ou H): ");
    scanf(" %c", &estado2);
    printf("Código da carta: ");
    scanf(" %s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %49s", nomeCidade2);
    printf("População: ");
    scanf(" %f", &populacao2);
    printf("Área (km²): ");
    scanf(" %f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf(" %f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf(" %d", &pontosTuristicos2);

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %.0f\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de pontos turísticos: %d\n", pontosTuristicos1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("População: %.0f\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de pontos turísticos: %d\n", pontosTuristicos2);

    return 0;
}

