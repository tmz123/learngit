#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  10

/*

  ��δ�����¼���������Ĳ��뵽������ļ�¼�Ӽ��У�ָ�����д��ż�¼ȫ���������Ϊֹ


  ֱ�Ӳ�������
  1��ʹ�õļ�������Ϊ����ʱ����������¼
  2���Ӻ���ǰ����Ӧ�ò����λ��
  3���������ƶ���ͬһѭ���н���


  �ӿռ�Ƕȿ���ֱ�Ӳ�������ֻ��Ҫt������ʵ�֡��ռ临�Ӷ�O(1)
  ��ʱ��Ƕȿ�����Ҫʱ��ķ��ڹؼ��ֱȽϺ��ƶ�Ԫ���ϡ�����һ�˲������򣬲���ļ�¼��ǰi-1��¼�Ĺؼ��ֵĹ�ϵ������
	�㷨��whileѭ���Ĵ���



  ֱ�Ӳ��������㷨����������ʹ�õģ����Ƚ��ʺ��ڴ������¼��Ŀ�����һ�������������
  ���������¼��Ŀ�ϴ��ʱ��ֱ��ʹ��ֱ�Ӳ�������ή�ͺܶ����ܡ�



  �Ľ���
  ���١��ȽϹؼ��֡��͡��ƶ���¼�������ֲ����Ĵ���
  */

void InsertSort(int a[],int n){
	int i,j,t;
	for(i = 1;i<n;i++){
		t = a[i];
		for(j = i-1;j>=0 && t < a[j];j--)
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
		InsertSort(a,ARRAYLWN);
		getch();
		return 0;
	}