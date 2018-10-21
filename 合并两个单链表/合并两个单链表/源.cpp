#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int element;
	struct node* next;
}Node ,*pNode;

void Init(pNode head);
void Insert(pNode head, int i, int x);
void Merge(pNode head1, pNode head2);
void Show(pNode head);
void Destroy(pNode head);

int main()
{
	pNode head1 = (pNode)malloc(sizeof(Node));
	Init(head1);
	int element1[6] = {2,4,5,6,7,8};
	for (int i = 0; i<6;i++){
		
		Insert(head1,i,element1[i]);
	}
	printf("链表1：");
	Show(head1);

	pNode head2 = (pNode)malloc(sizeof(Node));
	Init(head2);
	int element2[7] = { 0,1,3, 5, 7,9,10};
	for (int i = 0; i<7; i++ ){
		Insert(head2, i, element2[i]);
	}
	printf("链表2：");
	Show(head2);

	printf("合并后：");
    Merge(head1,head2);
	Show(head1);

	Destroy(head1);
	system("pause");
	return 0;
}

void Init(pNode head)
{
	head->next= NULL;
}

void Insert(pNode head, int i, int x)
{
	for (int j = 0; j <i ;j++)
	{
		head = head->next;
	}
	pNode temp = (pNode)malloc(sizeof(Node));
	temp->element = x;
    temp->next = head->next;
	head->next = temp;
}

void Merge(pNode head1, pNode head2)
{
	pNode p;
	pNode q;
	pNode temp1;
	pNode temp2;
	p = head1;
	q = head2;
	while (q->next!=NULL&&p->next!=NULL)
	{
		if (p->next->element>q->next->element)
		{
			temp1 = q->next;
			q->next =temp1->next;
			temp1->next = p->next;
			p->next = temp1;
			p = p->next;
		}
	
		while (p->next != NULL&&p->next->element<q->next->element)
		{
			p = p->next;
		}
		if (p->next != NULL&&p->next->element == q->next->element)
		{
			q = q->next;
		} 
		else if (p->next == NULL)
		{
			p->next = q->next;
			break;
		}
		else
		{
			temp2 = q->next;
			q->next = temp2->next;
			temp2->next = p->next;
			p->next = temp2;
		}
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
		head->next = temp->next;
		free(temp);
		temp = head->next;
	}
	free(head);
}
