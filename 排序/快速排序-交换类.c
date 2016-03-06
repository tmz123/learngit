#include<stdio.h>
#include"Create.c"



#define ARRAYLWN  10

/*
	ð�������У���ɨ��Ĺ�����ֻ�Ƚ����ڵ�����Ԫ�أ������ڻ�����������Ԫ��ʱֻ��
	����һ��������ʵҲ����ͨ�����������ڵ�Ԫ�ؽ��н������������ĺô��ǿ������������¼�еĶ������
	������ӿ�������ٶȡ��ɴ˿ɼ�����������ķ�������ͨ��һ�ν����������������Ĺ��̡�


  ���ŵĻ���˼���ǣ�

  1���Ӵ�����ļ�¼�б���ѡȡһ����¼��ͨ��ѡȡ���ǵ�һ��Ԫ�أ���������Ϊ�ؼ���K1
  2�����ؼ���С��K1�ļ�¼�Ƶ�ǰ�棬���ؼ��ִ���K1���Ƶ����棬����Ὣ�������¼���зֳ������ӱ�
  3�����ؼ���ΪK1�ļ�¼�嵽��ֽ��ߵ�λ��


  ע�⣺
  ���ŵ�ʱ��ķѺ͹���Ҫʹ�õݹ������ȵ������йأ�������˵

  ������:ÿ�˽�����һ��Ϊ���������ڱ���м䣬����ֳɴ�С��ȵ��ӱ�����������۰���ҡ�ʱ�临�Ӷ�ΪO(nlog2n)
  ���������������¼�Ѿ�����ʱ���㷨��ִ��ʱ�����ʱ�临�Ӷ�Ϊ��n^2/2



  ���ŵĻ������裺

  1����������ѡ��һ������׼����
  2��ɨ��һ�����У������бȡ���׼��С��Ԫ������ǰ�棬�����бȡ���׼�����Ԫ�����ں���
  3��ʹ�õݹ齫���������л���Ϊ��С�����У�ֱ����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵ������������

*/


int Division(int a[],int left,int right);
void QKSort(int a[],int left,int right);

int Division(int a[],int left,int right){
	int base = a[left];
	while(left<right){
		while((left<right) && (a[right]>base))
			right--;
		a[left] = a[right];
		while((left<right) && (a[left]<base))
			left++;
		a[right] = a[left];
	}
	a[left] = base;
	return left;
	
}
void QKSort(int a[],int left,int right){
	int i =0;
	if(a==NULL || left<0 || right<0 || left>right)
		return ;
	if (left<right){
		i = Division(a,left,right);
		QKSort(a,left,i-1);
		QKSort(a,i+1,right);
	} 
	
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
		QKSort(a,0,ARRAYLWN-1);
		printf("�����:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}