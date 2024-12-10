#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
using namespace std;
void CreateList(List& s)
{
	s.top = NULL;
	s.marker = NULL;
	s.tail = NULL;
}
void ResetList(List& s)
{
	s.marker = s.top;
}
void AddOne(List& s, char x)
{
	s.top = new node;
	s.top->data = x;
	s.top->next = NULL;
	s.tail = s.top;
	ResetList(s);
}
void AddValue(List& s, char x)
{
	s.marker = new node;
	s.marker->data = x;
	s.marker->next = NULL;
	s.tail->next = s.marker;
	s.tail = s.marker;
}
void ReadList(ifstream& f, List& s)
{
	ResetList(s);
	char x;
	if (f.peek() != EOF)
	{
		f.get(x);
		AddOne(s, x);
	}
	while (f.peek() != EOF)
	{
		f.get(x);
		AddValue(s, x);
	}
}
void WriteList(List& s)
{
	if (!s.top)
	{
		cout << "Пустой список";
	}
	else
	{
		node* p = s.marker;
		while (p != s.tail->next)
		{
			cout << p->data;
			p = p->next;
		}
	}
	cout << endl;
}
bool EmptyList(List& s)
{
	return s.top == NULL;
}
void DeleteList(List& s)
{
	ResetList(s);
	while (s.top)
	{
		s.top = s.top->next;
		delete s.marker;
		ResetList(s);
	}
}