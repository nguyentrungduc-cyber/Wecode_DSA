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
    {
        v.push_back(x);
    }
}

int treeMax(TREE t)
{
    // Trường hợp cây rỗng hoặc là nút lá
    if (t == NULL)
    {
        // Giả sử giá trị khóa luôn < 1000. Trả về một giá trị rất nhỏ để so sánh
        return -1;
    }

    // Giá trị lớn nhất khởi tạo là khóa của nút gốc hiện tại
    int max_val = t->key;

    // Tìm giá trị lớn nhất trong cây con trái
    int left_max = treeMax(t->left);

    // Tìm giá trị lớn nhất trong cây con phải
    int right_max = treeMax(t->right);

    // So sánh và cập nhật max_val
    if (left_max > max_val)
        max_val = left_max;

    if (right_max > max_val)
        max_val = right_max;

    return max_val;
}

void Fun(TREE t)
{
    if (t == nullptr)
    {
        cout << "Empty Tree";
        return;
    }
    cout << treeMax(t);
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
