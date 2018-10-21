#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int element;
	struct node* next;
}Node;

typedef struct 
{
	Node* front;
	Node* rear;
}Queue;

void init(Queue* top);
void EnQueue(Queue* top, int data);
int Front(Queue* top); 
void DeQueue(Queue* top);
void Show(Queue* top);
bool IsEmpty(Queue* top);
void Destory(Queue* top);

int main()
{
	Queue* top = (Queue*)malloc(sizeof(Queue));
	init(top);
	printf("原有队列中元素：");
	for (int i = 0; i < 10; i++)
	{
		EnQueue(top, i);
	}
	Show(top);
	printf("队头元素：%d\n", Front(top));
	printf("删除队尾元素：");
	DeQueue(top);
	Show(top);
	Destory(top);
	system("pause");
	return 0;
}

void init(Queue* top)
{
	top->front = top->rear = NULL;
}

void EnQueue(Queue* top, int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->element = data;
	temp->next = NULL;
	if (top->rear==NULL)
	{
		top->front = temp;
		top->rear = temp;
	}
	else
	{
		top->rear->next = temp;
		top->rear=temp;
	}
}

int Front(Queue* top)
{
	return top->rear->element;
}

void DeQueue(Queue* top)
{
	if (IsEmpty(top))
	{
		return;
	}
	Node* p;
	p = top->front->next;
	top->front->next = p->next;
	free(p);
}

void Show(Queue* top)
{
	Node* p;
	p = top->front;
	while (p!=NULL)
	{
		printf("%d ", p->element);
		p = p->next;
	}
	printf("\n");
}

bool IsEmpty(Queue* top)
{
	return top->front == top->rear;
}

void Destory(Queue* top)
{
	Node* p;
	while (top->front)
	{
		p = top->front;
		top->front = p->next;
		free(p);
	}
}