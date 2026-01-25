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

void add_after_k_th(LIST &l, int y, int k)
{
    // thêm giá trị y ở vị trí k
    int i = 1;
    node *p = l.pHead;
    while (p != nullptr)
    {
        if (i == k)
        {
            node *pAdd = createNode(y);
            pAdd->pNext = p->pNext;
            p->pNext = pAdd;
            return;
        }
        i++;
        p = p->pNext;
    }
}

int main()
{
    LIST L;
    int k, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> k >> Y;
    add_after_k_th(L, Y, k);

    PrintList(L);

    return 0;
}
