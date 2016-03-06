#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  10
/*

因为对有序表进行折半查找的性能要优于顺序查找，所以可以将折半查找用在有序记录中确定应该插入的位置
这种排序的方法称为折半直接插入排序算法。

  折半直接插入排序算法的好处是减少关键字的比较次数
  但是
  没有改变移动元素的时间耗费，所以折半直接插入排序算法总的时间复杂度仍然是O(N^2)



  如果想要提高移动元素的效率的话
  可以采取表插入排序
	它的基本思想是：
		先在待插入记录之前的有序子链中查找应该插入的位置，然后将待插入记录插入链表。因为链表的
		插入操作只修改指针的域，而不移动记录，所以使用表插入排序能够提高排序效率。

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
		if(!Create(a,ARRAYLWN,1,10990)){
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