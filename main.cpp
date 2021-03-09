//试验用
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "lib.h"
#include <Eigen/Geometry>
#include <Eigen/Core>
#include <absl/strings/str_format.h>
#include <opencv2/opencv.hpp>
#include "matrixmultiply.h"
#include <cmath>

using namespace Eigen;
using namespace std;
#define PI 3.141592653589793
/* make sure the memory is successive */
#pragma pack(2)
struct test {
    double sow;       /* s */
    double dtheta[3]; /* 陀螺, rad */
    double dvel[3];   /* 加表, m/s */
};

int main(int argc, char *argv[]){
    //变量规则
    std::cout<<totalc<<endl;
    change();
    std::cout<<num()<<endl;
    std::cout<<totalc<<endl;

    //test cmake
    printzzx();
    string out;
    out = absl::StrFormat("absl_ok\n");
    cout << out;
    cout << CV_VERSION << endl;

    //结构体赋值
    Vector2d vec1={1,2},vec2,vec3;
    vec2<<4,5;
    vec3<<7,8;
    Matrix <double,3,3> mat;
    mat<<vec1,vec2,vec3,
            3,   6,   9;
    cout << mat << endl;

    //带参数的main
    if (argc == 3){
        double base = atof(argv[1]);
        int exponent = atoi(argv[2]);
        double result = pow(base, exponent);
        printf("%g ^ %d is %g\n", base, exponent, result);
    }

    //systime2sow
    int64_t time;
    time=getCurrentLocalTimeStamp();
    time=time-3*24*3600*1000;
    time=time%(7*24*3600*1000);
    double sow=time;
    sow=18+sow/1000;
    printf("%.3f\n",sow);

    //UTC2SOW
    int weekNo;
    double secondOfweek;
    UTC2SOW(2021,3,9,20,15,30,&weekNo,&secondOfweek);
    std::cout<<weekNo<<std::endl;
    std::cout<<secondOfweek<<std::endl;

    return 0;
}