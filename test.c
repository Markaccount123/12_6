#include "SeqList.h"
//����ͷβ����ɾ��
void TestSeqList1()
{
	SeqList s;  // �������ʼ������ṹ�壬���涼�����ֵ
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 6);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s,2,5);
	SeqListPrint(&s);

	SeqListErase(&s,2);
	SeqListPrint(&s);

	

	int pos = SeqListFind(&s, 5);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}
	SeqListPrint(&s);

	SeqListDestory(&s);

}

int main()
{
	TestSeqList1();
	return 0;
}
//˳����ȱ��---һ���̶ȵ��˷ѿռ�
//Ϊ���ܸ��õĽ��������������������������

