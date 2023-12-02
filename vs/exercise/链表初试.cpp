#include<iostream>
using namespace std;

class node
{
public:
	int num;
	node* next;
};

void listcreat(node**head ,int len)
{
	int i = 1;
	node* p = *head;
	node* q = NULL;
	p->num = 0;
	p->next = NULL;
	for (i = 1; i <= len; i++)
	{
		q = new node;
		q->next = p->next;
		q->num = i;
		p->next = q;
		q = NULL;
	}
}

int sum1(node**head, int len, void (*f)(node**, int))
{
	f(head, len);
	int i, sum = 0;
	node* p = (*head)->next;
	for (i = 1; i <= len; i++)
	{
		sum += p->num;
		if (p->next != NULL)
			p = p->next;
	}
	return sum;
}

int main()
{
	int len, sum;
	FILE *fpin = fopen("D:\\vs project\\r.txt", "r");
	FILE *fpout = fopen("D:\\vs project\\w.txt", "w");
	fscanf(fpin, "%d", &len);
	fclose(fpin);
	node** head = new node*;
	*head = new node;
	sum = ::sum1(head, len, listcreat);
	fprintf(fpout, "%d", sum);
	fclose(fpout);
	return 0;
}


