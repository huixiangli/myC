/****************************************
*���ַ��������
*���뷭���Ը�һB����ѧ�̲�
*made by huixiang_li , 2020/10/24 , v1.0
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1000    //�궨�� ���������

double fun( double x ){    //����
    double y;
    y=x*x*x-3;    //�������ʽ
    return y;
}

int main()
{
    double a,b,e=0.00000001,m=0;
    double x;
    int n=0;//����
    a=0;    //��˵�
    b=64;    //�Ҷ˵�
    e=e*2;    //���� �Ż������ٶ�
    for ( n=1 ; n<=N ; n++){    //ѭ����
        if ( a-b <= e && a-b >= -e) //�Ƿ�ﵽ����
            break;    //����ѭ��
        else{
            m = (a+b)/2;    //�е�ֵ
            if (fun(m) == 0)
                break;
            else{
                if ( fun(a)*fun(m) < 0 )    //����ж�
                    b = m;
                else{
                    a = m;
                }
            }
        }
        //printf("%08f %08f \n",a,b);
        printf("x%d = %08f y%d = %08f\n",n,m,n,fun(m));    //�׶����
    }
    printf("\n\nx = %08f\ny = %08f\n\n",m,fun(m));    //���
    system("pause");
    return 0;
}
