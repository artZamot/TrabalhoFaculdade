#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct carta {
    char estado[3];              // "A"
    char codigo[10];             // "A01"           
    char nomeCidade[50];         // "SÃ£o Paulo"     
    float populacao;             // 1234.56         // em milhÃµes
    float area;                  // 1521.11         // em kmÂ²
    float pib;                   // 1234.56         // em bilhÃµes de reais
    int pontosTuristicos;        // 10              // nÃºmero de pontos turÃ­sticos    
    float pibPerCapita;          // 12345.67        // Ã© o PIB dividido pela populaÃ§Ã£o
    float densidadePopulacional; // 123.45          // Ã© a populaÃ§Ã£o dividida pela Ã¡rea
    float superPoder;            // valor calculado para o super poder da carta    
    
};

int main() {
    int menu, comparar; 
    struct carta cartas[2];
    char buffer[100];
    
    for (int i = 0; i < 2; i++) {
        printf("\n=== Carta %d ===\n\n", i + 1);

        printf("Estado: ");
        fgets(cartas[i].estado, sizeof(cartas[i].estado), stdin);
        cartas[i].estado[strcspn(cartas[i].estado, "\n")] = '\0';

        printf("CÃ³digo: ");
        fgets(cartas[i].codigo, sizeof(cartas[i].codigo), stdin);
        cartas[i].codigo[strcspn(cartas[i].codigo, "\n")] = '\0';

        printf("Nome da Cidade: ");
        fgets(cartas[i].nomeCidade, sizeof(cartas[i].nomeCidade), stdin);
        cartas[i].nomeCidade[strcspn(cartas[i].nomeCidade, "\n")] = '\0';

        printf("PopulaÃ§Ã£o: ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].populacao = atoi(buffer);

        printf("Ãrea (kmÂ²): ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].area = atof(buffer);

        printf("PIB (bilhÃµes): ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].pib = atof(buffer);

        printf("NÃºmero de Pontos TurÃ­sticos: ");
        fgets(buffer, sizeof(buffer), stdin);
        cartas[i].pontosTuristicos = atoi(buffer);

        cartas[i].pibPerCapita = (float)(cartas[i].pib / cartas[i].populacao);
        cartas[i].densidadePopulacional = (float)(cartas[i].populacao / cartas[i].area);
        cartas[i].superPoder = cartas[i].pibPerCapita + cartas[i].pontosTuristicos + cartas[i].area + cartas[i].populacao + cartas[i].pib;
        
    }

    
    printf("\n===== CARTAS CADASTRADAS =====\n");



    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n\n", i + 1);
        printf("Estado: %s\n", cartas[i].estado);
        printf("CÃ³digo: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("PopulaÃ§Ã£o: %.2f\n", cartas[i].populacao);
        printf("Ãrea: %.2f kmÂ²\n", cartas[i].area);
        printf("PIB: %.2f mil de reais\n", cartas[i].pib);
        printf("NÃºmero de Pontos TurÃ­sticos: %d\n", cartas[i].pontosTuristicos);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("Densidade Populacional: %.2f\n", cartas[i].densidadePopulacional);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
    }
    printf("\n===== MENU =====\n");
    printf("1 - Comparar cartas\n");
    printf("2 - sair - Sair do programa\n");
    printf("Escolha uma opÃ§Ã£o: ");
    scanf("%d", &menu);

    switch (menu == 1)
    {
    case 1:
        printf("\n===== COMPARAÃ‡ÃƒO DE CARTAS =====\n");
        printf("Selecione quais atributos comparar:\n");
        printf("1 - PopulaÃ§Ã£o\n");
        printf("2 - Ãrea\n");
        printf("3 - PIB\n");
        printf("4 - NÃºmero de Pontos TurÃ­sticos\n");
        printf("5 - PIB per Capita\n");
        printf("6 - Densidade Populacional\n");
        printf("7 - Super Poder\n");
        scanf("%d", &comparar);
        break;
    
    default:
        printf("Saindo do programa...\n");
        
        break;
    }

    if (comparar == 1)
    {
        printf("PopulaÃ§Ã£o da Carta 1: %.2f\n", cartas[0].populacao);
        printf("PopulaÃ§Ã£o da Carta 2: %.2f\n", cartas[1].populacao);
        if (cartas[0].populacao > cartas[1].populacao)
        {
            printf("\nA carta com maior populaÃ§Ã£o Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].populacao > cartas[0].populacao) {
            printf("\nA carta com maior populaÃ§Ã£o Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas tÃªm a mesma populaÃ§Ã£o.\n");
        }
        
    } else if (comparar == 2)
    {
        printf("Ãrea da Carta 1: %.2f kmÂ²\n", cartas[0].area);
        printf("Ãrea da Carta 2: %.2f kmÂ²\n", cartas[1].area);
            if (cartas[0].area > cartas[1].area) {
                printf("\nA carta com maior Ã¡rea Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
            } else if (cartas[1].area > cartas[0].area) {
                printf("\nA carta com maior Ã¡rea Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
            } else {
                printf("\nAs duas cartas tÃªm a mesma Ã¡rea.\n");
            }
        
    } else if (comparar == 3)
    {
        printf("PIB da Carta 1: %.2f mil de reais\n", cartas[0].pib);
        printf("PIB da Carta 2: %.2f mil de reais\n", cartas[1].pib);
         if (cartas[0].pib > cartas[1].pib) {
            printf("\nA carta com maior PIB Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].pib > cartas[0].pib) {
            printf("\nA carta com maior PIB Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas tÃªm o mesmo PIB.\n");
        }

    } else if (comparar == 4)
    {
        printf("NÃºmero de Pontos TurÃ­sticos da Carta 1: %d\n", cartas[0].pontosTuristicos);
        printf("NÃºmero de Pontos TurÃ­sticos da Carta 2: %d\n", cartas[1].pontosTuristicos);
         if (cartas[0].pontosTuristicos > cartas[1].pontosTuristicos) {
            printf("\nA carta com maior nÃºmero de pontos turÃ­sticos Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].pontosTuristicos > cartas[0].pontosTuristicos) {
            printf("\nA carta com maior nÃºmero de pontos turÃ­sticos Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas tÃªm o mesmo nÃºmero de pontos turÃ­sticos.\n");
        }   

    } else if (comparar == 5)
    {
        printf("PIB per Capita da Carta 1: %.2f\n", cartas[0].pibPerCapita);
        printf("PIB per Capita da Carta 2: %.2f\n", cartas[1].pibPerCapita);
            if (cartas[0].pibPerCapita > cartas[1].pibPerCapita) {
                printf("\nA carta com maior PIB per Capita Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
            } else if (cartas[1].pibPerCapita > cartas[0].pibPerCapita) {
                printf("\nA carta com maior PIB per Capita Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
            } else {
                printf("\nAs duas cartas tÃªm o mesmo PIB per Capita.\n");
            }

    } else if (comparar == 6)
    {
        printf("Densidade Populacional da Carta 1: %.2f\n", cartas[0].densidadePopulacional);
        printf("Densidade Populacional da Carta 2: %.2f\n", cartas[1].densidadePopulacional);
         if (cartas[0].densidadePopulacional < cartas[1].densidadePopulacional) {
            printf("\nA carta com menor densidade populacional Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].densidadePopulacional < cartas[0].densidadePopulacional) {
            printf("\nA carta com menor densidade populacional Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas tÃªm a mesma densidade populacional.\n");
        }   

    } else if (comparar == 7)
    {
        printf("Super Poder da Carta 1: %.2f\n", cartas[0].superPoder);
        printf("Super Poder da Carta 2: %.2f\n", cartas[1].superPoder);

         if (cartas[0].superPoder > cartas[1].superPoder) {
            printf("\nA carta com maior super poder Ã© a Carta 1: %s\n", cartas[0].nomeCidade);
        } else if (cartas[1].superPoder > cartas[0].superPoder) {
            printf("\nA carta com maior super poder Ã© a Carta 2: %s\n", cartas[1].nomeCidade);
        } else {
            printf("\nAs duas cartas tÃªm o mesmo super poder.\n");
        }   
    }
        return 0;
    }


    