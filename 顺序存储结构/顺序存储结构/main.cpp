#include <stdio.h>
#include <stdlib.h>

typedef struct seqlist
{
	int *element;
	int msize;
	int length;
}Seqlist;

void Init(Seqlist *list, int size);
void Insert(Seqlist *list, int location, int data);
void Delete(Seqlist *list, int size);
int Find(Seqlist* list, int data);
void Change(Seqlist *list, int location, int newdata);
void Show(Seqlist *list);
void Destroy(Seqlist*list);

int main()
{
	Seqlist list;
	int num;
	printf("输入要输入的元素个数：");
	scanf("%d",&num);
	Init(&list, num);
	printf("原数据：");
	for (int i = 0; i < num - 1; i++)
		Insert(&list, i - 1, i);
	
	Show(&list);
	printf("\n");
	int location,data;
	printf("输入要插入的位置：");
	scanf("%d",&location);
	printf("输入要插入的元素：");
	scanf("%d",&data);
	Insert(&list, location,data);
	printf("插入后的数据：");
	Show(&list);

	Delete(&list,5);
	printf("删除一个元素后的数据：");
	Show(&list);

	int location_1;
	printf("输入要查询的位置：");
	scanf("%d", &location_1);
	
	printf("查询到的元素：%d", Find(&list, location_1));
	

	Change(&list,8,999);
	printf("\n改变一个元素后的数据：");
	Show(&list);

	Destroy(&list);
	system("pause");
	return 0;
}

void Init(Seqlist *list, int size)
{
	list->msize=size;
	list->length = 0;
	list->element = (int*)malloc(sizeof(int)*size);
}

void Insert(Seqlist *list, int location, int data)
{
	int i;
	if (location<-1 || location>list->length - 1)
	{
		return;
	}
	else if (list->length==list->msize)
	{
		return;
	}
	for (i = list->length - 1; i >location; i--)
	{
		list->element[i + 1] = list->element[i];
	}
	list->element[i + 1] = data;
	list->length++;
}

void Delete(Seqlist *list, int location)
{
	if (location<0 || location>list->length)
	{
		return;
	}
	if (!list->length)
	{
		return;
	}
	for (int i = location + 1; i < list->length; i++)
	{
		list->element[i - 1] = list->element[i];
	}
	list->length--;
}

int Find(Seqlist* list, int location)
{
	if (list->length>=0 || location<=list->length)
	{
		for (int i = 0; i <= location; i++)
		{
			if (location==i)
			{
				return list->element[i];
			}
		}
		return -1;
	}
	else
		return-2;
}

void Change(Seqlist* list, int location, int newdata)
{
	if (location < 0 || location>list->length - 1)
	{
		return;
	}
	if (!list->length)
	{
		return;
	}
	list->element[location] = newdata;
}

void Show(Seqlist *list)
{
	if (!list->length)
	{
		return;
	}
	for (int i = 0; i < list->length;i++)
	{
		printf("%d ",list->element[i]);
	}
	printf("\n");
}

void Destroy(Seqlist*list)
{
	list->length = 0;
	list->msize = 0;
	free(list->element);
}
