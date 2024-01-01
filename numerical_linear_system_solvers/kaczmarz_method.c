//
// Created by joao-victor-oliveira on 01/12/23.
//

#include "kaczmarz_method.h"

real dot(const real *a, const real *b, size_t n)
{
    real result = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        result += a[i] * b[i];
    }
    return result;
}

void kaczmarz_method(real *A, real *B, real *X, size_t column_A, size_t lines, size_t max_iter)
{
    if (X == NULL)
    {
        printf("X array is a pointer to a null position\n");
        return;
    }
    if (A == NULL || B == NULL)
    {
        printf("Matrix A or B is a pointer to a null position\n");
        return;
    }

    for (size_t i = 0; i < lines; ++i)
    {
        X[i] = 0.0;
    }

    for (size_t iter = 0; iter < max_iter; ++iter)
    {
        for (size_t i = 0; i < lines; ++i)
        {
            real *ai = (real *)malloc(column_A * sizeof(real));
            for (size_t j = 0; j < column_A; ++j)
            {
                ai[j] = A[i * column_A + j];
            }

            real dot_aix = dot(ai, X, lines);

            real alpha = (B[i] - dot_aix) / (dot(ai, ai, lines));

            for (size_t j = 0; j < lines; ++j)
            {
                X[j] += alpha * A[i * column_A + j];
            }
        }
    }
}

void randomized_kaczmarz_method(real *A, real *B, real *X, size_t column_A, size_t lines, size_t max_iter)
{
    if (X == NULL)
    {
        printf("X array is a pointer to a null position\n");
        return;
    }
    if (A == NULL || B == NULL)
    {
        printf("Matrix A or B is a pointer to a null position\n");
        return;
    }

    for (size_t i = 0; i < lines; ++i)
    {
        X[i] = 0.0;
    }
    unsigned int seed = 2 * time(NULL) / 3 * time(NULL);
    tinymt64_t   prng;
    tinymt64_init(&prng, seed);
    for (size_t iter = 0; iter < max_iter; ++iter)
    {
        unsigned int i  = 0 + tinymt64_generate_uint64(&prng) % lines;
        real        *ai = (real *)malloc(column_A * sizeof(real));
        for (size_t j = 0; j < column_A; ++j)
        {
            ai[j] = A[i * column_A + j];
        }

        real dot_aix = dot(ai, X, lines);

        real alpha = (B[i] - dot_aix) / (dot(ai, ai, lines));

        for (size_t j = 0; j < lines; ++j)
        {
            X[j] += alpha * A[i * column_A + j];
        }
    }
}