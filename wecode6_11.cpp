/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
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

bool tongUoc(node *p)
{
    int giaTri = p->data, result = 0;
    if (giaTri == 0)
        return false;
    for (int i = 1; i < giaTri; i++)
    {
        if (giaTri % i == 0)
            result += i;
    }
    return result == giaTri;
}

void count_perfect_number(node *q, int &count)
{
    count = 0;

    for (node *p = q; p != nullptr; p = p->pNext)
    {
        if (tongUoc(p))
        {
            count++;
        }
    }
}

int main()
{
    LIST L;
    int count;
    CreateEmptyList(L);

    CreateList(L);
    count_perfect_number(L.pHead, count);
    cout << count;

    return 0;
}
