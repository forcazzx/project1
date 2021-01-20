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
static int totalc=1;
int num(void);
void change(void);
int64_t getCurrentLocalTimeStamp(void);
void UTC2SOW(int year, int month, int day, int hour, int minute, double second, int *weekNo, double *secondOfweek);

#endif //PROJECT1_MATRIXMULTIPLY_H
