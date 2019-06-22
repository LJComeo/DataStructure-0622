#include "SeqList.h"
#include <assert.h>

void SeqListInit(SeqList* psl, size_t capicity)//初始化
{
	assert(psl);
	psl->capicity = capicity;
	psl->array = (SLDataType *)malloc((sizeof(SLDataType)*capicity));
	assert(psl->array);
	psl->size = 0;
}

void SeqListDestory(SeqList* psl)//销毁函数
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
		psl->array = NULL;
		psl->size = 0;
		psl->capicity = 0;
	}
}

void CheckCapacity(SeqList* psl)//检查容量
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->capicity *= 2;
		psl->array = (SLDataType *)realloc(psl->array, psl->capicity*sizeof(psl->array, psl->capicity, psl->size));
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)//尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)//尾删
{
	assert(psl || psl->size);
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)//头插
{
	assert(psl);
	int i;
	for (i = psl->size-1; i >=0; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;
}

void SeqListPopFront(SeqList* psl)//头删
{
	assert(psl);
	int i;
	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

void SeqListPrint(SeqList* psl)//输出
{
	assert(psl);
	int i;
	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	putchar('\n');
}

int SeqListFind(SeqList* psl, SLDataType x)//查找
{
	assert(psl);
	int i;
	psl->size--;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)//中间插入
{
	assert(psl || pos<=psl->size);
	int i;
	for (i = psl->size - 1; i >= pos; i--)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}

void SeqListErase(SeqList* psl, size_t pos)//中间删除
{
	assert(psl || pos < psl->size);
	int i;
	psl->size--;
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
}

void SeqListRemove(SeqList* psl, SLDataType x)//删除其中的一个元素
{
	assert(psl);
	int pos = SeqListFind(&psl, x);;
	if (pos >= 0)
	{
		SeqListErase(&psl, pos);
	}
	
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)//将一个元素改成另外一个元素
{
	assert(psl || pos < psl->size);
	psl->array[pos-1] = x;
}