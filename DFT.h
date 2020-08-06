/* Discrete Fourier Transform By lihuixiang0518@hotmail.com on 06-08-2020 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979			//定义pi酱

int DFT(double *input , int length ,			//输入数据及长度
		double *output_re , double *output_im ,	//输出数据的虚实两部
		int startFs , int endFs ){				//起-终
	
    int n = 0 , k = 0;
	double temporary = 0.0;						//临时容器

	for ( n=0 ; n<length ; n++ ){				//初始化归零
		*(output_re+n) = 0.0;
		*(output_im+n) = 0.0;
	}

	for ( k=startFs ; k<=endFs ; k++ ){			//主体计算
		for ( n=0 ; n<length ; n++ ){
			temporary = -2 * pi * (double)k * (double)n / (double)length;
			*(output_re+LENGTH-1-k) = *(output_re+LENGTH-1-k) + *(input+n) * cos(temporary);
			*(output_im+LENGTH-1-k) = *(output_im+LENGTH-1-k) + *(input+n) * sin(temporary);
		}
	}

	return 0;									//返回零值，结束函数
}

/*
int LENGTH = 1024;
int main (){
	double x[LENGTH],y[LENGTH];
	double re[LENGTH],im[LENGTH];
	int n=0;
	for (n=0;n<LENGTH;n++){
		x[n]=(double)n/LENGTH;//x=>[0,1)
		y[n]=sin(x[n]*2*pi*440)+3*sin(x[n]*2*pi*364)-sin(x[n]*2*pi*880);
	}
	fft(y,LENGTH,re,im,1,LENGTH);
	for (n=0;n<LENGTH;n++){
		printf("%g,",re[n]);
	}
	system("pause");
    return 0;
}
*/