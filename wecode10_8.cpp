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

void InitHashTable(HASHTABLE &H, int numbucket)
{
    for (int i = 0; i < numbucket; i++)
        H[i] = NULL;
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
// ###INSERT CODE HERE -
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

bool Remove(HASHTABLE &ht, int numbucket, int x)
{
    int index = HF(numbucket, x);
    NODE *p = ht[index];
    NODE *prev = NULL;

    // Nếu bucket rỗng → không có x
    if (p == NULL)
        return false;

    // Duyệt danh sách liên kết
    while (p != NULL)
    {
        if (p->key == x)
        {
            // Nếu node cần xóa là node đầu
            if (prev == NULL)
            {
                ht[index] = p->pNext;
            }
            else
            {
                prev->pNext = p->pNext;
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->pNext;
    }

    return false; // không tìm thấy
}

//////////////////////////
int main()
{
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x))
    {
        cout << endl
             << x << ": Delete Successful." << endl
             << endl;
        Traverse(H, numbucket);
    }
    else
        cout << endl
             << x << ": Delete Failed." << endl
             << endl;

    return 0;
}
