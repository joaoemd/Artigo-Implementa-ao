#include <stdio.h>

#define NUM_ITENS 3

float calcularImposto(float *valorProduto, float taxaImposto, float *impostoPorItem) {
    float totalImposto = 0;
    for (int i = 0; i < NUM_ITENS; i++) {
        impostoPorItem[i] = valorProduto[i] * taxaImposto / 100.0;
        totalImposto += impostoPorItem[i];
    }
    return totalImposto;
}

void exibirTabela(float *valorProduto, float *impostoPorItem) {
    printf("\n%-10s%-15s%-15s\n", "Item", "Valor (R$)", "Imposto (R$)");
    for (int i = 0; i < NUM_ITENS; i++) {
        printf("%-10d%-15.2f%-15.2f\n", i + 1, valorProduto[i], impostoPorItem[i]);
    }
}

int main() {
    float valorProduto[NUM_ITENS];
    float taxaImposto, impostoTotal;
    float impostoPorItem[NUM_ITENS];

    // Solicita os valores dos produtos
    for (int i = 0; i < NUM_ITENS; i++) {
        printf("Digite o valor do %do produto: ", i + 1);
        scanf("%f", &valorProduto[i]);
    }

    printf("Digite a taxa de imposto em porcentagem: ");
    scanf("%f", &taxaImposto);

    impostoTotal = calcularImposto(valorProduto, taxaImposto, impostoPorItem);

    printf("\nO imposto de importacao total a ser pago e: R$ %.2f\n", impostoTotal);
    
    // Exibe a tabela
    exibirTabela(valorProduto, impostoPorItem);

    return 0;
}
