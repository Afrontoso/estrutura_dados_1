#include <stdio.h>

int main() {
    int F, L;
    scanf("%d %d", &F, &L);

    char mapa[F][L];

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < L; j++) {
            mapa[i][j] = '-';
        }
    }

    char fileira;
    int lugar;

    while (scanf(" %c%d", &fileira, &lugar) == 2) {
        int indice_f = fileira - 'A';
        int indice_l = lugar - 1;

        if (indice_f >= 0 && indice_f < F && indice_l >= 0 && indice_l < L) {
            mapa[indice_f][indice_l] = 'X'; 
        }
    }

    printf("  "); 
    for (int j = 1; j <= L; j++) {
        printf("%02d ", j); 
    }
    printf("\n");

    for (int i = F - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);

        for (int j = 0; j < L; j++) {
            if (mapa[i][j] == 'X') {
                printf("XX ");
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }

    return 0;
}