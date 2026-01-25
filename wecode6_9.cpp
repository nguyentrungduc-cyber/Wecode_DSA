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

int countList(LIST l)
{
    int result = -1;
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        result++;
    }
    return result;
}

void add_after_middle(LIST &l, int y)
{
    if (l.pHead == nullptr)
        return;

    int n = countList(l);
    int mid = n / 2;
    // if (n % 2 == 0)
    //     mid--;

    node *p = l.pHead;

    // Nếu chỉ có 1 phần tử
    if (l.pHead == l.pTail)
    {
        node *pAdd = createNode(y);
        l.pHead->pNext = pAdd;
        l.pTail = pAdd;
        return;
    }

    // Nếu có đúng 2 phần tử
    if (l.pHead->pNext == l.pTail)
    {
        node *pAdd = createNode(y);
        pAdd->pNext = l.pHead->pNext;
        l.pHead->pNext = pAdd;
        return;
    }

    // Di chuyển đến node giữa
    for (int i = 0; i < mid && p->pNext != nullptr; i++)
        p = p->pNext;

    // Thêm sau node giữa
    node *pAdd = createNode(y);
    pAdd->pNext = p->pNext;
    p->pNext = pAdd;

    if (pAdd->pNext == nullptr)
        l.pTail = pAdd;
}

void PrintList(LIST l)
{
    if (l.pHead == nullptr)
        cout << "Empty List.";
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << p->data << " ";
    }
}

int main()
{
    LIST L;
    int X, Y;

    CreateEmptyList(L);

    CreateList(L);

    std::cin >> Y;
    add_after_middle(L, Y);

    PrintList(L);

    return 0;
}
