#include <iostream>
using namespace std;

struct node
{
    int data;
    node *pNext;
};

node *createNode(int data)
{
    node *p = new node;
    p->data = data;
    p->pNext = nullptr;
    return p;
}

struct stack
{
    node *pTop;
};

void createEmptyStack(stack &s)
{
    s.pTop = nullptr;
}

void push(stack &s, node *p)
{
    p->pNext = s.pTop;
    s.pTop = p;
}

int top(stack &s)
{
    // if (s.pTop == nullptr)
    //     return;
    return s.pTop->data;
}

void pop(stack &s)
{
    if (s.pTop == nullptr)
        return;

    node *pTemp = s.pTop;
    s.pTop = pTemp->pNext;
    delete pTemp;
}

void Testing_Push_Pop_Top_Stack(stack &s)
{

    int n = 0;
    int array[10000];

    createEmptyStack(s);

    int x;
    while (cin >> x && x != -1)
    {
        if (x != 0)
        {
            push(s, createNode(x));
        }
        else
        {
            if (s.pTop != nullptr)
            {
                int val = top(s);
                pop(s);
                array[n] = val;
                n++;
            }
        }
    }

    cout << "output: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
    if (s.pTop == nullptr)
        cout << "top: ";
    else
        cout << "top: " << s.pTop->data;
}

int main()
{
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}
