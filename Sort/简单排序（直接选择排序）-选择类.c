#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  500
/*

  ֱ��ѡ������


  ��1���ؼ��ֱȽϴ���
  �����ļ���ʼ״����ô�����ڵ�i��������ѡ����С�ؼ��ֵļ�¼����Ҫ��n-i�αȽ�
	����
	�ܵıȽϴ����ǣ�O(n^2)
	
	  ����˵�����£�
	  ����ʼ�ļ�Ϊ�����ʱ����������Ϊ0
	  ����ʼ�ļ�Ϊ�����ʱ���ܵ��ƶ�����Ϊ3��n-1��
	  ֱ��ѡ�������ƽ��ʱ�临�Ӷ���O��n^2��

  ��2��ֱ��ѡ��������һ���͵�����
  ��3���ȶ��Է�����ֱ��ѡ�������ǲ��ȶ���





  �����������̣�

  1���ڳ�ʼ״̬��������Ϊ����ԭʼ���У�������Ϊ��
  2��ʵ�ֵ�һ��������������ѡ����С�ļ�¼a[t]���������������ĵ�һ����¼����������
	�����ͻ�ʹ����������һ��Ԫ�ض�����������һ��Ԫ��
  3��ʵ�ֵ�i������


  n���ļ���¼��ֱ��ѡ�����򾭹�n-i������ͻ�����ɹ�����õ���Ҫ��������

  
 

*/

void SelectSort(int a[],int n){

	int i,j,t,tem;

	for(i = 0;i<n-1;i++){
		t = i;
		for(j = i+1;j<=n-1;j++)
			if(a[t]>a[j])
				t = j;
			if(t!=i){
				tem = a[i];
				a[i] = a[t];
				a[t] = tem;
			}
		
	}
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
		SelectSort(a,ARRAYLWN);
		printf("�����:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}