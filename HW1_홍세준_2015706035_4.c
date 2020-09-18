#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	FILE *bit = 0;
	FILE*src1 = 0, *src2 = 0, *src3 = 0, *src4 = 0;
	FILE*des1 = 0, *des2 = 0, *des3 = 0, *des4 = 0;
	int *dat = 0;
	double*input1 = 0, *input2 = 0, *input3 = 0, *input4 = 0;
	double*H1 = 0, *H2=0;
	double temp1 = 0, temp2=0;
	int*output1 = 0, *output2 = 0, *output3 = 0, *output4 = 0;
	int i = 0, j = 0, k = 0, m = 0, n = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	double BER1 = 0, BER2 = 0, BER3 = 0, BER4 = 0;

	bit = fopen("bit.dat", "r");
	src1 = fopen("input#4.dat", "r");
	dat = (int*)malloc(sizeof(int) * 1000);
	input1 = (double*)malloc(sizeof(double) * 10000);
	H1 = (double*)malloc(sizeof(double) * 1000);
	H2 = (double*)malloc(sizeof(double) * 1000);
	output1 = (int*)malloc(sizeof(int) * 1000);
	output2 = (int*)malloc(sizeof(int) * 1000);

	int arr2[1000] = { 0 };
	double arr[10000] = { 0 };

	for (n = 0; n < 1000; n++)
	{
		fscanf(bit, "%d \n", &arr2);
		dat[n] = arr2[0];
	}

	for (m = 0; m < 10000; m++)
	{
		fscanf(src1, "%lf \n", &arr);
		input1[m] = arr[0];
	}


	for (j = 0; j <= 999; j++)
	{
		temp1 = 0.0;
		for (i = 0; i <= 9; i++)
		{
			temp1 += input1[10 * j + i];
		}
		H1[j] = temp1;
	}

	for (j = 0; j <= 999; j++)
	{
		temp2 = 0.0;
		temp2 = 0 * input1[10 * j + 0] + 6 * input1[10 * j + 1] + 10 * input1[10 * j + 2] + 12 * input1[10 * j + 3] + 15 * input1[10 * j + 4]
			+ 15 * input1[10 * j + 5] + 12 * input1[10 * j + 6] + 10 * input1[10 * j + 7] + 6 * input1[10 * j + 8] + 0 * input1[10 * j + 9];
		H2[j] = temp2;
	}

	for (k = 0; k < 1000; k++)
	{
		if (H1[k] > 0.0)
		{
			output1[k] = 1;
		}
		else
		{
			output1[k] = 0;
		}

		if (output1[k] != dat[k])
		{
			cnt1++;
		}
	}

	for (k = 0; k < 1000; k++)
	{
		if (H2[k] > 0.0)
		{
			output2[k] = 1;
		}
		else
		{
			output2[k] = 0;
		}

		if (output2[k] != dat[k])
		{
			cnt2++;
		}
	}

	BER1 = cnt1 / 1000.0;
	BER2 = cnt2 / 1000.0;
	printf("input4의 적분을 사용한 수신기 구현 BER은 %lf입니다.\n", BER1);
	printf("input4의 matched filter를 사용한 수신기 구현 BER은 %lf입니다.", BER2);

	free(dat);
	free(input1);
	free(output1);
	fclose(bit);
	fclose(src1);

	return 0;
}