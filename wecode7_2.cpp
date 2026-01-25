#include <iostream>
using namespace std;

struct NODE
{
    int info;
    NODE *pNext;
};

struct Stack
{
    NODE *pHead;
};

void CreateEmptyStack(Stack &s)
{
    s.pHead = NULL;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void Push(Stack &s, NODE *p)
{
    if (s.pHead == NULL)
        s.pHead = p;
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

int Pop(Stack &s, int &x)
{
    if (s.pHead == NULL)
        return 0;
    NODE *p = s.pHead;
    s.pHead = s.pHead->pNext;
    x = p->info;
    delete p;
    return 1;
}

void PrintStack(Stack s)
{
    for (NODE *p = s.pHead; p != NULL; p = p->pNext)
        cout << p->info;
    cout << endl;
}

void decimal_to_binary(int n)
{
    Stack s;
    CreateEmptyStack(s);

    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    while (n != 0)
    {
        NODE *p = CreateNode(n % 2);
        Push(s, p);
        n /= 2;
    }

    PrintStack(s);
}

int main()
{
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
