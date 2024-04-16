#include <stdio.h>

#define NUM_ITENS 3

float calcularImposto(float *valorProduto, float taxaImposto) {
    float totalImposto = 0;
    for (int i = 0; i < NUM_ITENS; i++) {
        totalImposto += valorProduto[i] * taxaImposto / 100.0;
    }
    return totalImposto;
}

int main() {
    float valorProduto[NUM_ITENS];
    float taxaImposto, impostoTotal;

    // Solicita os valores dos produtos
    for (int i = 0; i < NUM_ITENS; i++) {
        printf("Digite o valor do %do produto: ", i + 1);
        scanf("%f", &valorProduto[i]);
    }

    printf("Digite a taxa de imposto em porcentagem: ");
    scanf("%f", &taxaImposto);

    impostoTotal = calcularImposto(valorProduto, taxaImposto);

    printf("O imposto de importacao a ser pago e: R$ %.2f\n", impostoTotal);

    return 0;
}


    return 0;
}
