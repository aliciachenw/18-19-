#include <stdio.h>
#include <stdlib.h>
//�����鷽ʽ��Լɪ������
int JosephusArray(int n,int m) //���Լɪ�����⣬����n,m������ֵΪ�������
{
	int* number;
	number=(int *)malloc(sizeof(int)*n); //number��Ŀǰ�����Ǳ������������-1˵���Ѿ�����
	int out=0; //���м�ֻ���ӳ�����
	int current=1; //��ǰ����
	int *p=number; //��ǰ�����ĺ���
	int i;
	for(i=0;i<n;i++)
		*(number+i)=0; //��ʼ��
	while(out!=n-1) //������������n-1ʱ
	{
		if(*p!=-1 && current!=m) //��ǰ���ӻ�û�г��֣����ҵ�ǰ��������m
		{
			*p=current;
			current++;
			if(p-number==n-1) //��һֻ���ӣ�ע������ѭ������βʱҪ�������鿪ͷ
				p=number;
			else
				p++;
		}
		else if (current==m && *p!=-1) //��ǰ���ӻ�û�г��֣���ǰ������m
		//else if(current==m)//����д��
		{
			*p=-1; //���ӳ���
			current=1; //�����ص�1
			out++; //��������+1
			if(p-number==n-1) //��һֻ����
				p=number;
			else
				p++;
		}
		else //��ǰ�ĺ����Ѿ����֣��Ͳ����κβ�����������ֻ����
			if(p-number==n-1)
				p=number;
			else
				p++;
	}
	for(i=0;i<n;i++)
		if(*(number+i)!=-1) //����ֻ����û�г���
			break;
	free(number);
	return i+1;
}

int main()
{
	int n,m;
	int num;
	scanf("%d %d",&n,&m);
	num=JosephusArray(n,m);
	printf("%d",num);
	return 0;
}
//˼�����������ԭ��Ŀ�����������ʽ��