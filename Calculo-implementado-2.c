#include <stdio.h>
#include <stdlib.h>

#define NUM_ITENS 3

// Estrutura para nó da fila
typedef struct Node {
    float valor;
    struct Node* next;
} Node;

// Estrutura para nó da pilha
typedef struct StackNode {
    float imposto;
    struct StackNode* next;
} StackNode;

// Função para enfileirar um valor
void enqueue(Node** rear, float valor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->valor = valor;
    newNode->next = NULL;
    if (*rear == NULL) {
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Função para desenfileirar um valor
float dequeue(Node** front) {
    if (*front == NULL) {
        printf("Fila vazia\n");
        return -1;
    }
    Node* temp = *front;
    float valor = temp->valor;
    *front = (*front)->next;
    free(temp);
    return valor;
}

// Função para empilhar um imposto
void push(StackNode** top, float imposto) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->imposto = imposto;
    newNode->next = *top;
    *top = newNode;
}

// Função para desempilhar um imposto
float pop(StackNode** top) {
    if (*top == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
    StackNode* temp = *top;
    float imposto = temp->imposto;
    *top = (*top)->next;
    free(temp);
    return imposto;
}

// Função para calcular o imposto total
float calcularImpostoTotal(Node** front, float taxaImposto) {
    float impostoTotal = 0;
    StackNode* top = NULL;

    // Calcula o imposto de cada item e empilha na pilha
    for (int i = 0; i < NUM_ITENS; i++) {
        float valorProduto = dequeue(front);
        float imposto = valorProduto * taxaImposto / 100.0;
        printf("Valor do %do produto (sem imposto): R$ %.2f\n", i + 1, valorProduto);
        printf("Imposto do %do produto: R$ %.2f\n", i + 1, imposto);
        impostoTotal += imposto;
        push(&top, imposto);
    }

    // Desempilha os impostos e enfileira novamente para restaurar a fila original
    while (top != NULL) {
        float imposto = pop(&top);
        enqueue(front, imposto);
    }

    return impostoTotal;
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    float taxaImposto, impostoTotal;

    // Insere os valores dos produtos na fila
    for (int i = 0; i < NUM_ITENS; i++) {
        float valorProduto;
        printf("Digite o valor do %do produto: ", i + 1);
        scanf("%f", &valorProduto);
        enqueue(&rear, valorProduto);
        if (front == NULL) {
            front = rear;
        }
    }

    printf("Digite a taxa de imposto em porcentagem: ");
    scanf("%f", &taxaImposto);

    // Calcula o imposto total e exibe o resultado
    impostoTotal = calcularImpostoTotal(&front, taxaImposto);
    printf("\nO imposto de importacao total a ser pago e: R$ %.2f\n", impostoTotal);

    return 0;
}
