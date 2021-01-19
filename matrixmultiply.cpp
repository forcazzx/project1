//
// Created by zzx on 2019/10/25.
//
#include <chrono>
#include "matrixmultiply.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
int a=1;

int num(void){
    std::cout<<c<<endl;
}
void change(void){
    a=N;
    c=2;
    extern int b;
    std::cout<<a<<endl;
    std::cout<<b<<endl;
}
void multiply(Matrix3d matrix,Matrix3d matrix2,Matrix3d* matrix3)
{
    *matrix3=matrix*matrix2;
}
Matrix3d multiply2(Matrix3d matrix,Matrix3d matrix2)
{
    return matrix*matrix2;
}
// get current local time stamp
int64_t getCurrentLocalTimeStamp()
{
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    return tmp.count();

    // return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}



static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void);
void init_keyboard()
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag |= ICANON;
    new_settings.c_lflag |= ECHO;
    new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit()
{
    unsigned char ch;
    int nread;

    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch()
{
    char ch;

    if(peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}

