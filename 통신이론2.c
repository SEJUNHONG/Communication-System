#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE *wp;
	FILE  *fo1, *fo2;
	
	float s1,s2;
	short data; 
	int n;
	fo1 = fopen("outputa.raw","wb"); //outputa.raw파일 쓰기모드로 만들기 
	fo2 = fopen("outputb.raw","wb"); //outputb.raw파일 쓰기모드로 만들기   

	for(n=0; ;n++){
	
	s1 = 10000*cos(2*M_PI*12000*n/48000+0.01*10*sin(2*M_PI*600*n/48000));  // kp가 0.01일때 s(t)를 디지털 데이터화하여  출력한 결과 s1 
	s2 = 10000*cos(2*M_PI*12000*n/48000+0.2*10*sin(2*M_PI*600*n/48000));   // kp가 0.2일때 s(t)를 디지털 데이터화하여  출력한 결과 s2 
	
	data = (short)s1;
	fwrite(&data,2,1,fo1); //fo1 에 s1 신호를 2bite 1개씩 short형으로 바꿔서 파일에 쓰기
	data = (short)s2;
	fwrite(&data,2,1,fo2); //fo2 에 s2 신호를 2bite 1개씩 short형으로 바꿔서 파일에 쓰기
	}
	fclose(wp);
	return 0;
}
	

