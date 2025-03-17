#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para exibir o menu de atributos e retornar a escolha do jogador
int escolherAtributo(int atributoEscolhido) {
    int escolha;
    printf("\nEscolha o %dº atributo para comparação:\n", atributoEscolhido);
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int main() {
    // Variáveis para as cartas
    char codigo1[10], codigo2[10];
    char estado1[30], estado2[30];
    char cidade1[80], cidade2[80];
    unsigned long int populacao1, populacao2; // População como unsigned long int
    float pib1, pib2;
    float area1, area2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float super_poder1, super_poder2;

    // Informações para a primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf("%s", estado1);
    limparBuffer();

    printf("O código contém o estado mais o número da cidade\n");
    printf("Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo1);
    limparBuffer();

    printf("Escreva o nome da cidade (pode usar espaços):\n");
    printf("Nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin); // Captura a linha inteira, incluindo espaços
    cidade1[strcspn(cidade1, "\n")] = '\0'; // Remove a nova linha (\n) do final

    printf("População: ");
    scanf("%lu", &populacao1);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &area1);
    limparBuffer();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    limparBuffer();

    // Informações para a segunda carta
    printf("Cadastro da Carta 2\n");
    printf("Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf("%s", estado2);
    limparBuffer();

    printf("O código contém o estado mais o número da cidade\n");
    printf("Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo2);
    limparBuffer();

    printf("Escreva o nome da cidade (pode usar espaços):\n");
    printf("Nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin); // Captura a linha inteira, incluindo espaços
    cidade2[strcspn(cidade2, "\n")] = '\0'; // Remove a nova linha (\n) do final

    printf("População: ");
    scanf("%lu", &populacao2);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &area2);
    limparBuffer();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    limparBuffer();

    // Cálculos para a primeira carta
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (float)pib1 / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1 / densidade1);

    // Cálculos para a segunda carta
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (float)pib2 / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1 / densidade2);

    // Exibição dos dados das cartas
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %.0lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais/habitante\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %.0lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais/habitante\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Escolha dos dois atributos
    int atributo1, atributo2;
    atributo1 = escolherAtributo(1);

    // Garantir que o segundo atributo seja diferente do primeiro
    do {
        atributo2 = escolherAtributo(2);
        if (atributo2 == atributo1) {
            printf("Você já escolheu esse atributo. Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Comparação dos atributos
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1:
            if (populacao1 > populacao2) pontosCarta1++;
            else if (populacao1 < populacao2) pontosCarta2++;
            break;
        case 2:
            if (area1 > area2) pontosCarta1++;
            else if (area1 < area2) pontosCarta2++;
            break;
        case 3:
            if (pib1 > pib2) pontosCarta1++;
            else if (pib1 < pib2) pontosCarta2++;
            break;
        case 4:
            if (pontos_turisticos1 > pontos_turisticos2) pontosCarta1++;
            else if (pontos_turisticos1 < pontos_turisticos2) pontosCarta2++;
            break;
        case 5:
            if (densidade1 < densidade2) pontosCarta1++;
            else if (densidade1 > densidade2) pontosCarta2++;
            break;
        case 6:
            if (pib_per_capita1 > pib_per_capita2) pontosCarta1++;
            else if (pib_per_capita1 < pib_per_capita2) pontosCarta2++;
            break;
        case 7:
            if (super_poder1 > super_poder2) pontosCarta1++;
            else if (super_poder1 < super_poder2) pontosCarta2++;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1:
            if (populacao1 > populacao2) pontosCarta1++;
            else if (populacao1 < populacao2) pontosCarta2++;
            break;
        case 2:
            if (area1 > area2) pontosCarta1++;
            else if (area1 < area2) pontosCarta2++;
            break;
        case 3:
            if (pib1 > pib2) pontosCarta1++;
            else if (pib1 < pib2) pontosCarta2++;
            break;
        case 4:
            if (pontos_turisticos1 > pontos_turisticos2) pontosCarta1++;
            else if (pontos_turisticos1 < pontos_turisticos2) pontosCarta2++;
            break;
        case 5:
            if (densidade1 < densidade2) pontosCarta1++;
            else if (densidade1 > densidade2) pontosCarta2++;
            break;
        case 6:
            if (pib_per_capita1 > pib_per_capita2) pontosCarta1++;
            else if (pib_per_capita1 < pib_per_capita2) pontosCarta2++;
            break;
        case 7:
            if (super_poder1 > super_poder2) pontosCarta1++;
            else if (super_poder1 < super_poder2) pontosCarta2++;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Exibição do resultado
    printf("\nResultado da Comparação:\n");
    printf("Carta 1: %d pontos\n", pontosCarta1);
    printf("Carta 2: %d pontos\n", pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("Carta 1 venceu!\n");
    } else if (pontosCarta1 < pontosCarta2) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
