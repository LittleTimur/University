#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
using namespace std;
bool FindBKV(List&);
void FindTail(List&);
void GetSlovo(List&, bool&);
bool SameSlovo(List, node*);
node* PreviousSimvol(List&);
void DeleteSlovo(List&, node*);
void ChangeOneSlovo(List&, node*);
void CopySlovo(node*, node*&);
void ChangeAllSlovo(List&, node*&, node*&);