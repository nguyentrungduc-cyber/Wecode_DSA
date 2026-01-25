/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    node *pNext;
};

node *createNode(int x)
{
    node *p = new node();
    p->data = x;
    p->pNext = nullptr;
    return p;
}

struct LIST
{
    node *pHead;
    node *pTail;
};

void CreateEmptyList(LIST &l)
{
    l.pHead = l.pTail = nullptr;
}

void addHead(LIST &l, node *p)
{
    if (l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void CreateList(LIST &l)
{
    int x;
    while (cin >> x && x != -1)
        addHead(l, createNode(x));
}

int countDigit(node *p)
{
    int number = p->data, count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int sumDigit(node *p)
{
    int number = p->data, sum = 0, count = countDigit(p);
    while (number > 0)
    {
        sum += pow((number % 10), count);
        number /= 10;
    }
    return sum;
}

void PrintList_Armstrong(LIST l)
{
    if (l.pHead == nullptr)
        cout << "Empty List.";
    else
    {
        bool find = false;
        for (node *p = l.pHead; p != nullptr; p = p->pNext)
        {
            if (sumDigit(p) == p->data && p->data > 0)
            {
                cout << p->data << " ";
                find = true;
            }
        }
        if (!find)
            cout << "Không có số armstrong trong mảng.";
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
