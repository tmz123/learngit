#include<stdio.h>
#include"Create.c"

#define ARRAYLWN  500
/*

  直接选择排序


  （1）关键字比较次数
  无论文件初始状况怎么样，在第i躺排序中选出最小关键字的记录，需要做n-i次比较
	所以
	总的比较次数是：O(n^2)
	
	  具体说明如下：
	  当初始文件为正序的时候，引动次数为0
	  当初始文件为反序的时候，总的移动次数为3（n-1）
	  直接选择排序的平均时间复杂度是O（n^2）

  （2）直接选择排序是一个就地排序
  （3）稳定性分析：直接选择排序是不稳定的





  具体排序流程：

  1）在初始状态，无序区为整个原始序列，有序区为空
  2）实现第一躺排序。在无序区选出最小的记录a[t]，将它与无序区的第一个记录做交换。‘
	这样就会使无序区减少一个元素而有序区增加一个元素
  3）实现第i躺排序


  n个文件记录的直接选择排序经过n-i躺排序就会排序成功，会得到想要的排序结果

  
 

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
			printf("生成随机数失败！");
			getch();
			return 1;
		}
		printf("原数据:");
		for(i = 0;i<ARRAYLWN;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		SelectSort(a,ARRAYLWN);
		printf("排序后:");
		for(i = 0;i<ARRAYLWN;i++)
			printf("%d ",a[i]);
		printf("\n");
		getch();
		return 0;
	}