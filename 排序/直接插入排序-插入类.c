#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  10

/*

  将未排序记录逐个的有序的插入到已排序的记录子集中，指导所有待排记录全部插入完毕为止


  直接插入排序：
  1）使用的监视哨是为了临时保存待插入记录
  2）从后往前查找应该插入的位置
  3）查找与移动在同一循环中进行


  从空间角度看，直接插入排序只需要t来帮助实现。空间复杂度O(1)
  从时间角度看，主要时间耗费在关键字比较和移动元素上。对于一趟插入排序，插入的记录与前i-1记录的关键字的关系决定了
	算法中while循环的次数



  直接插入排序算法并不是任意使用的，它比较适合于待排序记录数目较少且基本有序的情况下
  当待排序记录数目较大的时，直接使用直接插入排序会降低很多性能。



  改进：
  减少“比较关键字”和“移动记录”这两种操作的次数
  */

void InsertSort(int a[],int n){
	int i,j,t;
	for(i = 1;i<n;i++){
		t = a[i];
		for(j = i-1;j>=0 && t < a[j];j--)
			a[j+1] = a[j];
		a[j+1] = t;
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
		InsertSort(a,ARRAYLWN);
		getch();
		return 0;
	}