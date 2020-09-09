#include <stdio.h>
#include <math.h>
int main(void)
{
	FILE *rp,*wp;     //읽기 쓰기 파일포인터 선언 
	FILE *fin,*fo1,*fo2; //입력, 출력 파일포인터 선언 
	short data;    // 16비트 데이터 선언 
	float qam,msg1,msg2;      // 신호 실수형으로 선언 
	int n;
	
	fin = fopen("qam.raw","rb");     //qam.raw 변조된 파일 읽기모드로 열기 
	fo1 = fopen("output1.raw","wb"); //output1.raw파일 쓰기모드로 만들기 
	fo2 = fopen("output2.raw","wb"); //output2.raw파일 쓰기모드로 만들기 
	
	for (n=0; ;n++){
		if(fread(&data,2,1,fin)=='\0'){
			break;  //입력파일의 데이터 2bite 1개씩 읽다가 마지막에 NULL이 되면 반복문 종료 
		}
	qam = (float)data;
	
	msg1 = qam*cos(2*M_PI*9600*n/48000); //qam 입력신호에 cos(2π9600n/48000)을 곱하여 신호를 복조 
	msg2 = qam*sin(2*M_PI*9600*n/48000); //qam 입력신호에 sin(2π9600n/48000)을 곱하여 신호를 복조  
	//c언어에서는 시간에 따라 신호를 변화시킬 수 없으므로 디지털 데이터화 시키기 위해서 1초에 48000sample을 할당하기 위헤 t 대신 n/48000 이용. 
	
	data = (short)msg1;
	fwrite(&data,2,1,fo1); //fo1 에 msg1 신호를 2bite 1개씩 short형으로 바꿔서 파일에 쓰기 
	data = (short)msg2;
	fwrite(&data,2,1,fo2); //fo2 에 msg2 신호를 2bite 1개씩 short형으로 바꿔서 파일에 쓰기 
	}
	//파일 저장과 닫기  
	fclose(fin);
	fclose(fo1);
	fclose(fo2);
	return 0; 
}

