#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Slovo.h"
using namespace std;
bool FindBKV(List& text)
{
	bool b = false;
	node* p = text.marker;
	while (p && !b)
	{
		if (p->data == ' ')
			p = p->next;
		else
		{
			b = true;
			text.marker = p;
		}
	}
	return b;
}
void FindTail(List& text)
{
	node* p = text.marker;
	bool b = false;
	text.tail = text.marker;
	while (!b)
	{
		if (p == NULL || p->data == ' ')
			b = true;
		else
		{
			text.tail = p;
			p = p->next;
		}
	}
}
void GetSlovo(List& text, bool& found)
{
	found = FindBKV(text);
	if (found)
		FindTail(text);
}
bool SameSlovo(List text, node* slovo)
{
	bool b = true;
	node* p = text.marker;
	while (p != text.tail->next && slovo != NULL && b)
	{
		if (p->data != slovo->data)
			b = false;
		p = p->next;
		slovo = slovo->next;
	}
	if (slovo != NULL || p != text.tail->next)
		b = false;
	return b;
}
node* PreviousSimvol(List& text)
{
	node* q = text.top, *pr = NULL;
	while (q && q != text.marker)
	{
		pr = q;
		q = q->next;
	}
	if (q == text.marker)
		return pr;
	return NULL;
}
void DeleteSlovo(List& text, node* p)
{
	node* q = text.tail->next;
	while (text.marker != q)
	{
		p->next = text.marker->next;
		delete text.marker;
		text.marker = p->next;
	}
	text.tail = p;
}
void ChangeOneSlovo(List& text, node* slovo)
{
	node* prev = PreviousSimvol(text);
	node* p = slovo;
	while (p->next)
		p = p->next;
	p->next = text.marker;
	if (text.top == text.marker)
		text.top = slovo;
	else
		prev->next = slovo;
	DeleteSlovo(text, p);
}
// slovof -  Слова, которые мы ищем в тескте для замены
// slovoс -  Слово, на которое мы заменяем искомые слова
void CopySlovo(node*copyslovo, node*& slovo)
{
	slovo = NULL;
	while (copyslovo)
	{
		pushBack(slovo, copyslovo->data);
		copyslovo = copyslovo->next;
	}
}
void ChangeAllSlovo(List& text, node*& slovof, node*& slovoc)
{
	node* copyslovoc = NULL;
	CopySlovo(slovoc, copyslovoc);
	bool foundNext;
	GetSlovo(text, foundNext);
	while (foundNext)
	{
		if (SameSlovo(text, slovof))
		{
			ChangeOneSlovo(text, slovoc);
			CopySlovo(copyslovoc, slovoc);
		}
		else
			text.marker = text.tail->next;
		GetSlovo(text, foundNext);
	}
}