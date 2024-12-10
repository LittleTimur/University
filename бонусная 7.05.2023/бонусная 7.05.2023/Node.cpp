#include <iostream>
#include <fstream>
#include "Node.h"
using namespace std;
bool EmptyNode(node* top)
{
	return top == NULL;
}
void pushBack(node*& top, char x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	if (EmptyNode(top))
		top = p;
	else
	{
		node* q = top;
		while (!EmptyNode(q->next))
			q = q->next;
		q->next = p;
	}
}
void ReadSlovo(ifstream& f, node*& top)
{
	char x;
	while (f.peek() != EOF)
	{
		f.get(x);
		pushBack(top, x);
	}
}
void WriteSlovo(node* top)
{
	if (EmptyNode(top))
		cout << "Слова нет";
	else
	{
		node* p = top;
		while (!EmptyNode(p))
		{
			cout << p->data;
			p = p->next;
		}
	}
	cout << endl;
}
void DeleteNode(node*& top)
{
	while (!EmptyNode(top))
	{
		node* p = top->next;
		delete top;
		top = p;
	}
}