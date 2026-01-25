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
#include <cmath>

void Input(vector<int> &v)
{
    int x;
    while (cin >> x && x != -1)
        v.push_back(x);
}

bool isPrime(TREE Node)
{
    int value = Node->key;
    if (value < 2)
        return false;
    if (value == 2 || value == 3)
        return true;
    if (value % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(value); i += 2)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}

int CountPrimeTree(TREE Root)
{
    if (Root == nullptr)
        return 0;

    int count = 0;
    if (isPrime(Root))
        count = 1;
    // Đệ quy sang trái và phải
    return count + CountPrimeTree(Root->left) + CountPrimeTree(Root->right);
}

void Fun(TREE t)
{
    // CreateEmptyTree(t);

    if (t == nullptr)
    {
        cout << "Empty Tree";
        return;
    }
    cout << CountPrimeTree(t);
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
