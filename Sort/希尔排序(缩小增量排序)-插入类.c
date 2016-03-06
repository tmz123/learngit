#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  10


/*
希尔排序又被称为缩小增量排序法。这是一种基于直接插入排序的方法。希尔排序利用了直接插入排序的最佳性质，
首先将待排序的关键字序列分成若干个较小的序列，然后对子序列进行直接插入排序操作。经过上述粗略调整，整个序列的记录
已经基本有序，最后再对全部记录进行一次直接插入排序。

  在时间耗费上，希尔排序与直接插入排序法相比较，其性能有了大的改进。

  在进行直接插入排序的时候，如果待排序的记录已经有序时，直接插入排序的时间复杂度可以提高到O(n)。因为希尔排序对直接插入
  排序进行了改进，所以大大提高了排序的效率。


  希尔排序主要是节省了数据移动的次数，希尔排序在数据比较少的情况下的表现并不是多么的优秀。但是在处理大量数据的时候
  希尔排序的效率是比直接插入排序的效率高得多。所以呢
	建议

  少量数据用直接插入排序，大量数据用希尔排序



*/

void Xier(int a[],int n){
	int i,j,t;
	int d = n/2;
	while(d>=1){
		for(i = d;i<n;i++){
			t = a[i];
			for(j = i - d; j >=0 && t < a[j];j-=d)
				a[j+d] = a[j];
			a[j+d] = t;
		}
			d/=2;
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
		if(!Create(a,ARRAYLWN,1,120)){
			printf("生成随机数失败！");
			getch();
			return 1;
		}
		printf("原数据:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		Xier(a,ARRAYLWN);
		getch();
		return 0;
	}