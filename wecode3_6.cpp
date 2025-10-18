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

void xuatBuoc(const vector<int> &v, int i)
{
    cout << "i=" << i << ":    ";
    for (int x : v)
        cout << x << "       ";
    cout << endl;
}

void hoanvi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[max] < v[j])
                max = j;
        }

        hoanvi(v[i], v[max]);
        xuatBuoc(v, i);
    }
}

int main()
{
    vector<int> A;
    Input(A);
    selectionSort(A);
    return 0;
}
