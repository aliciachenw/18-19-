#include <stdio.h>
#include <stdlib.h>
int main()
{
	int N;
	scanf("%d",&N);
	//int a[10000];
	int *a;
	a=(int *)malloc(sizeof(int)*N);
	int i;
	for(i=0;i<N;i++)
		scanf("%d",a+i);
	int del;
	scanf("%d",&del);
	i=0;
	while(i<N)
	{
		if(*(a+i)==del)//�����ǰԪ��Ҫ��ɾ��
		{
			for(int j=i+1;j<N;j++)
				*(a+j-1)=*(a+j);
			N--;
		}
		else //��ɾ��
			i++;
	}
	for(i=0;i<N;i++)
		if(i==0)
			printf("%d",*(a+i));
		else
			printf(" %d",*(a+i));
}
