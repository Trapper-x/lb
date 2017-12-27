//
//  lab08.cpp
//  lab08
//
//  Created by Alexey Kolesnik on 17/11/2017.
//  Copyright © 2017 Alexey Kolesnik. All rights reserved.
//

#include "iu_strings.hpp"
#include "matrix.hpp"

using namespace std;

// 1

char* stringCopy(const char* str) {
    auto strCopy = new char [strlen(str) + 1];
    strcpy(strCopy, str);
    return strCopy;
}

// 2

char* stringConcatinate(const char* str1, const char* str2) {
    auto newString = new char [strlen(str1) + strlen(str2) + 1];
    strcpy(newString, str1);
    strcat(newString, str2);
    return newString;
}

// 3

Matrix newMatrix(const int n, const int m) {
    auto matrix = new float* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new float[m];
        memset(matrix[i], 0, n*sizeof(matrix[0]));
    }
    
    Matrix mt {matrix, n, m};
    return mt;
}

// 4

void deleteMatrix(Matrix& m) {
    float ** matrix = m.matrix;
    
    for (int i = 0; i < m.n; ++i) {
        delete[] matrix[i];
    }
    delete matrix;
    
    m.matrix = nullptr;
    m.n = 0;
    m.m = 0;
}

// 5

// 6

Matrix copy(const Matrix& mt) {
    Matrix matrix = newMatrix(mt.n, mt.m);
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            matrix.matrix[i][j] = mt.matrix[i][j];
        }
    }
    return matrix;
}

// 7

Matrix transpose(const Matrix& mt) {
    auto cpMatr = copy(mt);
    for (int i = 0; i < mt.n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            swap(cpMatr.matrix[i][j], cpMatr.matrix[j][i]);
        }
    }
    return cpMatr;
}

// 8

// 9



// 10

Matrix ones(int n) {
    auto matrix = new float* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new float[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    Matrix mt {matrix, n, n};
    return mt;
}

// 11

Matrix operator* (const Matrix& mt1, const Matrix& mt2) {
    auto matrix = newMatrix(mt1.n, mt1.m);
    for (auto i = 0; i < mt1.n; ++i) {
        for (auto j = 0; j < mt2.m; ++j) {
            matrix.matrix[j][i] = (mt1.matrix[i][j] * mt2.matrix[i][j]) +
                                  (mt1.matrix[i + 1][j] * mt2.matrix[i][j + 1]) +
                                  (mt1.matrix[i + 2][j] * mt2.matrix[i][j + 2]);
        }
    }
    return matrix;
}

// 12

bool operator==(const Matrix& mt1, const Matrix& mt2) {
    if ((mt1.n != mt2.n) && (mt1.m != mt2.m)) {
        return false;
    }
    bool equal = true;
    for (int i = 0; i < mt1.n; ++i) {
        for (int j = 0; j < mt1.m; ++j) {
            if (mt1.matrix[i][j] != mt2.matrix[i][j]) {
                equal = false;
            }
        }
    }
    return equal;
}



