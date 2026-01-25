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

int countChildNode(TREE t)
{
    if (t == NULL)
        return 0;
    return 1 + countChildNode(t->pLeft) + countChildNode(t->pRight);
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE Root)
{
    if (Root != NULL)
    {
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(Root->pLeft);

        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(Root->pRight);
        if ((countChildNode(Root->pLeft)) - (countChildNode(Root->pRight)) == 1)
            cout << Root->key << " ";
    }
}

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);
    return 0;
}
