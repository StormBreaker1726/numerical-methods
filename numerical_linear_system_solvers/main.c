//
// Created by joao-victor-oliveira on 01/12/23.
//

#include "includes.h"
#include "kaczmarz_method.h"

#define lines   5
#define columns 5

int main(void)
{
    real *A        = (real *)malloc((lines * columns) * sizeof(real));
    real *B        = (real *)malloc(lines * sizeof(real));
    real *X        = (real *)malloc(lines * sizeof(real));
    real *X_random = (real *)malloc(lines * sizeof(real));

    A[0] = -1.00;
    A[1] = -3.00;
    A[2] = 1.00;
    A[3] = 9.00;
    A[4] = 1.00;

    A[5] = -4.76;
    A[6] = 2.15;
    A[7] = 1.00;
    A[8] = 1.00;
    A[9] = 0.00;

    A[10] = 10.00;
    A[11] = 10.00;
    A[12] = 12.34;
    A[13] = 8.65;
    A[14] = 1.65;

    A[15] = 1.23;
    A[16] = -2.00;
    A[17] = -1.00;
    A[18] = 1.00;
    A[19] = -0.987;

    A[20] = 1.00;
    A[21] = 1.00;
    A[22] = 0.00;
    A[23] = -4.75;
    A[24] = 1.00;

    B[0] = 25.00;
    B[1] = 1.785;
    B[2] = 0.00;
    B[3] = -1.56;
    B[4] = -21.00;

    size_t max_iter = pow(10, 6);

    clock_t start = clock();
    kaczmarz_method(A, B, X, columns, lines, max_iter);
    clock_t end = clock();

    clock_t start_random = clock();
    randomized_kaczmarz_method(A, B, X_random, columns, lines, max_iter);
    clock_t end_random = clock();

    if (X == NULL)
        printf("X ainda é null\n");

    for (int i = 0; i < lines; ++i)
    {
        printf("X[%d] = %.5f\n", i, X[i]);
        printf("X_random[%d] = %.5f\n\n", i, X_random[i]);
    }

    real random_time = (real)(end_random - start_random) / CLOCKS_PER_SEC;
    real time        = (real)(end - start) / CLOCKS_PER_SEC;

    printf("Time to solve with usual method      = %.5e\n", time);
    printf("Time to solve with randomized method = %.5e\n", random_time);

    free(A);
    free(B);
    free(X);
    free(X_random);

    return 0;
}