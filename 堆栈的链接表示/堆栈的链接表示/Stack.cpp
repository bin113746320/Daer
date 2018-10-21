#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
	int element;
	struct stack * next;
}Stack;

void init(Stack* top);
void Push(Stack* top,int data);
int Top(Stack* top);
void Pop(Stack* top);
void Show(Stack* top);
bool Isempty(Stack* top);
void Destory(Stack* top);

int main()
{
	Stack* top = (Stack*)malloc(sizeof(Stack));
	init(top);
	printf("Ô­ÓÐÕ»ÖÐÔªËØ£º");
	for (int i=0; i < 10;i++)
	{
		Push(top, i);
	}
	Show(top);
	printf("Õ»¶¥ÔªËØ£º%d\n", Top(top));
	printf("É¾³ýÕ»¶¥ÔªËØ£º");
	Pop(top);
	Show(top);
	system("pause");
	return 0;
}

void init(Stack* top)
{
	top->next = NULL;
}

void Push(Stack* top, int data)
{
	Stack* temp=(Stack*)malloc(sizeof(Stack));
	temp->element = data;
	temp->next = top->next;
	top->next = temp;
}

bool Isempty(Stack* top)
{
	return top->next == NULL;
}

int Top(Stack* top)
{
	if (Isempty(top))
	{
		return false;
	}
	return top->next->element;
}

void Pop(Stack* top)
{
	Stack* p;
	p = top->next;
	top->next = p->next;
	free(p);
}

void Show(Stack* top)
{
	Stack* p;
	p = top->next;
	while (p)
	{
		printf("%d ",p->element);
		p = p->next;
	}
	printf("\n");
}

void Destory(Stack* top)
{
	Stack* p;
	while (top->next)
	{
		p = top->next;
		top->next = p->next;
		free(p);
	}
}