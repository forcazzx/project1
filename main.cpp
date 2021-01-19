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

//    //转换float数据到字节数组
//    unsigned char i;
//    float floatVariable=1.1;
//    unsigned char charArray[4];
//    unsigned char *pdata = (unsigned char*)&floatVariable;  //把float类型的指针强制转换为unsigned char型
//    for(i=0;i<4;i++)
//    {
//        charArray[i] = *pdata++;//把相应地址中的数据保存到unsigned char数组中
//    }
//    //转换字节数组到float数据
//    float floatVariable2;
//    long test=(long) charArray;
//    floatVariable2=*((float*) test);
//    cout<<floatVariable<<','<<floatVariable2<<endl;
//
//    double data[3]={1.1,2.2,3.3},rddata[3];
//    long startAddress=(long) data;
//    FLASH_Read(&startAddress,rddata,3);
//    cout<<&rddata[0]<<','<<&rddata[1]<<','<<&rddata[2]<<endl;

//    int i=0,j=0,count=2;
//    long long int rd=0;
//    double writeData[2]={1.1,2.2},readData[2];
//    char data[2*8],temp;
//    int startAddress=0,readAddress=0;
//    for(i=0;i<count;i++){
//        data[startAddress]=writeData[i];
//        startAddress++;
//    }

//    readAddress=startAddress-2;
//    for(i=0;i<count;i++){
//        for(j=0;j<8;j++){
//            rd=(rd<<8)+data[readAddress+7-j+i*1];
//        }
//        readData[i]=rd;
//    }
//    cout<<data[0]<<','<<data[1]<<endl;

//    //条件断点的使用
//    int i=0;
//    for(i=0;i<10;i++){
//        cout<<i<<endl;
//    }

    //结构体赋值
//    Phi phi;
//    std::cout << sizeof(phi) << std::endl;

//    int64_t time;
//    time=getCurrentLocalTimeStamp();
//    time=time-3*24*3600*1000;
//    time=time%(7*24*3600*1000);
//    double sow=time;
//    sow=18+sow/1000;
//    printf("%.3f\n",sow);
//    char buff[100];
//    sprintf(buff,"/home/zzx/Downloads/%ld.txt",time);
//    ofstream offile;
//    offile.open(buff);



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

    ifstream file,file1;
    ofstream pfile,pfile1,pfile2,pfilebin;
    char i300data[32];
    uint16_t check[16];
    uint16_t checksum=0;
    uint8_t byte;
    int64_t i=0,datanum=0,validnum=0,err=0,ok=0;
    file.open("/home/zzx/cutecom.bin",ifstream::binary);
    while(!file.eof()){
        file.read((char*)&byte,1);
        if(i==0){
            if(byte==0x0E)
                i300data[i++]=byte;
            else{
                if(datanum!=validnum)
                    err++;
                datanum=validnum;
            }
        }
        else if(i==1){
            if(byte==0xA3)
                i300data[i++]=byte;
            else{
                i=0;
                err++;
            }
        }
        else if(i<32){
            i300data[i++]=byte;
        }
        if(i==32){
            i=0;
            validnum++;
            memcpy(check,i300data,sizeof(check));
            for(int j=0;j<15;j++){
                checksum+=check[j];
            }
            if(checksum==check[15])
                ok++;
        }
    }
    printf("%ld_%ld\n",validnum,err);
    printf("%ld\n",ok);

    //换算
//    double D2R=0.017453292519943295;
//    double h=12.0/3600;
//    printf("%.18lf\n",h*D2R);
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