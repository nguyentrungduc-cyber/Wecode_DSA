/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define M 100

struct NODE
{
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE *&head, int x)
{
    NODE *p = CreateNode(x);
    if (head == NULL)
        head = p;
    else
    {
        NODE *i = head;
        while (i->pNext != NULL)
        {
            i = i->pNext;
        }
        i->pNext = p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

// ###INSERT CODE HERE -
void InitHashTable(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
        H[i] = NULL;
}

void CreateHashTable(HASHTABLE &ht, int &numbucket)
{
    cin >> numbucket;
    InitHashTable(ht, numbucket);

    int x;
    while (cin >> x && x != -1)
    {
        int index = HF(numbucket, x);
        AddTail(ht[index], x); // luôn chèn vào cuối bucket
    }
}

void TraverseBucket(HASHTABLE H, int i)
{
    NODEPTR p = H[i];
    while (p != NULL)
    {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
    {
        cout << i;
        TraverseBucket(H, i);
        cout << endl;
    }
}

int Search(HASHTABLE &H, int numbucket, int x)
{
    int index = HF(numbucket, x);
    NODEPTR p = H[index];

    while (p != NULL)
    {
        if (p->key == x)
            return index; // trả về vị trí bucket
        p = p->pNext;
    }
    return -1; // không tìm thấy
}

int main()
{
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    cin >> x;
    int i = Search(H, numbucket, x);
    cout << endl;
    if (i == -1)
        cout << x << " not found.";
    else
        cout << x << " found in bucket " << i << ".";
    return 0;
}
