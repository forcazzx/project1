#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

#include "matrixmultiply.h"

using namespace Eigen;
#define PI 3.141592653589793
void euler2dcm(const Vector3d &eulerAngle, Matrix3d &dcm)
{
    Eigen::AngleAxisd rollAngle(AngleAxisd(eulerAngle(0),Vector3d::UnitX()));
    Eigen::AngleAxisd pitchAngle(AngleAxisd(eulerAngle(1),Vector3d::UnitY()));
    Eigen::AngleAxisd yawAngle(AngleAxisd(eulerAngle(2),Vector3d::UnitZ()));

    Eigen::AngleAxisd rotation_vector;
    rotation_vector=yawAngle*pitchAngle*rollAngle;

    dcm=rotation_vector.matrix();
}
void euler2quat(const Vector3d &eulerAngle,Quaterniond &quaternion)
{
    Matrix3d dcm;
    euler2dcm(eulerAngle,dcm);
    quaternion=dcm;
}
void dcm2euler(const Matrix3d &dcm,Vector3d &eulerAngle)
{
    eulerAngle(0)=atan(dcm(2,1)/dcm(2,2));
    eulerAngle(1)=atan(-dcm(2,0)/sqrt(dcm(2,1)*dcm(2,1)+dcm(2,2)*dcm(2,2)));
    eulerAngle(2)=atan(dcm(1,0)/dcm(0,0));
}
void dcm2quat(const Matrix3d &dcm,Quaterniond &quaternion)
{
    quaternion=dcm;
}
void quat2euler(const Quaterniond &quaternion,Vector3d &eulerAngle)
{
    dcm2euler(quaternion.matrix(),eulerAngle);
}
void quat2dcm(const Quaterniond &quaternion,Matrix3d &dcm)
{
    dcm=quaternion.matrix();
}
void e2q(const Vector3d &eulerAngle,Quaterniond &quaternion)
{
    double x=eulerAngle(0)/2;
    double y=eulerAngle(1)/2;
    double z=eulerAngle(2)/2;
    quaternion.w()=cos(x)*cos(y)*cos(z)+sin(x)*sin(y)*sin(z);
    quaternion.x()=sin(x)*cos(y)*cos(z)-cos(x)*sin(y)*sin(z);
    quaternion.y()=cos(x)*sin(y)*cos(z)+sin(x)*cos(y)*sin(z);
    quaternion.z()=cos(x)*cos(y)*sin(z)-sin(x)*sin(y)*cos(z);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    Matrix3d a,b;
    a<<1,2,3,4,5,6,7,8,9;
    b<<1,1,1,1,1,1,1,1,1;
    std::cout << b*a << std::endl;

    Vector3d eulerAngle(PI/3,PI/4,PI/5);
    Matrix<double, 4, 1> temp_1;
    temp_1<<1,1,1,1;

    Matrix3d dcm;
    Quaterniond quaternion;
    AngleAxisd rotvec;
    Vector3d euler;
    quaternion=temp_1;
    quaternion.normalize();

//    euler2dcm (eulerAngle,dcm);
//    euler2quat(eulerAngle,quaternion);
//    dcm2euler(dcm,euler);
//    dcm2quat(dcm,quaternion);
    quat2euler(quaternion,euler);
    quat2dcm(quaternion,dcm);
    rotvec=quaternion;
//    quaternion.x()=0.191342;
//    quaternion.y()=0.46194;
//    quaternion.z()=0.191342;
//    quaternion.w()=0.844623;
//    dcm=quaternion.matrix();
//    rotvec=quaternion;
    std::cout << dcm << std::endl << std::endl;
    std::cout << quaternion.coeffs() << std::endl << std::endl;
    std::cout << -euler << std::endl << std::endl;
    std::cout << cos(180)<<std::endl;

//    //Quaterniond qnn;
//    Vector3d temp1(1,2,3);
//    Vector3d temp2;
//    Vector3d temp3;
//    Matrix<double, 4, 1> temp_1;
//    //temp1<<1,2,3;
//    temp2<<1,2,3;
//    temp3=temp1.cross(temp2);
//    temp_1<<0,temp1;
//    Quaterniond qnn(temp_1);
//    //Quaterniond qnn(0,temp1(0),temp1(1),temp1(2));
//    std::cout << temp1 << std::endl << std::endl;
//    std::cout << temp3 << std::endl << std::endl;
//    std::cout << qnn.coeffs() << std::endl << std::endl;

    return 0;
}