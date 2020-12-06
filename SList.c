#include"SList.h"

void SListPrint(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		//һ��Ҫ�μǣ����curһ������дcur++����Ϊ��ӵ�ֻ��һ��ָ��Ĵ�С����������ô�ұ�֤������һ����ַ�պ�Ϊһ��ָ��Ĵ�С����Сʱ��ȷ����
		cur = cur->nest;
	}
	printf("NUll\n");
}
//����һ���½�㣬����������ں����ε��ã����Է�װһ��
SListNode* BuySListNode(SLDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	newNode->date = x;
	newNode->nest = NULL;
	return newNode;
}
//β��
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
		//��β
		while (tail->nest != NULL)
		{
			tail = tail->nest;//����Ҫ���벻ͨ���Կ��μ�������Ǹ�ͼ
		}
		SListNode* newNode = BuySListNode(x);
		tail->nest = newNode;
	}
}

//βɾ
void SListPopBack(SListNode** pphead)
{
	//1.��
	//2.һ�����
	//3.һ�����Ͻ��
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