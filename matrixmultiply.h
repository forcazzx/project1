//
// Created by zzx on 2019/10/25.
//

#ifndef PROJECT1_MATRIXMULTIPLY_H
#define PROJECT1_MATRIXMULTIPLY_H

#include <Eigen/Geometry>
#include <iostream>
using namespace Eigen;
using namespace std;
#define N 10
static int c;
void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3);
Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2);
int num(void);
void change(void);
int64_t getCurrentLocalTimeStamp(void);
int kbhit();
int readch();
void init_keyboard();
void close_keyboard();

//void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3)
//{
//    *matrix3=matrix*matrix2;
//}
//Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2)
//{
//    return matrix*matrix2;
//}
#endif //PROJECT1_MATRIXMULTIPLY_H
