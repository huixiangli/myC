/****************************************
*二分法计算程序
*代码翻译自高一B版数学教材
*made by huixiang_li , 2020/10/24 , v1.0
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000    //宏定义 最大计算次数

double fun( double x ){    //函数
    double y;
    y=x*x*x-3;    //函数表达式
    return y;
}

int main()
{
    double a,b,e=0.00000001,m=0;
    double x;
    int n=0;//次数
    a=0;    //左端点
    b=64;    //右端点
    e=e*2;    //倍增 优化计算速度
    for ( n=1 ; n<=N ; n++){    //循环体
        if ( a-b <= e && a-b >= -e) //是否达到精度
            break;    //结束循环
        else{
            m = (a+b)/2;    //中点值
            if (fun(m) == 0)
                break;
            else{
                if ( fun(a)*fun(m) < 0 )    //异号判定
                    b = m;
                else{
                    a = m;
                }
            }
        }
        //printf("%08f %08f \n",a,b);
        printf("x%d = %08f y%d = %08f\n",n,m,n,fun(m));    //阶段输出
    }
    printf("\n\nx = %08f\ny = %08f\n\n",m,fun(m));    //输出
    system("pause");
    return 0;
}
