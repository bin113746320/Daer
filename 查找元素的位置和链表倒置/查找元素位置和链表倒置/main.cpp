#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}Node, *pNode;

void Init(pNode head);
void Insert(pNode head, int i, int x);
//int Find(pNode head, int element);
void Reverse(pNode head);
void Show(pNode head);
void Destroy(pNode head);

int main()
{
	pNode head = (pNode)malloc(sizeof(Node));
	Init(head);
	for (int i = 0; i < 10; i++)
	{
		Insert(head, i, i + 3);
	}
	Show(head);

	/*int element;
	printf("输入要查找的元素：");
	scanf("%d", &element);
	printf("元素所在位置：%d", Find(head, element));
	printf("\n");*/

	Reverse(head);
	printf("倒置后：");
	Show(head);

	Destroy(head);

	system("pause");
	return 0;
}

void Init(pNode head)
{
	head->next =NULL;
}

void Insert(pNode head, int i, int x)
{
	pNode p = (pNode)malloc(sizeof(Node));
	p->element = x;

	if (i<-1)
	{
		return;
	}
	for (int j = 0; j < i; j++)
	{
		head = head->next;
	}

	p->next = head->next;
	head->next = p;
	
}

//int Find(pNode head, int element)
//{
//	pNode p = head->next;
//	int i = 1;
//	while (p != NULL)
//	{
//		if (p->element == element)
//		{
//			return i;
//		}
//		p = p->next;
//		i++;
//	}
//	return -1;
//}

void Reverse(pNode head)
{
	pNode q,p;
	if (head->next == NULL)
	{
		return;
	}
	q = head->next->next;
	head->next->next = NULL;
	while (q!=NULL)
	{
		p = q->next;
		q->next = head->next;
		head->next = q;
		q = p;
	}
}

void Show(pNode head)
{
	pNode p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->element);
		p = p->next;
	}
	printf("\n");
}

void Destroy(pNode head)
{
	pNode temp = head->next;
	while (head->next != NULL)
	{
		pNode p;
		p = temp->next;
		free(temp);
		temp = p;
		head->next = p;
	}
	free(head);
}