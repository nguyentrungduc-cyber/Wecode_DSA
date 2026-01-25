#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

// Tạo node mới
TNODE *CreateNode(int x)
{
    TNODE *p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// Chèn node vào BST
int Insert(TREE &T, int x)
{
    if (T)
    {
        if (T->key == x)
            return 0;
        if (x < T->key)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}

// Tạo cây
void CreateTree(TREE &T)
{
    int x;
    cin >> x;
    if (x == -1)
    {
        T = NULL;
        return;
    }
    T = CreateNode(x);
    while (cin >> x && x != -1)
    {
        Insert(T, x);
    }
}

// Tìm cây có root->key = x
TNODE *SearchNode(TREE T, int x)
{
    if (T == NULL)
        return NULL;
    if (T->key == x)
        return T;
    if (x < T->key)
        return SearchNode(T->pLeft, x);
    return SearchNode(T->pRight, x);
}

// Tìm cha của node X
TNODE *FindParent(TREE T, int x)
{
    if (T == NULL || T->key == x)
        return NULL;

    if ((T->pLeft && T->pLeft->key == x) ||
        (T->pRight && T->pRight->key == x))
        return T;

    if (x < T->key)
        return FindParent(T->pLeft, x);
    return FindParent(T->pRight, x);
}

// Tìm sibling
void FindSiblings(TREE T, int x)
{
    if (T == NULL)
    {
        cout << "Empty Tree.";
        return;
    }

    TNODE *nodeX = SearchNode(T, x);
    if (nodeX == NULL)
    {
        cout << "Not found " << x << ".";
        return;
    }

    if (T->key == x)
    {
        cout << x << " is Root.";
        return;
    }

    TNODE *parent = FindParent(T, x);

    // Nếu parent có đầy đủ 2 con → chắc chắn là siblings
    if (parent->pLeft != NULL && parent->pRight != NULL)
    {
        cout << parent->pLeft->key << " and "
             << parent->pRight->key << " are siblings.";
        return;
    }

    // Parent chỉ có 1 con
    cout << x << " has no siblings.";
}

int main()
{
    TREE T = NULL;
    CreateTree(T);

    int x;
    cin >> x;

    FindSiblings(T, x);

    return 0;
}
