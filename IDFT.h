/* Inverse Discrete Fourier Transform by lihuixiang0518@hotmail.com on 08-08-2020 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "DFT.hc"
#define pi 3.14159265358979					    //定义pi酱

int IDFT(double* input, int length,			//输入数据及长度
	double* output_re, double* output_im,	//输出数据的虚实两部
	int startt, int endt) {					      //起-终

	int n = 0, k = 0;
	double temporary = 0.0;					      //临时容器

	for (n = startt; n <= endt; n ++) {		//主体计算
		*(output_re + n) = 0.0;
		*(output_im + n) = 0.0;				      //初始化归零
		for (k = 0; k < length; k ++) {
			temporary = 2 * pi * (double)n * (double)k / (double)length;
			*(output_re + n) = *(output_re + n) + *(input + k) * cos(temporary);
			*(output_im + n) = *(output_im + n) + *(input + k) * sin(temporary);
		}
	}

	return 0;							              	//返回零值，结束函数
}
/*
*			 length
*x(n) = (1/N) sum  X(k)*(cos(2*pi*k*n/length)+i*sin(2*pi*k*n/length))		n=>[0,length).
*			  k=1
*/
/*
int LENGTH = 1024;
int main (){
	double x[LENGTH],y[LENGTH];
	double re[LENGTH],im[LENGTH],y_[LENGTH];
	int n=0;
	for (n=0;n<LENGTH;n++){
		x[n]=(double)n/LENGTH;//x=>[0,1)
		y[n]=sin(x[n]*2*pi*440);
	}
	DFT(y, LENGTH, re, im, 1, LENGTH);
	IDFT(re, LENGTH, y_, im, 1, LENGTH);
	for (n=0;n<LENGTH;n++){
		printf("%g,",y[n]);
	}
	system("pause");
	return 0;
}
*/
