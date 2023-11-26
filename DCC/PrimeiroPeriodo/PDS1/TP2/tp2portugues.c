#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura de dados para um produto qualquer
struct Produto {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
    char estado[3];
};

// Função para ler os produtos de um arquivo
int lerProdutos(const char *nomeArquivo, struct Produto **produtos, int *numProdutos) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    fscanf(arquivo, "%d", numProdutos);
    *produtos = (struct Produto *)malloc(*numProdutos * sizeof(struct Produto));

    for (int i = 0; i < *numProdutos; i++) {
        fscanf(arquivo, "%d", &(*produtos)[i].codigo);
        fscanf(arquivo, " %[^\n]", (*produtos)[i].nome);
        fscanf(arquivo, "%d", &(*produtos)[i].quantidade);
        fscanf(arquivo, "%f", &(*produtos)[i].preco);
        fscanf(arquivo, " %2s", (*produtos)[i].estado);
    }

    fclose(arquivo);
    return 1;
}

// Função para comparar dois produtos pelo nome
int compararProdutos(const void *a, const void *b) {
    return strcmp(((struct Produto *)a)->nome, ((struct Produto *)b)->nome);
}

// Função para encontrar um produto pelo código
int encontrarProdutoPorCodigo(const struct Produto *produtos, int numProdutos, int codigo) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("%d\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);
            return 1;
        }
    }
    return 0;
}

// Função para encontrar o produto com a menor quantidade em estoque
void encontrarProdutoComMenorQuantidade(const struct Produto *produtos, int numProdutos) {
    int minQuantidade = produtos[0].quantidade;
    int indice = 0;

    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].quantidade < minQuantidade) {
            minQuantidade = produtos[i].quantidade;
            indice = i;
        }
    }

    printf("%d\n", produtos[indice].codigo);
    printf("%s\n", produtos[indice].nome);
    printf("%d\n", produtos[indice].quantidade);
    printf("%.2f\n", produtos[indice].preco);
    printf("%s\n", produtos[indice].estado);
}

// Função para listar produtos por estado
void listarProdutosPorEstado(const struct Produto *produtos, int numProdutos, const char *estado) {
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            printf("%d\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);
        }
    }
}

// Função para encontrar o produto com a menor quantidade em estoque por estado
void encontrarProdutoComMenorQuantidadePorEstado(const struct Produto *produtos, int numProdutos, const char *estado) {
    int minQuantidade = -1;
    int indice = -1;

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            if (indice == -1 || produtos[i].quantidade < minQuantidade) {
                minQuantidade = produtos[i].quantidade;
                indice = i;
            }
        }
    }

    if (indice != -1) {
        printf("%d\n", produtos[indice].codigo);
        printf("%s\n", produtos[indice].nome);
        printf("%d\n", produtos[indice].quantidade);
        printf("%.2f\n", produtos[indice].preco);
        printf("%s\n", produtos[indice].estado);
    }
}

// Função para calcular a quantidade total e o preço total dos produtos em estoque
void calcularQuantidadeTotalEPreco(const struct Produto *produtos, int numProdutos) {
    int quantidadeTotal = 0;
    float precoTotal = 0;

    for (int i = 0; i < numProdutos; i++) {
        quantidadeTotal += produtos[i].quantidade;
        precoTotal += produtos[i].preco;
    }

    printf("%d\n", quantidadeTotal);
    printf("%.2f\n", precoTotal);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s [arquivoDeEntrada] [função] [arquivoDeSaida] [argumentoAdicional]\n", argv[0]);
        return 1;
    }

    const char *arquivoDeEntrada = argv[1];
    int funcao = atoi(argv[2]);
    const char *arquivoDeSaida = argc > 3 ? argv[3] : NULL;
    int argumentoAdicional = argc > 4 ? atoi(argv[4]) : 0;

    struct Produto *produtos;
    int numProdutos;

    if (!lerProdutos(arquivoDeEntrada, &produtos, &numProdutos)) {
        return 1;
    }

    switch (funcao) {
        case 1: // Gerar relatório de estoque
            qsort(produtos, numProdutos, sizeof(struct Produto), compararProdutos);

            if (arquivoDeSaida != NULL) {
                FILE *arquivo = fopen(arquivoDeSaida, "w");
                if (arquivo == NULL) {
                    perror("Erro ao criar o arquivo de saída");
                    return 1;
                }

                for (int i = 0; i < numProdutos; i++) {
                    fprintf(arquivo, "%d\n", produtos[i].codigo);
                    fprintf(arquivo, "%s\n", produtos[i].nome);
                    fprintf(arquivo, "%d\n", produtos[i].quantidade);
                    fprintf(arquivo, "%.2f\n", produtos[i].preco);
                    fprintf(arquivo, "%s\n", produtos[i].estado);
                }

                fclose(arquivo);
            }

            break;

        case 2: // Pesquisar por produto pelo código
            if (argumentoAdicional > 0) {
                encontrarProdutoPorCodigo(produtos, numProdutos, argumentoAdicional);
            }
            break;

        case 3: // Listar dados do produto com menor quantidade em estoque
            encontrarProdutoComMenorQuantidade(produtos, numProdutos);
            break;

        case 4: // Listar produtos por estado
            if (arquivoDeSaida != NULL) {
                listarProdutosPorEstado(produtos, numProdutos, arquivoDeSaida);
            }
            break;

        case 5: // Encontrar produto com menor quantidade em estoque do estado
            if (arquivoDeSaida != NULL) {
                encontrarProdutoComMenorQuantidadePorEstado(produtos, numProdutos, arquivoDeSaida);
            }
            break;

        case 6: // Calcular a quantidade total de itens no estoque
            calcularQuantidadeTotalEPreco(produtos, numProdutos);
            break;

        default:
            printf("Número de função inválido.\n");
    }

    free(produtos);
    return EXIT_SUCCESS;
}

