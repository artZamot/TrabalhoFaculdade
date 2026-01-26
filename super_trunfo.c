#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct carta {
    char estado[3];              // "A"
    char codigo[10];             // "A01"           
    char nomeCidade[50];         // "São Paulo"     
    float populacao;             // 1234.56         // em milhões
    float area;                  // 1521.11         // em km²
    float pib;                   // 1234.56         // em bilhões de reais
    int pontosTuristicos;        // 10              // número de pontos turísticos    
    float pibPerCapita;          // 12345.67        // é o PIB dividido pela população
    float densidadePopulacional; // 123.45          // é a população dividida pela área
    float superPoder;            // valor calculado para o super poder da carta    
     
};

int main() {
    struct carta cartas[2];
    char buffer[100];
    
    for (int i = 0; i < 2; i++) {
        printf("\n=== Carta %d ===\n\n", i + 1);

        printf("Estado: ");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = '\0';

        printf("Código: ");
        fgets(cartas[i].codigo, sizeof(cartas[i].codigo), stdin);
        cartas[i].codigo[strcspn(cartas[i].codigo, "\n")] = '\0';

        printf("Nome da Cidade: ");
        fgets(cartas[i].nomeCidade, sizeof(cartas[i].nomeCidade), stdin);
        cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0';

        printf("População: ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].populacao = atoi(buffer);

        printf("Área (km²): ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].area = atof(buffer);

        printf("PIB (bilhões): ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].pib = atof(buffer);

        printf("Número de Pontos Turísticos: ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].pontosTuristicos = atoi(buffer);

        cartas[i].pibPerCapita = (float)(cartas[i].pib / cartas[i].populacao);
        cartas[i].densidadePopulacional = (float)(cartas[i].populacao / cartas[i].area);
        cartas[i].superPoder = cartas[i].pibPerCapita + cartas[i].densidadePopulacional + cartas[i].pontosTuristicos + cartas[i].area + cartas[i].populacao + cartas[i].pib;
        
    }

    
    printf("\n===== CARTAS CADASTRADAS =====\n");



    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %.2f\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f mil de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("Densidade Populacional: %.2f\n", cartas[i].densidadePopulacional);

        if (cartas[0].superPoder > cartas[1].superPoder) {
            printf("\nA carta com maior super poder é a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].superPoder > cartas[0].superPoder) {
            printf("\nA carta com maior super poder é a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas têm o mesmo super poder.\n");
        }   
    }

    return 0;
} 