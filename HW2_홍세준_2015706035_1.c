#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592

int main(void)
{
	FILE*bit = 0;
	FILE*src1 = 0;
	FILE*des1 = 0;
	int i = 0, j=0, k=0,  n = 0, m=0;
	double ber1 = 0.0;
	int*dat = 0;
	double*input1 = 0;
	int*bpsk1 = 0;
	double temp = 0.0 ;
	dat = (int*)malloc(sizeof(int) * 1000);
	input1 = (double*)malloc(sizeof(double) * 20000);
	bpsk1 = (int*)malloc(sizeof(int) * 1000);

	int arr0[1000] = { 0 };
	double arr1[20000] = { 0 };
	double s1[1000] = { 0 }, c[20] = { 0 };

	bit = fopen("bit.dat", "r");
	src1 = fopen("bpsk1.dat", "r");

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr0);
		dat[n] = arr0[0];
	}

	for (m = 0; m < 20000; m++)
	{
		fscanf(src1, "%lf \n", &arr1);
		input1[m] = arr1[0];
	}

	for (i = 0; i < 1000; i++)
	{
		temp = 0.0;
		for (j = 0; j < 20; j++)
		{
			c[j] = 1000 * cos(2 * Pi * j * 0.1);
			temp += input1[20 * i + j] * c[j];
		}

		if (temp > 0.0)
			bpsk1[i] = 1;
		else
			bpsk1[i] = 0;
	}

	int cnt1 = 0;
	for (i = 0; i < 1000; i++)
	{
		if (bpsk1[i] != dat[i])
		{
			cnt1++;
		}
	}
	
	ber1 = (cnt1) / 10.0;

	printf("BPSK1의 BER은 %lf 입니다.\n", ber1);

	free(dat);
	free(input1);
	free(bpsk1);
	fclose(bit);
	fclose(src1);
	return 0;
}