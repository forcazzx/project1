//试验用
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <fstream>
#include "matrixmultiply.h"
#include <time.h>
#include <chrono>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

using namespace Eigen;
using namespace std;
#define PI 3.141592653589793
int b=1;
/* make sure the memory is successive */
#pragma pack(2)
typedef struct ImuRaw {
    double sow;       /* s */
    double dtheta[3]; /* 陀螺, rad */
    double dvel[3];   /* 加表, m/s */
} ImuRaw;
typedef struct Phi{
    u8     head1;    /* 数据头0x55 */
    u8     head2;    /* 数据头0xAA */
    u16    week;     /* GPS周 */
    double sow;      /* GPS周内秒,s */
    double systime;  /*系统时间*/
    double lat;      /* 纬度,deg */
    double lon;      /* 经度,deg */
    float  alt;      /* 椭球高,m */
    float  velnorth; /* 北向速度,m/s */
    float  veleast;  /* 东向速度,m/s */
    float  veldown;  /* 地向速度,m/s */
    float  roll;     /* 横滚角,deg */
    float  pitch;    /* 俯仰角,deg */
    float  yaw;      /* 航向角,deg */
    u8     navmode;  /* 导航模式,0-纯惯导,1-SPP松组合,2-FLOAT松组合,3-FIXED松组合 */
    u8     flag;     /* 后续速度标志,0-终止数据,1-IMU数据,2-GNSS数据 */
    /* 标准数据包68字节 */

    float imubias[6];
    /* 加IMU零偏92字节 */

    float imuscale[6];
    /* 加IMU比例因子116字节 */

    u8 check1; /* 校验和 */
    u8 check2; /* 校验和 */
}Phi;
static void FLASH_Read(long *startAddress,double *readData,uint16_t count){
    int i=0;
    double *pf;
    pf=(double*)(*startAddress);
    for(i=0;i<count;i++){
        readData[i]=*pf;
        pf++;
    }
}
void euler2dcm(const Vector3d &eulerAngle, Matrix3d &dcm) {
    Eigen::AngleAxisd rollAngle(AngleAxisd(eulerAngle(0), Vector3d::UnitX()));
    Eigen::AngleAxisd pitchAngle(AngleAxisd(eulerAngle(1), Vector3d::UnitY()));
    Eigen::AngleAxisd yawAngle(AngleAxisd(eulerAngle(2), Vector3d::UnitZ()));

    Eigen::AngleAxisd rotation_vector;
    rotation_vector = yawAngle * pitchAngle * rollAngle;

    dcm = rotation_vector.matrix();
}
int main() {
//    int a=0;
//    b=2;
//    change();
//    a=num();
//    std::cout<<a+N<<endl;
//    std::cout<<c<<endl;


//    //条件断点的使用
//    int i=0;
//    for(i=0;i<10;i++){
//        cout<<i<<endl;
//    }

    ifstream iferror;
    double start=357759.9,T=180;
    iferror.open("/mnt/Storage/FileRecv/Navigation/组合导航数据处理/20210114车载/result/B/LC_OUTAGE60S_TXT.err");
    double poserr[3],t,velerr[3],atterr[3];
    double posmaxrms[3]={0},attmaxrms[3]={0},posmaxmax=0,plane;
    int num = 0;
    while(!iferror.eof()){
        iferror>>t>>poserr[0]>>poserr[1]>>poserr[2]>>velerr[0]>>velerr[1]>>velerr[2]>>atterr[0]>>atterr[1]>>atterr[2];
        if(t==start){
            num++;
            start+=T;
            posmaxrms[0]+=poserr[0]*poserr[0];
            posmaxrms[1]+=poserr[1]*poserr[1];
            posmaxrms[2]+=poserr[2]*poserr[2];
            attmaxrms[0]+=atterr[0]*atterr[0];
            attmaxrms[1]+=atterr[1]*atterr[1];
            attmaxrms[2]+=atterr[2]*atterr[2];
            plane=sqrt((poserr[0]*poserr[0]+poserr[1]*poserr[1])/2);
            if(plane>posmaxmax)
                posmaxmax=plane;
        }
    }
    posmaxrms[0]=sqrt(posmaxrms[0]/N);
    posmaxrms[1]=sqrt(posmaxrms[1]/N);
    posmaxrms[2]=sqrt(posmaxrms[2]/N);
    attmaxrms[0]=sqrt(attmaxrms[0]/N);
    attmaxrms[1]=sqrt(attmaxrms[1]/N);
    attmaxrms[2]=sqrt(attmaxrms[2]/N);
    printf("%.6f\n%.6f\n%.6f\n%.6f\n%.6f\n%.6f\n%.6f\n\n",
           posmaxrms[0],posmaxrms[1],posmaxrms[2],attmaxrms[0],attmaxrms[1],attmaxrms[2],posmaxmax);

    //systime2sow
//    int64_t time;
//    time=getCurrentLocalTimeStamp();
//    time=time-3*24*3600*1000;
//    time=time%(7*24*3600*1000);
//    double sow=time;
//    sow=18+sow/1000;
//    printf("%.3f\n",sow);

    //UTC2SOW
//    int weekNo;
//    double secondOfweek;
//    UTC2SOW(2019,4,28,0,0,0,&weekNo,&secondOfweek);
//    std::cout<<weekNo<<std::endl;
//    std::cout<<secondOfweek<<std::endl;

    //结构体赋值
//    Phi phi;
//    std::cout << sizeof(phi) << std::endl;

    //矩阵块赋值
//    Matrix3d A3;
//    A3<<1,2,3,4,5,6,7,8,10;
//    Vector3d B1,B2,B3,B4;
//    B1<<1,4,7;
//    B2<<2,5,8;
//    B3<<3,6,10;
//    B4<<0,0,0;
//    Matrix4d A4;
//    double x=2;
//    A4<<A3,B4,
//        0,0,0,x;
//    cout<<A3.inverse()<<endl;
//    cout<<A4.inverse()<<endl;

//    //四元数赋值
//    Vector3d vec1;
//    Matrix <double,4,1> mat;
//    vec1={1,2,3};
//    mat<<vec1,4;
//    Quaterniond q(mat);
//    std::cout << q.coeffs()<< std::endl<< std::endl;

    return 0;
}