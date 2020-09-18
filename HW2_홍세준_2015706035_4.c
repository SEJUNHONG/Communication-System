#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592

int main(void)
{
	FILE*bit = 0;
	FILE*src4 = 0;
	int i = 0, j = 0, k = 0, n = 0, m = 0;
	int cnt4 = 0;
	double ber4 = 0.0;
	int*dat = 0;
	double*input4 = 0;
	int*qpsk = 0;
	double temp1 = 0.0, temp2=0.0;
	dat = (int*)malloc(sizeof(int) * 1000);
	input4 = (double*)malloc(sizeof(double) * 40000);
	qpsk = (int*)malloc(sizeof(int) * 1000);

	int arr0[1000] = { 0 };
	double arr4[40000] = { 0 };
	double s4[1000] = { 0 }, s5[1000] = { 0 },  c1[40] = { 0 }, c2[40] = { 0 };

	bit = fopen("bit.dat", "r");
	src4 = fopen("qpsk.dat", "r");

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr0);
		dat[n] = arr0[0];
	}

	for (m = 0; m < 40000; m++)
	{
		fscanf(src4, "%lf \n", &arr4);
		input4[m] = arr4[0];
	}

	for (i = 0; i < 500; i++)
	{
		temp1 = 0.0;
		temp2 = 0.0;
		for (j = 0; j <40; j++)
		{
			temp1 += input4[40 * i + j] * cos(2 * Pi*j / 10);
			temp2 += input4[40 * i + j] * sin(2 * Pi*j / 10);
		}
		if (temp1 > 0.0)
			qpsk[2 * i] = 1;
		else
			qpsk[2 * i] = 0;

		if (temp2 > 0.0)
			qpsk[2 * i + 1] = 0;
		else
			qpsk[2 * i + 1] = 1;
	}

	for (k = 0; k < 1000; k++)
	{

		if (qpsk[k] != dat[k])
		{
			cnt4++;
		}
	}

	ber4 = (cnt4) / 10.0;
	printf("QPSK의 BER은 %lf 입니다.\n", ber4);

	free(dat);
	free(input4);
	free(qpsk);
	fclose(bit);
	fclose(src4);
	return 0;
}