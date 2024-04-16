#include <stdio.h>

#define NUM_ITENS 3

int main() {
    float taxaImposto, impostoTotal = 0;

    printf("Digite a taxa de imposto em porcentagem: ");
    scanf("%f", &taxaImposto);

    for (int i = 0; i < NUM_ITENS; i++) {
        float valorProduto;
        printf("Digite o valor do %do produto: ", i + 1);
        scanf("%f", &valorProduto);
        
        float imposto = valorProduto * taxaImposto / 100.0;
        printf("Valor do %do produto (sem imposto): R$ %.2f\n", i + 1, valorProduto);
        printf("Imposto do %do produto: R$ %.2f\n", i + 1, imposto);
        impostoTotal += imposto;
    }

    printf("\nO imposto de importacao total a ser pago e: R$ %.2f\n", impostoTotal);

    return 0;
}
