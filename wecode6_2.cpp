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

int count_even(node *p)
{
    int result = 0;
    bool find = false;
    for (node *q = p; q != nullptr; q = q->pNext)
    {
        if (q->data % 2 == 0 )
        {
            result++;
            find = true;
        }
    }
    if (!find)
        return 0;
    else
        return result;
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}
