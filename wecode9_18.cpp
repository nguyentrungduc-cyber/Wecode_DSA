/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <queue>
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

void PrintAncestors(TREE t, int x)
{
	if (t == nullptr)
	{
		cout << "Empty Tree.";
		return;
	}
	if (t->key == x)
	{
		cout << "Node is root.";
		return;
	}
	if (SearchNode(t, x) == nullptr)
	{
		cout << "-1";
		return;
	}
	TREE parent = FindParent(t, x);
	while (parent != nullptr)
	{
		cout << parent->key << " ";
		parent = FindParent(t, parent->key);
	}
}

int main()
{
	TNODE *T;
	int x;

	cin >> x;

	T = NULL;
	CreateTree(T);

	PrintAncestors(T, x);

	return 0;
}
