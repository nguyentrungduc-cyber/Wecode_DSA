/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>

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
    while (std::cin >> x && x != -1)
        addTail(l, createNode(x));
}

int countList(LIST l)
{
    int result = 0;
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        result++;
    }
    return result;
}

void Remove_k_th(LIST &l, int k)
{
    // không có node
    if (l.pHead == nullptr)
        return;
    int n = countList(l);
    // nếu n < k -> return
    if (n < k || k <= 0)
        return;
    // nếu chỉ có 1 node và k == 1
    if (n == 1 && k == 1)
    {
        delete l.pHead;
        l.pHead = l.pTail = nullptr;
        return;
    }
    // nếu có nhiều node và k == 1
    if (n > 1 && k == 1)
    {
        node *p = l.pHead;
        l.pHead = p->pNext;
        delete p;
        return;
        // nếu chỉ có 2 node, pTail vẫn vậy chỉ thêm vai trò pHead
    }
    // nếu có nhiều node và k == n, tức xóa node cuối thì phải tìm được node trước nó
    // tiện thể xóa node giữa luôn
    // tìm node trước vị trí k
    node *pGoto = l.pHead; // chạy đến vị trí k
    node *pPre = nullptr;  // chạy đến vị trí k - 1
    for (int i = 1; i < k && pGoto->pNext != nullptr; i++)
    {
        pPre = pGoto;
        pGoto = pGoto->pNext;
    }
    if (n > 1 && k == n)
    {
        delete l.pTail;
        l.pTail = pPre;
        l.pTail->pNext = nullptr;
    }
    if (k > 1 && k < n)
    {
        node *pTemp = pPre->pNext;
        pPre->pNext = pTemp->pNext;
        delete pTemp;
        return;
    }
}

void PrintList(LIST l)
{
    if (l.pHead == nullptr)
    {
        std::cout << "Empty List.";
        return;
    }
    for (node *p = l.pHead; p != nullptr; p = p->pNext)
    {
        std::cout << p->data << " ";
    }
}

int main()
{
    LIST L;
    int k;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> k;
    Remove_k_th(L, k);
    PrintList(L);

    return 0;
}