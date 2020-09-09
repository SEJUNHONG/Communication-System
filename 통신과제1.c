#include <stdio.h>
#include <math.h>
int main(void)
{
	FILE *rp,*wp;     //�б� ���� ���������� ���� 
	FILE *fin,*fo1,*fo2; //�Է�, ��� ���������� ���� 
	short data;    // 16��Ʈ ������ ���� 
	float qam,msg1,msg2;      // ��ȣ �Ǽ������� ���� 
	int n;
	
	fin = fopen("qam.raw","rb");     //qam.raw ������ ���� �б���� ���� 
	fo1 = fopen("output1.raw","wb"); //output1.raw���� ������� ����� 
	fo2 = fopen("output2.raw","wb"); //output2.raw���� ������� ����� 
	
	for (n=0; ;n++){
		if(fread(&data,2,1,fin)=='\0'){
			break;  //�Է������� ������ 2bite 1���� �дٰ� �������� NULL�� �Ǹ� �ݺ��� ���� 
		}
	qam = (float)data;
	
	msg1 = qam*cos(2*M_PI*9600*n/48000); //qam �Է½�ȣ�� cos(2��9600n/48000)�� ���Ͽ� ��ȣ�� ���� 
	msg2 = qam*sin(2*M_PI*9600*n/48000); //qam �Է½�ȣ�� sin(2��9600n/48000)�� ���Ͽ� ��ȣ�� ����  
	//c������ �ð��� ���� ��ȣ�� ��ȭ��ų �� �����Ƿ� ������ ������ȭ ��Ű�� ���ؼ� 1�ʿ� 48000sample�� �Ҵ��ϱ� ���� t ��� n/48000 �̿�. 
	
	data = (short)msg1;
	fwrite(&data,2,1,fo1); //fo1 �� msg1 ��ȣ�� 2bite 1���� short������ �ٲ㼭 ���Ͽ� ���� 
	data = (short)msg2;
	fwrite(&data,2,1,fo2); //fo2 �� msg2 ��ȣ�� 2bite 1���� short������ �ٲ㼭 ���Ͽ� ���� 
	}
	//���� ����� �ݱ�  
	fclose(fin);
	fclose(fo1);
	fclose(fo2);
	return 0; 
}

