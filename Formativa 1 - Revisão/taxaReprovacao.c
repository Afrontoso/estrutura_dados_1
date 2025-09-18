#include <stdio.h>
#include <stdlib.h> // Para a função qsort
#include <string.h> // Para a função strcmp

// Função de comparação para qsort, para ordenar inteiros em ordem crescente
int compararInteiros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int D; // Quantidade total de disciplinas
    
    // Lê a quantidade total de disciplinas, que é a primeira linha da entrada.
    scanf("%d", &D);

    int ano, semestre, m; // Ano, semestre e quantidade de disciplinas no semestre
    
    // O loop continua lendo dados até o final do arquivo (EOF).
    while (scanf("%d %d %d", &ano, &semestre, &m) != EOF) {
        int codigo, matriculados, aprovados;
        int max_reprovacoes = -1;
        int codigos_max_reprovacoes[m]; // Array para armazenar os códigos com maior reprovação
        int count_codigos = 0;

        // Imprime o cabeçalho do semestre.
        printf("%d/%d\n", ano, semestre);

        // Loop para ler os dados de cada uma das 'm' disciplinas do semestre.
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &codigo, &matriculados, &aprovados);
            int reprovacoes = matriculados - aprovados;

            // Verifica se a reprovação atual é a nova máxima.
            if (reprovacoes > max_reprovacoes) {
                max_reprovacoes = reprovacoes;
                count_codigos = 0; // Reseta a lista de códigos, pois há um novo máximo.
                codigos_max_reprovacoes[count_codigos++] = codigo;
            } else if (reprovacoes == max_reprovacoes) {
                // Se for igual, adiciona o código à lista.
                codigos_max_reprovacoes[count_codigos++] = codigo;
            }
        }
        
        // Se houver mais de um código, ordena a lista em ordem crescente.
        if (count_codigos > 1) {
            qsort(codigos_max_reprovacoes, count_codigos, sizeof(int), compararInteiros);
        }

        // Imprime os códigos em ordem crescente.
        for (int i = 0; i < count_codigos; i++) {
            printf("%d ", codigos_max_reprovacoes[i]);
        }
        
        // Imprime as linhas de quebra de linha conforme o exemplo.
        printf("\n\n");
    }

    return 0;
}
