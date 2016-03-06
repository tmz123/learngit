#include<stdlib.h>

int Create(int arr[],int n,int min,int max);

int Create(int arr[],int n,int min,int max){

	int i,j,flag;
	
	if((max-min+1)<n) 
		return 0;
	for(i = 0;i<n;i++){

		do{
			arr[i] = (max-min+1)*rand()/(RAND_MAX+1)+min;
			flag = 0;
			for(j = 0;j<i;j++){
				if(arr[i] == arr[j])
					flag = 1;
			}
		}while(flag);
	}
	return 1;
}
