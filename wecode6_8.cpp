/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <cmath>
#include <iostream>

// ###INSERT CODE HERE -
using namespace std;
struct node
{
    int x, y;
    node *pNext;
};

node *createNode(int x, int y)
{
    node *p = new node();
    p->x = x;
    p->y = y;
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

void addTail(LIST &l, int x, int y)
{
    node *pAdd = createNode(x, y);
    if (l.pHead == nullptr)
        l.pHead = l.pTail = pAdd;
    else
    {
        l.pTail->pNext = pAdd;
        l.pTail = pAdd;
    }
}

void Nhap(LIST &l)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        addTail(l, x, y);
    }
}

void Xuat(LIST l)
{
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << "(" << p->x << ", " << p->y << ")" << endl;
    }
}

main()
{
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    Xuat(points);

    return 0;
}
