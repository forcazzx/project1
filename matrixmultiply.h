//
// Created by zzx on 2019/10/25.
//

#ifndef PROJECT1_MATRIXMULTIPLY_H
#define PROJECT1_MATRIXMULTIPLY_H

#include <Eigen/Geometry>
using namespace Eigen;

void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3);
Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2);

//void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3)
//{
//    *matrix3=matrix*matrix2;
//}
//Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2)
//{
//    return matrix*matrix2;
//}
#endif //PROJECT1_MATRIXMULTIPLY_H
