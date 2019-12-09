//
// Created by zzx on 2019/10/25.
//
#include "matrixmultiply.h"
void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3)
{
    *matrix3=matrix*matrix2;
}
Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2)
{
    return matrix*matrix2;
}
