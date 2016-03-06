#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  10
/*

��Ϊ�����������۰���ҵ�����Ҫ����˳����ң����Կ��Խ��۰�������������¼��ȷ��Ӧ�ò����λ��
��������ķ�����Ϊ�۰�ֱ�Ӳ��������㷨��

  �۰�ֱ�Ӳ��������㷨�ĺô��Ǽ��ٹؼ��ֵıȽϴ���
  ����
  û�иı��ƶ�Ԫ�ص�ʱ��ķѣ������۰�ֱ�Ӳ��������㷨�ܵ�ʱ�临�Ӷ���Ȼ��O(N^2)



  �����Ҫ����ƶ�Ԫ�ص�Ч�ʵĻ�
  ���Բ�ȡ���������
	���Ļ���˼���ǣ�
		���ڴ������¼֮ǰ�����������в���Ӧ�ò����λ�ã�Ȼ�󽫴������¼����������Ϊ�����
		�������ֻ�޸�ָ����򣬶����ƶ���¼������ʹ�ñ���������ܹ��������Ч�ʡ�

*/

void InsertSort(int a[],int n){
	int i,j,t;
	int low = 0;
	int high = 0;
	int mid = 0;

	for(i = 1;i<n;i++){
		t = a[i];
		low = 0;
		high = i -1;
		while(low<=high){
			mid = (low+high)/2;
			if(t < a[mid])
				high = mid - 1;
			else 
				low = mid + 1;
		}
		for(j = i-1;j>=low;j--)
			a[j+1] = a[j];
		a[j+1] = t;
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
		if(!Create(a,ARRAYLWN,1,10990)){
			printf("���������ʧ�ܣ�");
			getch();
			return 1;
		}
		printf("ԭ����:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		InsertSort(a,ARRAYLWN);
		getch();
		return 0;
	}