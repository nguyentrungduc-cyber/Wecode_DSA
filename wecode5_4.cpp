/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
#include <cmath>
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

void add_after_all_prime(LIST &l, int y)
{
    for (node *p = l.pHead; p != nullptr;)
    {
        if (isPrime(p))
        {
            node *pAdd = createNode(y);
            pAdd->pNext = p->pNext;
            p->pNext = pAdd;
            p = pAdd->pNext;
        }
        else
            p = p->pNext;
    }
}

void PrintList(LIST l)
{
    if (l.pHead == nullptr)
        cout << "Empty List.";
    else
    {
        for (node *p = l.pHead; p != nullptr; p = p->pNext)
        {
            cout << p->data << " ";
        }
    }
}

int main()
{
    LIST L;
    int Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_all_prime(L, Y);

    PrintList(L);

    return 0;
}
