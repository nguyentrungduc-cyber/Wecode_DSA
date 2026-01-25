#include <iostream>
using namespace std;

// ###INSERT CODE HERE -
struct NODE
{
    int info;
    NODE *pNext;
};

struct stack
{
    NODE *pHead;
};

void CreateEmptyStack(stack &s)
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

void Push(stack &s, NODE *p)
{
    if (s.pHead == NULL)
        s.pHead = p;
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}

int Pop(stack &s, int &x)
{
    if (s.pHead == NULL)
        return 0;
    NODE *p = s.pHead;
    s.pHead = s.pHead->pNext;
    x = p->info;
    delete p;
    return 1;
}

void array_reverse(stack &s, int a[], int n)
{
    cin >> n; // đọc n (do main không nhập n)
    for (int i = 0; i < n; i++)
        cin >> a[i];

    CreateEmptyStack(s);

    // Đưa các phần tử mảng vào stack
    for (int i = 0; i < n; i++)
    {
        NODE *p = CreateNode(a[i]);
        Push(s, p);
    }

    // Pop ngược ra để đảo mảng
    for (int i = 0; i < n; i++)
    {
        int x;
        Pop(s, x);
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    stack s;
    int a[100], n;
    array_reverse(s, a, n);
    return 0;
}
