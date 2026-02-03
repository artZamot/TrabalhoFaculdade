#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int menu, comparar1, comparar2;

    /* ===== DADOS DAS CARTAS ===== */
    char estado[2][3];
    char codigo[2][10];
    char nomeCidade[2][50];

    float populacao[2];
    float area[2];
    float pib[2];
    int pontosTuristicos[2];

    float pibPerCapita[2];
    float densidadePopulacional[2];
    float superPoder[2];

    char buffer[100];

    /* ===== CARTA 1 (JOGADOR) ===== */
    printf("\n=== Carta 1 ===\n\n");

    printf("Estado: ");
    fgets(estado[0], sizeof(estado[0]), stdin);
    estado[0][strcspn(estado[0], "\n")] = '\0';

    printf("Codigo: ");
    fgets(codigo[0], sizeof(codigo[0]), stdin);
    codigo[0][strcspn(codigo[0], "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(nomeCidade[0], sizeof(nomeCidade[0]), stdin);
    nomeCidade[0][strcspn(nomeCidade[0], "\n")] = '\0';

    printf("População: ");
    fgets(buffer, sizeof(buffer), stdin);
    populacao[0] = atof(buffer);

    printf("Área (km²): ");
    fgets(buffer, sizeof(buffer), stdin);
    area[0] = atof(buffer);

    printf("PIB (bilhões): ");
    fgets(buffer, sizeof(buffer), stdin);
    pib[0] = atof(buffer);

    printf("Número de Pontos Turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    pontosTuristicos[0] = atoi(buffer);

    pibPerCapita[0] = pib[0] / populacao[0];
    densidadePopulacional[0] = populacao[0] / area[0];
    superPoder[0] = pibPerCapita[0] + pontosTuristicos[0] + area[0] + populacao[0] + pib[0];

    /* ===== CARTA 2 (ALEATÓRIA) ===== */
    char estados[][3] = {"SP", "RJ", "MG", "BA", "RS"};
    char cidades[][50] = {"São Paulo", "Rio de Janeiro", "Belo Horizonte", "Salvador", "Porto Alegre"};

    int idx = rand() % 5;

    strcpy(estado[1], estados[idx]);
    sprintf(codigo[1], "%c%02d", estados[idx][0], rand() % 100);
    strcpy(nomeCidade[1], cidades[idx]);

    populacao[1] = 50 + rand() % 1000;
    area[1] = 100 + rand() % 500;
    pib[1] = 10 + rand() % 300;
    pontosTuristicos[1] = rand() % 20;

    pibPerCapita[1] = pib[1] / populacao[1];
    densidadePopulacional[1] = populacao[1] / area[1];
    superPoder[1] = pibPerCapita[1] + pontosTuristicos[1] + area[1] + populacao[1] + pib[1];

    /* ===== MENU ===== */
    printf("\n===== MENU =====\n");
    printf("1 - Comparar cartas\n");
    printf("2 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &menu);

    if (menu != 1) {
        printf("Saindo do programa...\n");
        return 0;
    }

    /* ===== ESCOLHA DOS ATRIBUTOS ===== */
    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - PIB per Capita\n6 - Densidade Populacional\n7 - Super Poder\n");
    scanf("%d", &comparar1);

    do {
        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        scanf("%d", &comparar2);

        if (comparar1 == comparar2) {
            printf("Atributos iguais! Escolha outro.\n");
        }
    } while (comparar1 == comparar2);

    /* ===== COMPARAÇÃO ===== */
    float soma1 = 0, soma2 = 0;

    for (int i = 0; i < 2; i++) {
        int atr = (i == 0) ? comparar1 : comparar2;

        float v1, v2;

        switch (atr) {
            case 1: v1 = populacao[0]; v2 = populacao[1]; break;
            case 2: v1 = area[0]; v2 = area[1]; break;
            case 3: v1 = pib[0]; v2 = pib[1]; break;
            case 4: v1 = pontosTuristicos[0]; v2 = pontosTuristicos[1]; break;
            case 5: v1 = pibPerCapita[0]; v2 = pibPerCapita[1]; break;
            case 6: v1 = densidadePopulacional[0]; v2 = densidadePopulacional[1]; break;
            case 7: v1 = superPoder[0]; v2 = superPoder[1]; break;
            default: v1 = v2 = 0;
        }

        if (atr == 6) { // densidade: menor vence
            soma1 += (v1 < v2) ? v1 : 0;
            soma2 += (v2 < v1) ? v2 : 0;
        } else {
            soma1 += v1;
            soma2 += v2;
        }
    }

    /* ===== RESULTADO ===== */
    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s (%.2f)\n", nomeCidade[0], soma1);
    printf("%s (%.2f)\n", nomeCidade[1], soma2);

    if (soma1 > soma2)
        printf("\nVencedora: %s\n", nomeCidade[0]);
    else if (soma2 > soma1)
        printf("\nVencedora: %s\n", nomeCidade[1]);
    else
        printf("\nEmpate!\n");

    return 0;
}
