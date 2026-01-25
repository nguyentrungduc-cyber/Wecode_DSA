/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *pNext;
};

node *createNode(int x)
{
    node *p = new node;
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

void addTail(LIST &l, node *p)
{
    if (l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void CreateList(LIST &l)
{
    int x;
    while (cin >> x && x != -1)
        addTail(l, createNode(x));
}

int findMax(node *p)
{
    int maxValue = p->data;
    bool find = false;
    for (node *q = p->pNext; q != nullptr; q = q->pNext)
    {
        if (maxValue < q->data)
        {
            find = true;
            maxValue = q->data;
            break;
        }
    }
    if (!find)
    {
        return -1;
    }
    else
        return maxValue;
}

void Function(node *q)
{
    if (q == nullptr)
    {
        cout << "Empty List.";
    }
    for (node *p = q; p != nullptr; p = p->pNext)
    {
        cout << p->data << " " << findMax(p) << endl;
    }
}

int main()
{
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);

    Function(L.pHead);

    return 0;
}