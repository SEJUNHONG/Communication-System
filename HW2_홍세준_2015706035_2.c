#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Pi 3.141592

int main(void)
{
	FILE*bit = 0;
	FILE*src2 = 0;
	int i = 0, j = 0, k = 0, n = 0, m = 0;
	double ber2 = 0.0;
	int*dat = 0;
	double*input2 = 0;
	int*bpsk2 = 0;
	double temp1 = 0.0, temp2=0.0;
	dat = (int*)malloc(sizeof(int) * 1000);
	input2 = (double*)malloc(sizeof(double) * 20000);
	bpsk2 = (int*)malloc(sizeof(int) * 1000);

	int arr0[1000] = { 0 };
	double arr2[20000] = { 0 };
	double s2[1000] = { 0 }, c1[20] = { 0 }, c2[20] = { 0 };

	bit = fopen("bit.dat", "r");
	src2 = fopen("bpsk2.dat", "r");

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr0);
		dat[n] = arr0[0];
	}

	for (m = 0; m < 20000; m++)
	{
		fscanf(src2, "%lf \n", &arr2);
		input2[m] = arr2[0];
	}

	for (i = 0; i < 1000; i++)
	{
		temp1 = 0.0;
		temp2 = 0.0;
		for (j = 0; j < 20; j++)
		{
			c1[j] = 1000 * cos(2 * Pi * j * 0.1);
			c2[j] = 1000 * sin(2 * Pi*j*0.1);
			temp1 += input2[20 * i + j] * c1[j];
			temp2 += input2[20 * i + j] * c2[j];
		}

		if (temp1 > 0.0 && temp2<0.0)
			bpsk2[i] = 1;
		else if(temp1<0.0 && temp2>0.0)
			bpsk2[i] = 0;
		else if (temp1 > 0.0 && temp2 > 0.0)
		{
			if (temp1 > temp2)
				bpsk2[i] = 1;
			else
				bpsk2[i] = 0;
		}
		else
		{
			if (temp1 < temp2)
				bpsk2[i] = 0;
			else
				bpsk2[i] = 1;
		}
	}

	int cnt2 = 0;
	for (i = 0; i < 1000; i++)
	{
		if (bpsk2[i] != dat[i])
		{
			cnt2++;
		}
	}

	ber2 = (cnt2) / 10.0;

	printf("BPSK2의 BER은 %lf 입니다.\n", ber2);

	free(dat);
	free(input2);
	free(bpsk2);
	fclose(bit);
	fclose(src2);
	return 0;
}