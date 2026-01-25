/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    TREE root;
    if (inE < inB)
        return NULL;
    root = new TNode;
    if (root != NULL)
    {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB])
                break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    }
    return root;
}

// ###INSERT CODE HERE -
void Input(vector<int> &v)
{
    int x;
    while (cin >> x && x != -1)
        v.push_back(x);
}

int maxAtLevel(TREE t, int level, int k, bool &found)
{
    if (!t)
        return INT_MIN;
    if (level == k)
    {
        found = true;
        return t->key;
    }
    int L = maxAtLevel(t->left, level + 1, k, found);
    int R = maxAtLevel(t->right, level + 1, k, found);
    if (L == INT_MIN && R == INT_MIN)
        return INT_MIN;
    return max(L, R);
}

bool existLevel(TREE t, int level, int k)
{
    if (!t)
        return false;
    if (level == k)
        return true;
    return existLevel(t->left, level + 1, k) ||
           existLevel(t->right, level + 1, k);
}

void Fun(TREE t)
{
    int k;
    cin >> k;

    if (t == NULL)
    {
        cout << "Empty Tree";
        return;
    }

    // Mức gốc = 0
    if (!existLevel(t, 0, k))
    {
        cout << "No Find";
        return;
    }

    bool found = false;
    int mx = maxAtLevel(t, 0, k, found);
    if (!found || mx == INT_MIN)
    {
        cout << "No Find";
    }
    else
    {
        cout << mx;
    }
}

int main()
{
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num = duyetNLR.size() - 1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    return 0;
}
