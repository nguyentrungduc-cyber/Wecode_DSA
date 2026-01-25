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
void createEmptyTree(TREE &t)
{
    t = nullptr;
}

// TREE createNode(int x)
// {
//     TREE p = new TNODE;
//     p->key = x;
//     p->pLeft = nullptr;
//     p->pRight = nullptr;
//     return p;
// }

// void insert(TREE &t, int x)
// {
//     if (t)
//     {
//         if (t->key == x)
//             return;
//         else if (t->key > x)
//             insert(t->pLeft, x);
//         else if (t->key < x)
//             insert(t->pRight, x);
//     }
//     t = createNode(x);
// }

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

void Task01(TREE t)
{
    if (t != nullptr)
    {
        Task01(t->pLeft);
        cout << t->key << " ";
        Task01(t->pRight);
    }
}

void PrintTree(TREE t)
{
    if (t == nullptr)
    {
        cout << "Empty Tree.";
    }
    else
    {
        Task01(t);
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
