#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592

int main(void)
{
	FILE*bit = 0;
	FILE*src3 = 0;
	int i = 0, j = 0, k = 0, n = 0, m = 0;
	int cnt3 = 0;
	double ber3 = 0.0;
	int*dat = 0;
	double*input3 = 0;
	int*bpsk3 = 0;
	double temp = 0.0;
	dat = (int*)malloc(sizeof(int) * 1000);
	input3 = (double*)malloc(sizeof(double) * 10000);
	bpsk3 = (int*)malloc(sizeof(int) * 1000);

	int arr0[1000] = { 0 };
	double arr3[10000] = { 0 };
	double s3[1000] = { 0 }, c[10] = { 0 };

	bit = fopen("bit.dat", "r");
	src3 = fopen("bpsk3.dat", "r");

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr0);
		dat[n] = arr0[0];
	}

	for (m = 0; m < 10000; m++)
	{
		fscanf(src3, "%lf \n", &arr3);
		input3[m] = arr3[0];
	}

	for (n = 0; n < 10; n++)
	{
		c[n] = 1000 * cos(2 * Pi*n / 10);
	}

	for (i = 0; i <= 999; i++)
	{
		temp = 0.0;
		for (j = 0; j <= 9; j++)
		{
			temp += input3[10 * i + j] * c[j];
		}
		s3[i] = temp;
	}

	for (k = 0; k < 1000; k++)
	{
		if (s3[k] > 0.0)
			bpsk3[k] = 1;
		else
			bpsk3[k] = 0;

		if (bpsk3[k] != dat[k])
		{
			cnt3++;
		}
	}

	ber3 = (cnt3) / 10.0;
	printf("BPSK3의 BER은 %lf 입니다.\n", ber3);

	free(dat);
	free(input3);
	free(bpsk3);
	fclose(bit);
	fclose(src3);
	return 0;
}