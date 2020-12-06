#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		//一定要牢记，你的cur一定不敢写cur++，因为你加的只是一个指针的大小，但是你怎么敢保证他的下一个地址刚好为一个指针的大小，大小时不确定的
		cur = cur->nest;
	}
	printf("NUll\n");
}
//创建一个新结点，由于这个会在后面多次调用，所以封装一下
SListNode* BuySListNode(SLDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->nest = NULL;
	return newNode;
}
//尾插
void SListPushBack(SListNode** pphead, SLDateType x)
{
	if (*pphead == NULL)
	{
		SListNode* newNode = BuySListNode(x);
		*pphead = newNode;
	}
	else
	{
		SListNode* tail = *pphead;
		//找尾
		while (tail->nest != NULL)
		{
			tail = tail->nest;//这里要是想不通可以看课件上面的那个图
		}
		SListNode* newNode = BuySListNode(x);
		tail->nest = newNode;
	}
}

//尾删
void SListPopBack(SListNode** pphead)
{
	//1.空
	//2.一个结点
	//3.一个以上结点
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->nest == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pphead;
		while (tail->nest != NULL)
		{
			prev = tail;
			tail = tail->nest;
		}
		free(tail);
		tail = NULL;
		prev->nest = NULL;
	}
}