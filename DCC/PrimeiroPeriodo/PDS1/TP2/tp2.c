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
    // Abrindo o arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    // Lendo o número de produtos do arquivo
    fscanf(arquivo, "%d", numProdutos);
    // Alocando memória para o array de produtos
    *produtos = (struct Produto *)malloc(*numProdutos * sizeof(struct Produto));

    // Lendo os detalhes dos produtos do arquivo
    for (int i = 0; i < *numProdutos; i++) {
        fscanf(arquivo, "%d", &(*produtos)[i].codigo);
        fscanf(arquivo, " %[^\n]", (*produtos)[i].nome);
        fscanf(arquivo, "%d", &(*produtos)[i].quantidade);
        fscanf(arquivo, "%f", &(*produtos)[i].preco);
        fscanf(arquivo, " %2s", (*produtos)[i].estado);
    }

    // Fechando o arquivo
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
            // Imprimindo detalhes do produto
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("Estado: %s\n", produtos[i].estado);
            return 1;
        }
    }
    // Produto não encontrado
    printf("Produto não encontrado.\n");
    return 0;
}

// Função para encontrar o produto com a menor quantidade em estoque
void encontrarProdutoComMenorQuantidade(const struct Produto *produtos, int numProdutos) {
    int minQuantidade = produtos[0].quantidade;
    int indice = 0;

    // Encontrando o produto com a menor quantidade
    for (int i = 1; i < numProdutos; i++) {
        if (produtos[i].quantidade < minQuantidade) {
            minQuantidade = produtos[i].quantidade;
            indice = i;
        }
    }

    // Imprimindo detalhes do produto com a menor quantidade
    printf("Código: %d\n", produtos[indice].codigo);
    printf("Nome: %s\n", produtos[indice].nome);
    printf("Quantidade: %d\n", produtos[indice].quantidade);
    printf("Preço: %.2f\n", produtos[indice].preco);
    printf("Estado: %s\n", produtos[indice].estado);
}

// Função para listar produtos por estado
void listarProdutosPorEstado(const struct Produto *produtos, int numProdutos, const char *estado) {
    // Listando produtos com base no estado especificado
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            // Imprimindo detalhes dos produtos no estado especificado
            printf("Código: %d\n", produtos[i].codigo);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preço: %.2f\n", produtos[i].preco);
            printf("Estado: %s\n", produtos[i].estado);
        }
    }
}

// Função para encontrar o produto com a menor quantidade em estoque por estado
void encontrarProdutoComMenorQuantidadePorEstado(const struct Produto *produtos, int numProdutos, const char *estado) {
    int minQuantidade = -1;
    int indice = -1;

    // Encontrando o produto com a menor quantidade no estado especificado
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            if (indice == -1 || produtos[i].quantidade < minQuantidade) {
                minQuantidade = produtos[i].quantidade;
                indice = i;
            }
        }
    }

    // Imprimindo detalhes do produto com a menor quantidade no estado especificado
    if (indice != -1) {
        printf("Código: %d\n", produtos[indice].codigo);
        printf("Nome: %s\n", produtos[indice].nome);
        printf("Quantidade: %d\n", produtos[indice].quantidade);
        printf("Preço: %.2f\n", produtos[indice].preco);
        printf("Estado: %s\n", produtos[indice].estado);
    }
}

// Função para calcular a quantidade total e o preço total dos produtos em estoque
void calcularQuantidadeTotalEPreco(const struct Produto *produtos, int numProdutos) {
    int quantidadeTotal = 0;
    float precoTotal = 0;

    // Calculando a quantidade total e o preço total
    for (int i = 0; i < numProdutos; i++) {
        quantidadeTotal += produtos[i].quantidade;
        precoTotal += produtos[i].preco;
    }

    // Imprimindo a quantidade total e o preço total
    printf("Quantidade Total: %d\n", quantidadeTotal);
    printf("Preço Total: %.2f\n", precoTotal);
}

int main(int argc, char *argv[]) {
    // Verificando o número correto de argumentos na linha de comando
    if (argc < 3) {
        printf("Uso: %s [arquivoDeEntrada] [função] [arquivoDeSaida] [argumentoAdicional]\n", argv[0]);
        return 1;
    }

    // Obtendo os parâmetros da linha de comando
    const char *arquivoDeEntrada = argv[1];
    int funcao = atoi(argv[2]);
    const char *arquivoDeSaida = argc > 3 ? argv[3] : NULL;
    int argumentoAdicional = argc > 4 ? atoi(argv[4]) : 0;

    // Declarando variáveis para armazenar os produtos
    struct Produto *produtos;
    int numProdutos;

    // Lendo os produtos do arquivo
    if (!lerProdutos(arquivoDeEntrada, &produtos, &numProdutos)) {
        return 1;
    }

    // Executando a função correspondente com base no argumento fornecido
    switch (funcao) {
        case 1: // Gerar relatório de estoque
            // Ordenando os produtos por nome
            qsort(produtos, numProdutos, sizeof(struct Produto), compararProdutos);

            // Se um arquivo de saída foi fornecido, escrevendo os produtos ordenados nele
            if (arquivoDeSaida != NULL) {
                FILE *arquivo = fopen(arquivoDeSaida, "w");
                if (arquivo == NULL) {
                    perror("Erro ao criar o arquivo de saída");
                    return 1;
                }

                // Escrevendo os produtos ordenados no arquivo de saída
                for (int i = 0; i < numProdutos; i++) {
                    fprintf(arquivo, "%d\n", produtos[i].codigo);
                    fprintf(arquivo, "%s\n", produtos[i].nome);
                    fprintf(arquivo, "%d\n", produtos[i].quantidade);
                    fprintf(arquivo, "%.2f\n", produtos[i].preco);
                    fprintf(arquivo, "%s\n", produtos[i].estado);
                }

                // Fechando o arquivo de saída
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

    // Liberando a memória alocada para os produtos
    free(produtos);
    return EXIT_SUCCESS;
}

