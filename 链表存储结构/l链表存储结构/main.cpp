#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int element;
	struct node* next;
}NODE,*pNODE;

/*typedef struct 
{
	int n;
	struct node* head;
}head*/;

void Init(pNODE head);
void Insert(pNODE head, int location,int data);
int Find(pNODE head, int location);
void Delete(pNODE head,int location);
void Change(pNODE head, int location, int data);
void Show(pNODE head);
void Detroy(pNODE head);

int main()
{
	pNODE head = (pNODE)malloc(sizeof(NODE));
	Init(head);

	int num;
	printf("输入要输入的元素个数：");
	scanf("%d", &num);
	printf("原数据：");
	for (int i = 0; i < num-1; i++)
	{
		Insert(head,i,i);
	}
	Show(head);
	int location, data;
	printf("输入要插入的位置：");
	scanf("%d", &location);
	printf("输入要插入的元素：");
	scanf("%d", &data);
	Insert(head, location, data);
	printf("插入后的数据：");
	Show(head);

	int location_1;
	printf("输入要查找的位置：");
	scanf("%d", &location_1);
	printf("查找到的数据：%d\n",Find(head,location_1));

	int location_2;
	printf("输入要删除的位置：");
	scanf("%d",&location_2);
	Delete(head,location_2-1);
	Show(head);

	int location_3;
	int data_1;
	printf("输入要改变的位置：");
	scanf("%d", &location_3);
	printf("输入改后的元素：");
	scanf("%d", &data_1);
	Change(head, location_3, data_1);
	Show(head);

	Detroy(head);
	system("pause");
	return 0;
}

void Init(pNODE head)
{
	head->next = NULL;
}

void Insert(pNODE head, int location, int data)
{
	int i=0;
	pNODE temp = (pNODE)malloc(sizeof(NODE));
	temp->element = data;
    //头插
	if (location<0)
	{
		return;
	}
	while(i < location)
	{
		head = head->next;
		i++;
	}
	temp->next = head->next;
	head->next = temp;

}

int Find(pNODE head, int location)
{
	int i=0;
	pNODE p = head->next;
	while (p->next!=NULL)
	{
		if (i==location)
		{
			return p->element;
		}
		else
		{
			p = p->next;
			i++;
		}
	}
	return -1;
}

void Delete(pNODE head, int location)
{
	pNODE temp;
	pNODE p;
	temp = head->next;
	if (temp==NULL)
	{
		return;
	}
	else
	{
		if (location == -1)
		{
			pNODE q;
			q = temp->next;
			free(temp);
			head->next = q;
			/*temp->next = q->next;
			head->next = temp;
			free(q);*/
			return;
		}
		else
		{
			for (int i = 0; i < location; i++)
			{
				temp = temp->next;
			}
			p = temp->next;
			temp->next = p->next;
			free(p);
		}
	}
}

void Change(pNODE head, int location,int data)
{
	pNODE temp=head->next;
	for (int i = 0; i < location; i++)
	{
		temp = temp->next;
	}
	temp->element = data;
}

void Show(pNODE head)
{
	if (head->next==NULL)
	{
		return;
	}
	while (head->next!=NULL)
	{
		printf("%d ",head->next->element);
		head = head->next;
	}
	printf("\n");
}

void Detroy(pNODE head)
{
	pNODE temp = head->next;
	while (head->next != NULL)
	{
		head->next = temp->next;
		free(temp);
		temp = head->next;
	}
	free(head);
}










//尾插
/*pNODE p = head;
while (p->next != NULL)
{
p = p->next;
}
temp->next = p->next;
p->next = temp;*/