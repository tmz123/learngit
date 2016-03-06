#include<stdio.h>
#include"Create.c"



#define ARRAYLWN  10

/*
	冒泡排序中，在扫描的过程中只比较相邻的两个元素，左移在互换两个相邻元素时只能
	消除一个逆序。其实也可以通过两个不相邻的元素进行交换，这样做的好处是可以消除排序记录中的多个逆序
	这样会加快排序的速度。由此可见，快速排序的方法就是通过一次交换而消除多个逆序的过程。


  块排的基本思想是：

  1）从待排序的记录列表中选取一个记录，通常选取的是第一个元素，将其设置为关键字K1
  2）将关键字小于K1的记录移到前面，将关键字大于K1的移到后面，结果会将待排序记录序列分成两个子表
  3）将关键字为K1的记录插到其分界线的位置


  注意：
  快排的时间耗费和共需要使用递归调用深度的趟数有关，具体来说

  最好情况:每趟将序列一分为二，正好在表的中间，将表分成大小相等的子表，这就类似于折半查找。时间复杂度为O(nlog2n)
  最坏情况：当待排序记录已经排序时，算法的执行时间最长。时间复杂度为：n^2/2



  快排的基本步骤：

  1）从数列中选择一个“基准”。
  2）扫描一遍数列，将所有比“基准”小的元素排在前面，将所有比“基准”大的元素排在后面
  3）使用递归将各个子序列划分为更小的序列，直到把小于基准值元素的子序列和大于基准值的子序列排序

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
			printf("生成随机数失败！");
			getch();
			return 1;
		}
		printf("原数据:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		QKSort(a,0,ARRAYLWN-1);
		printf("排序后:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}