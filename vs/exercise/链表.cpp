#include<iostream>
using namespace std;

struct node
{
	int value;
	node* next;
};

int Listcreat(node**);
int output(node**);
int find(node** head);
int insert(node**, int);
int erase(node**, int);

int main()
{
	freopen("D:\\vs project\\r.txt", "r", stdin);
	int len;
	node** head = new node*;
	
	len = Listcreat(head);
	
	output(head);

	find(head);
	
	len = insert(head, len);

	output(head);

	len = erase(head, len);

	output(head);
	return 0;
}

int Listcreat(node** head)
{
	int i, len;
	cout << "please input len:" << endl;
	cin >> len;
	*head = new node;
	(*head)->next = NULL;
	node* p = *head;
	node* q = NULL;
	for (i = 1; i <= len; i++)
	{
		q = (node*)malloc(sizeof(node));
		q->next = p->next;
		p->next = q;
		p = q;
		cout << "please input value" << i << ":" << endl;
		cin >> p->value;
	}
	cout << "-----listcreation finished-----" << endl;
	return len;
}

int output(node** head)
{
	int len;
	node* p = (*head)->next;
	cout << "list text:" << endl;
	for (len = 0; p != NULL; len++)
	{
		cout << "value" << len + 1 << " " << p->value << endl;
		p = p->next;
	}
	cout << "len is " << len << endl;
	return len;
}

int find(node** head)
{
	int i, ele;
	cout << "please input you want to find:" << endl;
	cin >> ele;
	node* p = (*head)->next;
	for (i = 1; p != NULL; i++)
	{
		if (p->value == ele)
		{
			cout << "The position is " << i << endl;
			return i;
		}
		p = p->next;
	}
	cout << "-----nofind-----" << endl;
	return 0;
}

int insert(node** head, int len)
{
	int i, pos, ele;
	cout << "please input position and element:" << endl;
	cin >> pos >> ele;
	if (pos > len)
	{
		cout << "operate error" << endl;
		return len;
	}
	node* p = *head;
	node* q = new node;
	for (i = 1; i < pos; i++)
		p = p->next;
	q->next = p->next;
	p->next = q;
	q->value = ele;
	return len + 1;
}

int erase(node** head, int len)
{
	int i, pos;
	cout << "please input position which you want to earse:" << endl;
	cin >> pos;
	if (pos > len)
	{
		cout << "-----ERROR-----" << endl;
		return len;
	}
	node* p = *head;
	node* q = NULL;
	for (i = 1; i < pos; i++)
		p = p->next;
	q = p->next;
	p->next = p->next->next;
	delete q;
	return len - 1;
}