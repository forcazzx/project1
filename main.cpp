//试验用
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <fstream>
#include "matrixmultiply.h"

using namespace Eigen;
using namespace std;
//using namespace std;
#define PI 3.141592653589793
typedef struct Phi{
    Matrix3d a,b;
    double c=1;
}Phi;
typedef struct ImuRaw {
    double sow;       /* s */
    double dtheta[3]; /* 陀螺, rad */
    double dvel[3];   /* 加表, m/s */
} ImuRaw;
int main() {
    double d=200*1.0e-6;
    std::cout << d << std::endl;
    Matrix3d identity = Matrix3d::Identity();
    Matrix3d zero=Matrix3d::Zero();

//    //条件断点的使用
//    int i=0;
//    for(i=0;i<10;i++){
//        cout<<i<<endl;
//    }

//    //结构体赋值
//    Matrix3d a,b;
//    Vector3d vec={3,1,2};
//    std::cout << vec << std::endl;
//    b<<0,1,2,4,5,6,7,8,9;
//    Phi phi;
//    phi={a,b};
//    std::cout << phi.a << std::endl<< std::endl;
//    std::cout << phi.b << std::endl<< std::endl;
//    std::cout << phi.c << std::endl<< std::endl;

//    //矩阵块赋值
//    Vector3d eulerAngle(PI/3,PI/4,PI/5);
//    Matrix<double, 4, 4> temp_1;
//    temp_1<<a,vec,vec.transpose(),0;
//    Matrix<double, 6, 6> temp_2;
//    temp_2<<a.transpose(),zero.transpose(),identity.transpose(),b.transpose();
//    std::cout << temp_1 << std::endl<< std::endl;
//    std::cout << temp_2 << std::endl<< std::endl;

    //换算
    double D2R=0.017453292519943295;
    double h=12.0/3600;
    printf("%.18lf\n",h*D2R);
//    std::cout<<std::fixed<<setprecision(18)<<h*D2R<<std::endl;

//    //四元数赋值
//    Vector3d vec1;
//    Matrix <double,4,1> mat;
//    vec1={1,2,3};
//    mat<<vec1,4;
//    Quaterniond q(mat);
//    std::cout << q.coeffs()<< std::endl<< std::endl;

    return 0;
}