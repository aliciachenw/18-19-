#include<stdio.h>
#include<stdlib.h>

void InsertArr(int *small,int n);

int main()
{
	int N;
	scanf("%d",&N);
	int *a;
	a=(int *)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
		scanf("%d",a+i);
	int K;
	scanf("%d",&K);
	//int *small;
	//small=(int *)malloc(sizeof(int)*K);
	int small[100];
	int counter=0;

	for(int i=0;i<N;i++)
		if(counter<K)
		{
			//����a[i]
			small[counter]=a[i];
			counter++;
			InsertArr(small,counter);

		}
		else if(a[i]<small[K-1])
		{
			//����a[i]
			small[K-1]=a[i];
			InsertArr(small,K);
		}

	//���
	for(int i=0;i<K;i++)
		printf("%d ",small[i]);
}

void InsertArr(int *small,int n) //��small�ĵ�n��Ԫ�ؽ��в�������
{
	int i=n-1;
	int temp;
	while (!(small[i]>small[i-1] || i==0))
	{
		temp=small[i-1];
		small[i-1]=small[i];
		small[i]=temp;
		i--;
	}
}