#include<stdio.h>
#include"Create.c"



#define ARRAYLWN  12
/*
	冒泡排序的基本思想是：

  从头扫描待排序记录序列，在扫描大的过程中顺序比较相邻元素的大小

  它会执行length-1躺，每趟都会n-i次。若出现逆序就会交换数据，否则则不会交换
  还有
  就是如果在一趟中没有发生过交换，那么说明数组本来就是已经排序好的
  所以就终止排序


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
	printf("排序后:");
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
			printf("生成随机数失败！");
			getch();
			return 1;
		}
		printf("原数据:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		BubbleSort(a,ARRAYLWN);
		getch();
		return 0;
	}