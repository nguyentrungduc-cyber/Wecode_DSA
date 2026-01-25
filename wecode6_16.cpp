/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
#include <cmath>

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

void addTail(LIST &l, node *p)
{
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = p;
        return;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void Nhap(LIST &l)
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        addTail(l, createNode(x, y));
    }
}

float distance(node *p)
{
    return sqrt((pow(p->x, 2)) + (pow(p->y, 2)));
}

node *DiemGanGocToaDoNhat(LIST l)
{
    node *minDis = l.pHead;
    for (node *p = l.pHead->pNext; p != nullptr; p = p->pNext)
    {
        if (distance(minDis) > distance(p))
        {
            minDis = p;
            break;
        }
    }
    return minDis;
}

void Xuat(node *p)
{
    std::cout << "(" << p->x << ", " << p->y << ")";
}

int main()
{
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    std::cout << "Diem gan goc toa do nhat la: ";
    Xuat(DiemGanGocToaDoNhat(points));

    return 0;
}
