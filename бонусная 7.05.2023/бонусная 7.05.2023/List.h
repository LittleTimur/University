#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
using namespace std;
struct List
{
	node* top;
	node* tail;
	node* marker;
};
void CreateList(List&);
void ResetList(List&);
void AddOne(List&, char);
void AddValue(List&, char);
void ReadList(ifstream&, List&);
void WriteList(List&);
bool EmptyList(List&);
void DeleteList(List&);