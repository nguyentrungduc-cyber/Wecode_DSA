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

bool isPrime(node *p)
{
    int data = p->data;
    if (data < 2)
        return false;
    if (data == 2 || data == 3)
        return true;
    if (data % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(data); i += 2)
    {
        if (data % i == 0)
            return false;
    }
    return true;
}

int search_prime(node *p)
{
    int index = 1;
    for (node *q = p; q != nullptr; q = q->pNext)
    {
        if (isPrime(q))
            return index; // tìm thấy -> trả về vị trí
        index++;
    }
    return 0; // không có số nguyên tố
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << search_prime(L.pHead);

    return 0;
}
