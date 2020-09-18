#include <stdio.h>
#include <math.h>

int main(void)
{
	FILE *rp,*wp;     //�б� ���� ���������� ���� 
	FILE *fin,*fo1,*fo2,*fo3,*fo4; //�Է�, ��� ���������� ���� 
	short data;    // 16��Ʈ ������ ���� 
	
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
			break;  //�Է������� ������ 2byte(16bit)�� 1���� �дٰ� �������� NULL�� �Ǹ� �ݺ��� ���� 
		}
		input = (float)data; //input�� float������ �ٲ� 
				
		uniform =(short)(128*(int)(abs(input)/128 + 0.5)); //uniform ����ȭ  
							
		y = abs(8192 * log10(1+(255*abs((input))/8192))/log10(256)); // h(m)
		data =128*(int)((y/128)+0.5); //����ȭ   
		nonuniform =(short)((pow(10,data*(log10(256))/8192)-1)*8192/255); //nonuniform ���Ҵ� h-1(m)   
		
		if(input<0){
			uniform = -uniform;
			nonuniform = -nonuniform;
			
		}//�޼����� �����ΰ�� ���� 
			
		m1error = (short)(input - uniform); // ������ �޼��� ���� 
		m2error = (short)(input - nonuniform); // �������� �޼��� ���� 
		
		fwrite(&uniform,2,1,fo1); //fo1 �� uniform�� 2bite 1���� �ٲ㼭 ���Ͽ� ����
		fwrite(&nonuniform,2,1,fo2); //fo2�� nonuniform�� 2bite 1���� �ٲ㼭 ���Ͽ� ����  
		fwrite(&m1error,2,1,fo3);
		fwrite(&m2error,2,1,fo4);
	
	}
	//���� ����� �ݱ�  
	fclose(fin);
	fclose(fo1);
	fclose(fo2);
	fclose(fo3);
	fclose(fo4);
	return 0; 
}
