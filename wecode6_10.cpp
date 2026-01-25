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

void addHead(LIST &l, node *p)
{
    if (l.pHead == nullptr)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addRandom(LIST &l, int x, int y)
{
    // nếu danh sách rỗng
    if (l.pHead == nullptr)
    {
        l.pHead = l.pTail = createNode(y);
        return;
    }

    // duyệt đến khi gặp node đầu tiên có giá trị x
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        if (p->data == x)
        {
            node *pAdd = createNode(y); // tạo tại chỗ
            pAdd->pNext = p->pNext;
            p->pNext = pAdd;

            if (pAdd->pNext == nullptr)
                l.pTail = pAdd;

            return;
        }
    }

    // nếu x là node cuối
    if (l.pTail->data == x)
    {
        addTail(l, createNode(y));
        return;
    }
}

void PrintList(LIST l)
{
    if (l.pHead == nullptr)
        cout << "Empty List.";
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

void CreateList(LIST &l)
{
    int check;
    while (cin >> check && check != -1)
    {
        if (check == 0)
        {
            int x;
            cin >> x;
            addHead(l, createNode(x));
            // PrintList(l);
        }
        else if (check == 1)
        {
            int x;
            cin >> x;
            addTail(l, createNode(x));
            // PrintList(l);
        }
        else if (check == 2)
        {
            int x, y; // thêm Y sau K
            cin >> x >> y;
            addRandom(l, x, y);
            // PrintList(l);
        }
    }
}

int main()
{
    LIST L;

    L.pHead = L.pTail = NULL;

    CreateList(L);

    PrintList(L);

    return 0;
}
