#include <iostream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Slovo.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ru");
    ifstream fin("text.txt");
    ifstream fin1("slovo1.txt");
    ifstream fin2("slovo2.txt");
    List s;
    node* slovof = NULL, * slovoc = NULL;

    cout << "Исходный текст:" << endl;
    CreateList(s);
    ReadList(fin, s);
    ResetList(s);
    WriteList(s);

    cout << "Слово, которое нужно изменить:" << endl;
    ReadSlovo(fin1, slovof);
    WriteSlovo(slovof);
    cout << "Слово, на которое нужно поменять найденные слова:" << endl;
    ReadSlovo(fin2, slovoc);
    WriteSlovo(slovoc);

    ChangeAllSlovo(s, slovof, slovoc);

    cout << "Измененный текст:" << endl;
    ResetList(s);
    WriteList(s);

    DeleteList(s);
    DeleteNode(slovof);
    DeleteNode(slovoc);

    system("pause");
    return 0;
}