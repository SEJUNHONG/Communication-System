#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592

int main(void)
{
	FILE*bit = 0;
	FILE*src = 0;
	FILE*des = 0;
	int i = 0, j = 0, k = 0, n = 0, m = 0;
	double ber = 0.0;
	int*dat = 0;
	double*input = 0;
	int*bpsk = 0;
	double temp = 0.0;
	dat = (int*)malloc(sizeof(int) * 1000);
	input = (double*)malloc(sizeof(double) * 60000);
	bpsk = (int*)malloc(sizeof(int) * 1000);

	int arr0[1000] = { 0 };
	double arr1[60000] = { 0 };
	double s[1000] = { 0 }, c[60] = { 0 };

	bit = fopen("bit.dat", "r");
	src = fopen("bpsk.dat", "r");

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr0);
		dat[n] = arr0[0];
	}

	for (m = 0; m < 60000; m++)
	{
		fscanf(src, "%lf \n", &arr1);
		input[m] = arr1[0];
	}

	for (i = 0; i < 1000; i++)
	{
		temp = 0.0;
		for (j = 0; j < 60; j++)
		{
			c[j] = 5000 * cos(2 * Pi * j / 8);
			temp += input[60 * i + j] * c[j];
		}

		if (temp > 0.0)
			bpsk[i] = 1;
		else
			bpsk[i] = 0;
	}

	int cnt = 0;
	for (i = 0; i < 1000; i++)
	{
		if (bpsk[i] != dat[i])
		{
			cnt++;
		}
	}

	ber = (cnt) / 10.0;

	printf("BPSK의 BER은 %lf 입니다.\n", ber);

	free(dat);
	free(input);
	free(bpsk);
	fclose(bit);
	fclose(src);
	return 0;
}