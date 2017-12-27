//
//  main.cpp
//  lab08
//
//  Created by Alexey Kolesnik on 17/11/2017.
//  Copyright © 2017 Alexey Kolesnik. All rights reserved.
//

#include <iostream>

#include "iu_strings.hpp"
#include "matrix.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    const char * p = "some string";
    char * newString = stringCopy(p);
    std::cout << p << std::endl;
    std::cout << newString << std::endl;
    //
    const char * p1 = "Hello,";
    const char * p2 = " world!";
    char * newString1 = stringConcatinate(p, p1);
    //
    int n = 10;
    int m = 10;
    Matrix matrix = newMatrix(n, m);
    //
    int n1 = 10;
    int m1 = 15;
    Matrix matrix1 = newMatrix(n1, m1);
    deleteMatrix(matrix1);
    bool b = matrix1.matrix == nullptr;
    //
    int n2 = 10;
    int m2 = 15;
    Matrix matrix2 = newMatrix(n2, m2);
    snake(matrix2);
    deleteMatrix(matrix2);
    //
    int n3 = 10;
    int m3 = 10;
    Matrix matrixA = newMatrix(n3, m3);
// ...
    Matrix matrixB = copy(matrixA);
    deleteMatrix(matrixA);
    deleteMatrix(matrixB);
    //
    int n4 = 10;
    int m4 = 10;
    Matrix matrix4 = newMatrix(n4, m4);
// ...
    Matrix matrixT = transpose(matrix4);
    deleteMatrix(matrix);
    //
    int n5 = 10;
    Matrix matrix5 = newMatrix(n5, n5);
// ...
    Matrix inv = inverse(matrix5);
    deleteMatrix(matrix5);
    //
    int n6 = 10;
    int m6 = 10;
    Matrix matrix6 = newMatrix(n6, m6);
// ...
    float d = determinant(matrix6);
    deleteMatrix(matrix6);
    //
    int n7 = 10;
    int m7 = 10;
    Matrix matrix7 = ones(n7);
    float d1 = determinant(matrix7);
// d == 1
    deleteMatrix(matrix7);
    //
    int n8 = 10;
    int m8 = 10;
    int k = 10;
    Matrix matrixOne = newMatrix(n8, m8);
    Matrix matrixTwo = newMatrix(m8, k);
// ...
    Matrix matrixThree = matrixOne * matrixTwo;
// ...
    deleteMatrix(matrixOne);
    deleteMatrix(matrixTwo);
    deleteMatrix(matrixThree);
    //
    int n9 = 10;
    Matrix matrixOne1 = newMatrix(n9, n9);
    Matrix matrixTwo1 = newMatrix(n9, n9);
// ...
    bool d2 = (matrixOne1 == matrixTwo1);
    deleteMatrix(matrixOne1);
    deleteMatrix(matrixTwo1);
    return 0;
}
