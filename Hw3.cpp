#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE *rp,*wp;     //읽기 쓰기 파일포인터 선언 
	FILE *fin,*fo1,*fo2,*fo3,*fo4; //입력, 출력 파일포인터 선언 
	short data;    // 16비트 데이터 선언 
	
	float input;
	short y, uniform, nonuniform;
	short m1error, m2error;
	int n;
	
	fin = fopen("input.raw","rb");    
	fo1 = fopen("uniform.raw","wb");
	fo2 = fopen("nonuniform.raw","wb");  
	fo3 = fopen("m1error.raw","wb");
	fo4 = fopen("m2error.raw","wb");
	for (n=0; ;n++){
		if(fread(&data,2,1,fin)=='\0'){
			break;  //입력파일의 데이터 2byte(16bit)를 1개씩 읽다가 마지막에 NULL이 되면 반복문 종료 
		}
		input = (float)data; //input을 float형으로 바꿈 
				
		uniform =(short)(128*(int)(abs(input)/128 + 0.5)); //uniform 양자화  
							
		y = abs(8192 * log10(1+(255*abs((input))/8192))/log10(256)); // h(m)
		data =128*(int)((y/128)+0.5); //양자화   
		nonuniform =(short)((pow(10,data*(log10(256))/8192)-1)*8192/255); //nonuniform 컴팬더 h-1(m)   
		
		if(input<0){
			uniform = -uniform;
			nonuniform = -nonuniform;
			
		}//메세지가 음수인경우 복조 
			
		m1error = (short)(input - uniform); // 유니폼 메세지 오차 
		m2error = (short)(input - nonuniform); // 논유니폼 메세지 오차 
		
		fwrite(&uniform,2,1,fo1); //fo1 에 uniform을 2bite 1개씩 바꿔서 파일에 쓰기
		fwrite(&nonuniform,2,1,fo2); //fo2에 nonuniform을 2bite 1개씩 바꿔서 파일에 쓰기  
		fwrite(&m1error,2,1,fo3);
		fwrite(&m2error,2,1,fo4);
	
	}
	//파일 저장과 닫기  
	fclose(fin);
	fclose(fo1);
	fclose(fo2);
	fclose(fo3);
	fclose(fo4);
	return 0; 
}
