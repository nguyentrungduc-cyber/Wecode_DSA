/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

// ###INSERT CODE HERE -
void Input(vector<int> &v)
{
    int x;
    cin >> x;
    while (x != 0)
    {
        v.push_back(x);
        cin >> x;
    }
}

void xuatBuoc(const vector<int> &v, int i, int e)
{
    cout << "i=" << i << ":    e=" << e << ":    ";
    for (int x : v)
        cout << x << "       ";
    cout << endl;
}

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int bienTam = v[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] < bienTam)
                break;
            v[j + 1] = v[j];
        }
        v[j + 1] = bienTam;
        xuatBuoc(v, i, bienTam);
    }
}

int main()
{
    vector<int> A;
    Input(A);
    insertionSort(A);
    return 0;
}
