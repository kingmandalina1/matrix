#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR_A 2
#define SUTUN_A 3
#define SATIR_B 3
#define SUTUN_B 2

void matrisDoldur(int* matris, int satir, int sutun) {
	int i,j;
    for ( i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            *(matris + i * sutun + j) = rand() % 100 + 1;
        }
    }
}

void matrisYazdir(int* matris, int satir, int sutun) {
	int i,j;
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            printf("%5d ", *(matris + i * sutun + j));
        }
        printf("\n");
    }
}

void matrisCarp(int A[][SUTUN_A], int B[][SUTUN_B], int C[][SUTUN_B]) {
	int i,j,k;
    for ( i = 0; i < SATIR_A; i++) {
        for (j = 0; j < SUTUN_B; j++) {
            C[i][j] = 0;
            for (k = 0; k < SUTUN_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int A[SATIR_A][SUTUN_A];
    int B[SATIR_B][SUTUN_B];
    int C[SATIR_A][SUTUN_B];

    matrisDoldur((int*)A, SATIR_A, SUTUN_A);
    matrisDoldur((int*)B, SATIR_B, SUTUN_B);

    printf("Matris A:\n");
    matrisYazdir((int*)A, SATIR_A, SUTUN_A);

    printf("\nMatris B:\n");
    matrisYazdir((int*)B, SATIR_B, SUTUN_B);

    printf("\nToplama islemi yapilamaz\n");

    matrisCarp(A, B, C);
    printf("\nA * B Sonucu:\n");
    matrisYazdir((int*)C, SATIR_A, SUTUN_B);

    return 0;
}

