/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

// ###INSERT CODE HERE -
TNODE *createNode(int x)
{
    TNODE *p;
    p = new TNODE; // cấp phát vùng nhớ động
    if (p == NULL)
        exit(1); // thoát
    p->key = x;  // gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int insert(TREE &T, int x)
{
    if (T)
    {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return insert(T->pLeft, x);
        return insert(T->pRight, x);
    }
    T = createNode(x);
    return 1;
}

void CreateTree(TREE &t)
{
    int x;
    while (cin >> x && x != -1)
        insert(t, x);
}

int CountLeaf(TREE t)
{
    if (t == nullptr)
        return 0;
    int sum = 0;
    if (t->pLeft == nullptr && t->pRight == nullptr)
        sum = 1;
    return sum + CountLeaf(t->pLeft) + CountLeaf(t->pRight);
}

void CountLeaf(TREE t, int &count)
{
    if (t == nullptr)
        count = 0;
    count = CountLeaf(t);
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int count = 0;
    CountLeaf(T, count);
    cout << count;
    return 0;
}
