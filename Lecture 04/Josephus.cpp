#include <stdio.h>
#include <stdlib.h>
//用数组方式解约瑟夫问题
int JosephusArray(int n,int m) //求解约瑟夫问题，输入n,m，返回值为猴王编号
{
	int* number;
	number=(int *)malloc(sizeof(int)*n); //number：目前猴子们报的数，如果是-1说明已经出局
	int out=0; //数有几只猴子出局了
	int current=1; //当前报数
	int *p=number; //当前报数的猴子
	int i;
	for(i=0;i<n;i++)
		*(number+i)=0; //初始化
	while(out!=n-1) //出局数量少于n-1时
	{
		if(*p!=-1 && current!=m) //当前猴子还没有出局，而且当前报数不是m
		{
			*p=current;
			current++;
			if(p-number==n-1) //下一只猴子，注意数据循环到结尾时要跳到数组开头
				p=number;
			else
				p++;
		}
		else if (current==m && *p!=-1) //当前猴子还没有出局，当前报数是m
		//else if(current==m)//错误写法
		{
			*p=-1; //猴子出局
			current=1; //报数回到1
			out++; //出局数量+1
			if(p-number==n-1) //下一只猴子
				p=number;
			else
				p++;
		}
		else //当前的猴子已经出局，就不做任何操作，跳过这只猴子
			if(p-number==n-1)
				p=number;
			else
				p++;
	}
	for(i=0;i<n;i++)
		if(*(number+i)!=-1) //看哪只猴子没有出局
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
//思考：如何满足原题目的输入输出方式？