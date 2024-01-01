//
// Created by joao-victor-oliveira on 01/12/23.
//

#ifndef NUMERICAL_LINEAR_SYSTEM_SOLVERS_KACZMARZ_METHOD_H
#define NUMERICAL_LINEAR_SYSTEM_SOLVERS_KACZMARZ_METHOD_H

#pragma once

#include "includes.h"

void kaczmarz_method(real *A, real *B, real *X, size_t column_A, size_t lines, size_t max_iter);

void randomized_kaczmarz_method(real *A, real *B, real *X, size_t column_A, size_t lines, size_t max_iter);

#endif  // NUMERICAL_LINEAR_SYSTEM_SOLVERS_KACZMARZ_METHOD_H
