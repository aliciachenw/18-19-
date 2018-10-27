#include<stdio.h>
#include<stdlib.h>

//用插入排序法对数组进行排序
void InsertArrange(int arr[],int len)//arr待排序数组，len数组长度
{
	for(int i=1;i<len;i++)//插入值a[i]
	{
		int j=i;
		while(j>0 && arr[j]<arr[j-1])
		{
			int temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			j--;
		}
	}
}

//用折半法找某个元素第一次出现的位置
int HalfSearchMin(int arr[],int len,int key)//arr：查找数组 len：数组长度 key：查找元素
{
	int low,high,mid;//当前区间：[low,high]
	low=0;
	high=len-1;
	while(high-low>1)//在当前区间里面还有元素的时候
	{
		mid=(low+high)/2;
		if(arr[mid]>key)
			high=mid;
		else if(arr[mid]<key)
			low=mid;
		else //和普通折半法的区别：当中点和查找元素相同时，把high设为中点
			high=mid;
	}
	//也就是说，这个查找会一直查找至发现high-1,high，使得arr[high]=key,arr[high-1]<key
	return high;
}

//用折半法找某个元素最后一次出现的位置
int HalfSearchMax(int arr[],int len,int key)//arr：查找数组 len：数组长度 key：查找元素
{
	int low,high,mid;
	low=0;
	high=len-1;
	while(high-low>1)
	{
		mid=(low+high)/2;
		if(arr[mid]>key)
			high=mid;
		else if(arr[mid]<key)
			low=mid;
		else //和普通折半法的区别：当中点和查找元素相同时，把low设为中点
			low=mid;
	}
	//也就是说，这个查找会一直查找至发现low,low+1，使得arr[low]=key,arr[low+1]>key
	return low;
}

int main()
{
	int n;
	int number[100];
	int key;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&number[i]);
	InsertArrange(number,n);
	scanf("%d",&key);
	int low=HalfSearchMin(number,n,key);
	int high=HalfSearchMax(number,n,key);
	printf("%d<-->%d",low,high);
	return 0;
}