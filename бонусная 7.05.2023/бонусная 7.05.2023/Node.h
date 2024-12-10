#pragma once
#include <iostream>
using namespace std;
struct node
{
	char data;
	node* next;
};
void pushBack(node*&, char);
bool EmptyNode(node*);
void ReadSlovo(ifstream&, node*&);
void WriteSlovo(node*);
void DeleteNode(node*&);
