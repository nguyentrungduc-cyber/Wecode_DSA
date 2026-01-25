/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE
{
    int key;
};
typedef NODE HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key)
{
    return key % M;
}
int HF_LinearProbing(int key, int i)
{
    return (HF(key) + i) % TableSize;
}
// ###INSERT CODE HERE -
void CreateHashTable(HASHTABLE H, int &CurrentSize)
{
    /*cin >> M;
    cin >> TableSize;
    CurrentSize = TableSize;

    // Khởi tạo tất cả ô là -1
    for (int i = 0; i < TableSize; i++)
        H[i].key = -1;

    int x;
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;

        int h = HF(x);
        int idx;

        // Thăm dò tuyến tính
        for (int i = 0; i < TableSize; i++)
        {
            idx = HF_LinearProbing(x, i);

            // Nếu ô trống → chèn vào
            if (H[idx].key == -1)
            {
                H[idx].key = x;
                break;
            }

            // Nếu đụng key trùng → không chèn
            if (H[idx].key == x)
                break;
        }
    }*/
    cin >> M;
    cin >> TableSize;
    CurrentSize = TableSize;

    for (int i = 0; i < CurrentSize; i++)
    {
        H[i].key = -1;
    }

    int x;
    while (cin >> x && x != -1)
    {
        int index = HF(x);

        if (H[index].key == -1)
            H[index].key = x;
        else if (H[index].key == x)
            continue;
        else
        {
            for (int i = 1; i < CurrentSize; i++)
            {
                int newIndex = HF_LinearProbing(x, i);

                if (H[newIndex].key == -1)
                {
                    H[newIndex].key = x;
                    break;
                }
            }
        }
    }
}

void Traverse(HASHTABLE H, int CurrentSize)
{
    // for (int i = 0; i < CurrentSize; i++)
    // {
    //     cout << i << " --> " << H[i].key;
    //     if (i < CurrentSize - 1)
    //         cout << endl;
    // }
    for (int i = 0; i < CurrentSize; i++)
    {
        cout << i << " --> " << H[i].key << endl;
    }
}

int main()
{
    HASHTABLE H;
    int CurrentSize;

    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);

    return 0;
}
