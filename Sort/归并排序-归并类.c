#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  6
#define MAX      32767 

/*
	归并排序

  1）将两个或者两个以上的有序表合并成一个新的有序表。假设厨师序列含有k个记录，首先将这k个记看成k个有序的子序列
  ，每个子序列的长度为1
  2）然后进行两两合并，得到是k/2个长度为2（k为奇数的话最后一个子序列的长度为1）的子序列。
  3）最后在这个基础上再进行两两合并，如此重复下去直到得到一个长度为k的有序序列

  上述的这个方法就是   二路归并排序算法


  注意：在二路归并过程中，暂存数据的空间是要动态申请的。因为申请的空间会很大，所以需要判断加入申请空间是否成功

  在归并排序中，一趟归并中要多次用到二路归并排序算法。一趟归并排序的操作是调用n/2h次merge算法将序列中前后相邻长度为
  h的有序段进行两两归并，然后得到前后相邻擦汗年高度为2h的有序段

  所以一趟的时间复杂度为O(n)

  整个归并排序的过程中共需要 m=以2为底n的对数  躺二路归并，所以归并排序的总的时间复杂度为O(n*m)
  需要和待排记录一样的暂存空间是O(n)


  与快速排序和堆排序相比，归并排序的最大特点是：它是一种稳定的排序方法，在一般情况下因为要求附加和待排记录等数量的
  辅助空间，所以很少用二路归并排序进行内部排序


  归并排序重要用于外部排序
 
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
			printf("生成随机数失败！");
			getch();
			return 1;
		}
		printf("原数据:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		//在这里创建动态数组比较利于空间的额维护，如果在递归调用的方法中的话就会反复创建和释放，不安全也不方便
		temp = (int*)malloc(sizeof(int)*ARRAYLWN);
		if(temp!=NULL){
			GuiSort(a,0,ARRAYLWN-1,temp);
			free(temp);
		}else
			printf("抱歉！申请空间失败！\n");
		printf("排序后:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}