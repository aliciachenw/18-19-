#include<stdio.h>
#include<stdlib.h>

//�ò������򷨶������������
void InsertArrange(int arr[],int len)//arr���������飬len���鳤��
{
	for(int i=1;i<len;i++)//����ֵa[i]
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

//���۰뷨��ĳ��Ԫ�ص�һ�γ��ֵ�λ��
int HalfSearchMin(int arr[],int len,int key)//arr���������� len�����鳤�� key������Ԫ��
{
	int low,high,mid;//��ǰ���䣺[low,high]
	low=0;
	high=len-1;
	while(high-low>1)//�ڵ�ǰ�������滹��Ԫ�ص�ʱ��
	{
		mid=(low+high)/2;
		if(arr[mid]>key)
			high=mid;
		else if(arr[mid]<key)
			low=mid;
		else //����ͨ�۰뷨�����𣺵��е�Ͳ���Ԫ����ͬʱ����high��Ϊ�е�
			high=mid;
	}
	//Ҳ����˵��������һ�һֱ����������high-1,high��ʹ��arr[high]=key,arr[high-1]<key
	return high;
}

//���۰뷨��ĳ��Ԫ�����һ�γ��ֵ�λ��
int HalfSearchMax(int arr[],int len,int key)//arr���������� len�����鳤�� key������Ԫ��
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
		else //����ͨ�۰뷨�����𣺵��е�Ͳ���Ԫ����ͬʱ����low��Ϊ�е�
			low=mid;
	}
	//Ҳ����˵��������һ�һֱ����������low,low+1��ʹ��arr[low]=key,arr[low+1]>key
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