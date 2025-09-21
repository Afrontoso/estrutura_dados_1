#include <stdio.h>
#include <stdlib.h> 

struct Disciplina {
    int codigo;
    int matriculados;
    int aprovados;
};

struct Semestre {
    int ano;
    int semestre;
    int m; 
    struct Disciplina disciplinas[100];
};

int compararInteiros(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int D;
    scanf("%d", &D);

    struct Semestre semestres_lidos[100]; 
    int num_semestres = 0; 
    
    while (scanf("%d %d %d", &semestres_lidos[num_semestres].ano, &semestres_lidos[num_semestres].semestre, &semestres_lidos[num_semestres].m) != EOF) {
        
        int disciplinas_neste_semestre = semestres_lidos[num_semestres].m;
        
        for (int i = 0; i < disciplinas_neste_semestre; i++) {
            scanf("%d %d %d", 
                  &semestres_lidos[num_semestres].disciplinas[i].codigo, 
                  &semestres_lidos[num_semestres].disciplinas[i].matriculados, 
                  &semestres_lidos[num_semestres].disciplinas[i].aprovados);
        }
        
        num_semestres++;
    }

    for (int i = 0; i < num_semestres; i++) {
        int max_reprovacoes = -1;
        
        int m = semestres_lidos[i].m;
        int codigos_max_reprovacoes[m];
        int count_codigos = 0;

        printf("%d/%d\n", semestres_lidos[i].ano, semestres_lidos[i].semestre);

        for (int j = 0; j < m; j++) {
            int matriculados = semestres_lidos[i].disciplinas[j].matriculados;
            int aprovados = semestres_lidos[i].disciplinas[j].aprovados;
            int codigo = semestres_lidos[i].disciplinas[j].codigo;
            
            int reprovacoes = matriculados - aprovados;

            if (reprovacoes > max_reprovacoes) {
                max_reprovacoes = reprovacoes;
                count_codigos = 0;
                codigos_max_reprovacoes[count_codigos++] = codigo;
            } else if (reprovacoes == max_reprovacoes) {
                codigos_max_reprovacoes[count_codigos++] = codigo;
            }
        }
        
        qsort(codigos_max_reprovacoes, count_codigos, sizeof(int), compararInteiros);

        for (int j = 0; j < count_codigos; j++) {
            printf("%d ", codigos_max_reprovacoes[j]);
        }
        
        printf("\n\n");
    }

    return 0;
}