//duzenlenecek...

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR_A 2
#define SUTUN_A 3
#define SATIR_B 3
#define SUTUN_B 2

void matrisADoldur(int matris[][SUTUN_A], int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < SUTUN_A; j++) {
            matris[i][j] = (rand() % 100) + 1;
        }
    }
}
void matrisBDoldur(int matris[][SUTUN_B], int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < SUTUN_B; j++) {
            matris[i][j] = (rand() % 100) + 1;
        }
    }
}
void matrisAYazdir(int matris[][SUTUN_A], int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < SUTUN_A; j++) {
            printf("%5d ", matris[i][j]);
        }
        printf("\n");
    }
}
void matrisBYazdir(int matris[][SUTUN_B], int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < SUTUN_B; j++) {
            printf("%5d ", matris[i][j]);
        }
        printf("\n");
    }
}
void matrisCYazdir(int matris[][SUTUN_B], int satirSayisi) {
    int i, j;
    for (i = 0; i < satirSayisi; i++) {
        for (j = 0; j < SUTUN_B; j++) {
            printf("%5d ", matris[i][j]);
        }
        printf("\n");
    }
}
void carpMatris(int A[][SUTUN_A], int B[][SUTUN_B], int sonuc[][SUTUN_B]) {
    int i, j, k;
    for (i = 0; i < SATIR_A; i++) {
        for (j = 0; j < SUTUN_B; j++) {
            sonuc[i][j] = 0;
            for (k = 0; k < SUTUN_A; k++) {
                sonuc[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
int main() {
    srand(time(NULL));

    int A[SATIR_A][SUTUN_A];
    int B[SATIR_B][SUTUN_B];
    int C[SATIR_A][SUTUN_B];
    int i, j;

    matrisADoldur(A, SATIR_A);
    matrisBDoldur(B, SATIR_B);

    printf("Matris A:\n");
    matrisAYazdir(A, SATIR_A);

    printf("\nMatris B:\n");
    matrisBYazdir(B, SATIR_B);

    printf("\nToplama islemi yapilamaz\n");

    carpMatris(A, B, C);
    printf("\nA * B Sonucu:\n");
    matrisCYazdir(C, SATIR_A);

    return 0;
}
