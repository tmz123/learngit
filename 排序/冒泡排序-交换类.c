#include<stdio.h>
#include"Create.c"



#define ARRAYLWN  12
/*
	ð������Ļ���˼���ǣ�

  ��ͷɨ��������¼���У���ɨ���Ĺ�����˳��Ƚ�����Ԫ�صĴ�С

  ����ִ��length-1�ɣ�ÿ�˶���n-i�Ρ�����������ͻύ�����ݣ������򲻻ύ��
  ����
  ���������һ����û�з�������������ô˵�����鱾�������Ѿ�����õ�
  ���Ծ���ֹ����


*/

void BubbleSort(int a[],int n){

	int i ,j ,change = 1;
	int x= 0;

	for(i = 1;(i<=n-1) && (change==1);i++){
		change = 0;
		for(j = 1;j<=n-i;j++)
			if(a[j]>a[j+1]){
				x = a[j];
				a[j] = a[j+1];
				a[j+1] = x;
				change = 1;
			}
		
	}
	printf("�����:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
}
int main(void){
		int i ;
		int a[ARRAYLWN];
		for(i = 0;i<ARRAYLWN;i++)
			a[i] = 0;
		if(!Create(a,ARRAYLWN,1,100)){
			printf("���������ʧ�ܣ�");
			getch();
			return 1;
		}
		printf("ԭ����:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		BubbleSort(a,ARRAYLWN);
		getch();
		return 0;
	}