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

void PrintList(node *p)
{
    if (p == nullptr)
        cout << "Empty List.";
    else
    {
        for (node *q = p; q != nullptr; q = q->pNext)
        {
            cout << q->data << " ";
        }
    }
}

void add_afterX_1(LIST &l, int y, int x)
{
    // x: là số kiểm tra, y là số thêm sau x
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
        {
            node *pAdd = createNode(y);
            pAdd->pNext = p->pNext;
            p->pNext = pAdd;
            break;
        }
    }
}

int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> X >> Y;
    add_afterX_1(L, Y, X);

    PrintList(L.pHead);

    return 0;
}
