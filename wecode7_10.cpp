#include <iostream>

using namespace std;

struct NODE
{
    char info;
    NODE *pNext;
};
struct queue
{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x) // lỗi, int-> char, khỏi sài luôn
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void createQueue(queue &q)
{
    q.front = q.back = NULL;

    string s;
    getline(cin, s);

    // KHÔNG BỎ KHOẢNG TRẮNG. Giữ nguyên tất cả
    string filtered = "";
    for (char c : s)
    {
        filtered += tolower(c);
    }

    if (filtered.empty())
    {
        cout << "Empty" << endl;
        return;
    }

    for (char c : filtered)
    {
        NODE *p = new NODE;
        p->info = c;
        p->pNext = NULL;

        if (q.front == NULL)
            q.front = q.back = p;
        else
        {
            q.back->pNext = p;
            q.back = p;
        }
    }

    string original = "", reversed = "";
    for (NODE *k = q.front; k != NULL; k = k->pNext)
        original += k->info;

    for (int i = original.size() - 1; i >= 0; i--)
        reversed += original[i];

    if (original == reversed)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}

int main()
{
    queue q;
    createQueue(q);
    return 0;
}
