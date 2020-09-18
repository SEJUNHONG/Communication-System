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
	double*H1 = 0;
	double temp = 0;
	int*output1 = 0, *output2 = 0, *output3 = 0, *output4 = 0;
	int i = 0, j = 0, k = 0, m = 0, n = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	double BER1 = 0, BER2 = 0, BER3 = 0, BER4 = 0;

	bit = fopen("bit.dat", "r");
	src1 = fopen("input#2.dat", "r");
	dat = (int*)malloc(sizeof(int) * 1000);
	input1 = (double*)malloc(sizeof(double) * 10000);
	H1 = (double*)malloc(sizeof(double) * 1000);
	output1 = (int*)malloc(sizeof(int) * 1000);

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
		temp = 0.0;
		for (i = 0; i <= 9; i++)
		{
			temp += input1[10 * j + i]-10.0;
		}
		H1[j] = temp;
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

	BER1 = cnt1 / 1000.0;
	printf("input2의 BER은 %lf입니다.", BER1);

	free(dat);
	free(input1);
	free(output1);
	fclose(bit);
	fclose(src1);

	return 0;
}