#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  6
#define MAX      32767 

/*
	�鲢����

  1�������������������ϵ������ϲ���һ���µ�����������ʦ���к���k����¼�����Ƚ���k���ǿ���k�������������
  ��ÿ�������еĳ���Ϊ1
  2��Ȼ����������ϲ����õ���k/2������Ϊ2��kΪ�����Ļ����һ�������еĳ���Ϊ1���������С�
  3�����������������ٽ��������ϲ�������ظ���ȥֱ���õ�һ������Ϊk����������

  �����������������   ��·�鲢�����㷨


  ע�⣺�ڶ�·�鲢�����У��ݴ����ݵĿռ���Ҫ��̬����ġ���Ϊ����Ŀռ��ܴ�������Ҫ�жϼ�������ռ��Ƿ�ɹ�

  �ڹ鲢�����У�һ�˹鲢��Ҫ����õ���·�鲢�����㷨��һ�˹鲢����Ĳ����ǵ���n/2h��merge�㷨��������ǰ�����ڳ���Ϊ
  h������ν��������鲢��Ȼ��õ�ǰ�����ڲ�����߶�Ϊ2h�������

  ����һ�˵�ʱ�临�Ӷ�ΪO(n)

  �����鲢����Ĺ����й���Ҫ m=��2Ϊ��n�Ķ���  �ɶ�·�鲢�����Թ鲢������ܵ�ʱ�临�Ӷ�ΪO(n*m)
  ��Ҫ�ʹ��ż�¼һ�����ݴ�ռ���O(n)


  ���������Ͷ�������ȣ��鲢���������ص��ǣ�����һ���ȶ������򷽷�����һ���������ΪҪ�󸽼Ӻʹ��ż�¼��������
  �����ռ䣬���Ժ����ö�·�鲢��������ڲ�����


  �鲢������Ҫ�����ⲿ����
 
  */

void merge(int a[],int start,int mid,int end,int temp[]){ 
	
	int  i=start;
	int j = mid+1;

	int m = mid;
	int n = end;

	int k = 0;

 
	while(i<=m && j<=n){
		if(a[i]>a[j])
			temp[k++] = a[j++];
		else 
			temp[k++] = a[i++];
	}
	while(i<=m)
			temp[k++] = a[i++];
	while(j<=n)
			temp[k++] = a[j++];
	printf("temp: ");
	for(i = 0;i<k;i++){
		printf("%d ",temp[i]);
		a[start+i] = temp[i];
	} 
	printf("\n");
}

void GuiSort(int a[],int start,int end,int temp[]){

	int mid = 0; 
	int i;  

	if((start<end) && (start>=0) && (end>=0) ){  

		mid = (start+end)/2;
		
		printf("GuiSort (%d-%d,%d-%d)",start,mid,mid+1,end);
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");

		GuiSort(a,start,mid,temp);
		GuiSort(a,mid+1,end,temp);
		merge(a,start,mid,end,temp);

		printf("merge (%d-%d,%d-%d)",start,mid,mid+1,end);
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
	} 

}
int main(void){
		int i ;
		int *temp;
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
		//�����ﴴ����̬����Ƚ����ڿռ�Ķ�ά��������ڵݹ���õķ����еĻ��ͻᷴ���������ͷţ�����ȫҲ������
		temp = (int*)malloc(sizeof(int)*ARRAYLWN);
		if(temp!=NULL){
			GuiSort(a,0,ARRAYLWN-1,temp);
			free(temp);
		}else
			printf("��Ǹ������ռ�ʧ�ܣ�\n");
		printf("�����:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}