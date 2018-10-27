#include <stdio.h>
#include <stdlib.h>

struct Monkey{
	int code; //猴子编号
	int number; //猴子报数，如果是-1说明已经出局
	struct Monkey* next; //下一只猴子的地址
};

struct Monkey* CreateMonkey(int n){ //创建猴子链
	struct Monkey *head; //第一只猴子
	struct Monkey *tmp;
	struct Monkey *current;
	int i;
	head=(struct Monkey*)malloc(sizeof(struct Monkey));
	head->code=1;
	head->number=0;
	current=head;
	for(i=1;i<n;i++)
	{
		tmp=(struct Monkey*)malloc(sizeof(struct Monkey)); //为后来的猴子开辟空间
		tmp->code=i+1;
		tmp->number=0;
		current->next=tmp;
		current=tmp;
	}
	current->next=head; //一个环形的链表
	return head;
}

int JosephusLink(int n,int m) //用链表的方式解约瑟夫问题
{
	struct Monkey *pMonkey;
	pMonkey=CreateMonkey(n); //创建有n只猴子的链表
	struct Monkey *current=pMonkey;//当前报数的猴子
	int out=0;//出局猴子的数量
	int curNum=1;//当前报数
	while(out!=n-1)//出局猴子数量少于n-1时
	{
		if(current->number==-1)//当前猴子已经出局：不做任何操作，跳过这只猴子
			current=current->next;
		else if(curNum!=m)//当前报数不是m
		{
			current->number=curNum;
			curNum++;
			current=current->next;//注意用环形链表的话就不需要判断是否到达数组结尾
		}
		else//当前报数为m
		{
			current->number=-1;//猴子出局
			current=current->next;
			out++;//出局数量+1
			curNum=1;//报数回到1
		}
	}
	current=pMonkey;
	for(int i=0;i<n;i++)
		if(current->number!=-1)//看哪只猴子没有出局
			break;
		else
			current=current->next;
	int outCode=current->code;//记录未出局猴子的编号
	//释放链表空间
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
//思考：如何满足原题目的输入输出方式？