#include <stdio.h>
#include <stdlib.h>

struct Monkey{
	int code; //���ӱ��
	int number; //���ӱ����������-1˵���Ѿ�����
	struct Monkey* next; //��һֻ���ӵĵ�ַ
};

struct Monkey* CreateMonkey(int n){ //����������
	struct Monkey *head; //��һֻ����
	struct Monkey *tmp;
	struct Monkey *current;
	int i;
	head=(struct Monkey*)malloc(sizeof(struct Monkey));
	head->code=1;
	head->number=0;
	current=head;
	for(i=1;i<n;i++)
	{
		tmp=(struct Monkey*)malloc(sizeof(struct Monkey)); //Ϊ�����ĺ��ӿ��ٿռ�
		tmp->code=i+1;
		tmp->number=0;
		current->next=tmp;
		current=tmp;
	}
	current->next=head; //һ�����ε�����
	return head;
}

int JosephusLink(int n,int m) //������ķ�ʽ��Լɪ������
{
	struct Monkey *pMonkey;
	pMonkey=CreateMonkey(n); //������nֻ���ӵ�����
	struct Monkey *current=pMonkey;//��ǰ�����ĺ���
	int out=0;//���ֺ��ӵ�����
	int curNum=1;//��ǰ����
	while(out!=n-1)//���ֺ�����������n-1ʱ
	{
		if(current->number==-1)//��ǰ�����Ѿ����֣������κβ�����������ֻ����
			current=current->next;
		else if(curNum!=m)//��ǰ��������m
		{
			current->number=curNum;
			curNum++;
			current=current->next;//ע���û�������Ļ��Ͳ���Ҫ�ж��Ƿ񵽴������β
		}
		else//��ǰ����Ϊm
		{
			current->number=-1;//���ӳ���
			current=current->next;
			out++;//��������+1
			curNum=1;//�����ص�1
		}
	}
	current=pMonkey;
	for(int i=0;i<n;i++)
		if(current->number!=-1)//����ֻ����û�г���
			break;
		else
			current=current->next;
	int outCode=current->code;//��¼δ���ֺ��ӵı��
	//�ͷ�����ռ�
	struct Monkey *pTmp=pMonkey;
	struct Monkey *pNow;
	for(int i=0;i<n;i++)
	{
		if(i<n-1)
		{
			pNow=pTmp->next;
			free(pTmp);
			pTmp=pNow;
		}
		else
			free(pTmp);
	}
	return outCode;
}
/*
int main()
{
	int n,m;
	int num;
	scanf("%d %d",&n,&m);
	num=JosephusLink(n,m);
	printf("%d",num);
	return 0;
}
*/
//˼�����������ԭ��Ŀ�����������ʽ��