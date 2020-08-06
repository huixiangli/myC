/* Discrete Fourier Transform By lihuixiang0518@hotmail.com on 06-08-2020 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265358979			//����pi��

int DFT(double *input , int length ,			//�������ݼ�����
		double *output_re , double *output_im ,	//������ݵ���ʵ����
		int startFs , int endFs ){				//��-��
	
    int n = 0 , k = 0;
	double temporary = 0.0;						//��ʱ����

	for ( n=0 ; n<length ; n++ ){				//��ʼ������
		*(output_re+n) = 0.0;
		*(output_im+n) = 0.0;
	}

	for ( k=startFs ; k<=endFs ; k++ ){			//�������
		for ( n=0 ; n<length ; n++ ){
			temporary = -2 * pi * (double)k * (double)n / (double)length;
			*(output_re+LENGTH-1-k) = *(output_re+LENGTH-1-k) + *(input+n) * cos(temporary);
			*(output_im+LENGTH-1-k) = *(output_im+LENGTH-1-k) + *(input+n) * sin(temporary);
		}
	}

	return 0;									//������ֵ����������
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