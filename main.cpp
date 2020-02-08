#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <fstream>
#include "matrixmultiply.h"

using namespace Eigen;
using namespace std;
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
    ImuRaw imu;
    FILE *file;
    file = fopen("/media/zzx/STORAGE/FileRecv/Navigation/Lcdata/A15_imu.txt", "r");
    fread(&imu, sizeof(ImuRaw), 1, file);
    std::cout << sizeof(ImuRaw) << std::endl;
    fclose(file);

    std::cout << "Hello, World!" << std::endl;
    Phi phi;

    Matrix3d a,b;
    Vector3d vec={1,2,3};
    a=vec.asDiagonal();
    b<<0,1,2,4,5,6,7,8,9;
    Matrix3d identity = Matrix3d::Identity();
    Matrix3d zero=Matrix3d::Zero();

    phi={a,b};
    std::cout << phi.a << std::endl<< std::endl;
    std::cout << phi.b << std::endl<< std::endl;
    std::cout << phi.c << std::endl<< std::endl;

    Vector3d eulerAngle(PI/3,PI/4,PI/5);
    Matrix<double, 6, 6> temp_1;
    temp_1<<a,identity,zero,b;
    Matrix<double, 6, 6> temp_2;
    temp_2<<a.transpose(),zero.transpose(),identity.transpose(),b.transpose();
    std::cout << temp_1 << std::endl<< std::endl;
    std::cout << temp_2 << std::endl<< std::endl;

    double D2R=0.017453292519943295;
    double h=0.5/3600;
    printf("%.18lf\n",h*D2R);
//    std::cout<<std::fixed<<setprecision(18)<<h*D2R<<std::endl;

    Vector3d vec1;
    Matrix <double,4,1> mat;
    vec1={1,2,3};
    mat<<vec1,4;
    Quaterniond q(mat);
    std::cout << q.coeffs()<< std::endl<< std::endl;

    Vector3d I=Vector3d::Zero();
    std::cout << I << std::endl<< std::endl;

    return 0;
}