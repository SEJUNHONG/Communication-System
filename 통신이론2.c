#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE *wp;
	FILE  *fo1, *fo2;
	
	float s1,s2;
	short data; 
	int n;
	fo1 = fopen("outputa.raw","wb"); //outputa.raw���� ������� ����� 
	fo2 = fopen("outputb.raw","wb"); //outputb.raw���� ������� �����   

	for(n=0; ;n++){
	
	s1 = 10000*cos(2*M_PI*12000*n/48000+0.01*10*sin(2*M_PI*600*n/48000));  // kp�� 0.01�϶� s(t)�� ������ ������ȭ�Ͽ�  ����� ��� s1 
	s2 = 10000*cos(2*M_PI*12000*n/48000+0.2*10*sin(2*M_PI*600*n/48000));   // kp�� 0.2�϶� s(t)�� ������ ������ȭ�Ͽ�  ����� ��� s2 
	
	data = (short)s1;
	fwrite(&data,2,1,fo1); //fo1 �� s1 ��ȣ�� 2bite 1���� short������ �ٲ㼭 ���Ͽ� ����
	data = (short)s2;
	fwrite(&data,2,1,fo2); //fo2 �� s2 ��ȣ�� 2bite 1���� short������ �ٲ㼭 ���Ͽ� ����
	}
	fclose(wp);
	return 0;
}
	

