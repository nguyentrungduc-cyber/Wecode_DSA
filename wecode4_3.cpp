/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
    int tmp;
    cin >> tmp;
    while (tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

// ###INSERT CODE HERE -
void Print(vector<int> v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << "\t";
    }
}

void QuickSort(vector<int> &a, int b, int e)
{
    if (a.empty())
    {
        cout << "0";
        return;
    }

    if (b >= e)
    {
        Print(a);
        // return;
    }
    int x = a[(b + e) / 2];
    int i = b, j = e;
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (b < j)
        QuickSort(a, b, j);
    if (i < e)
        QuickSort(a, i, e);
    if (b == 0 && e == a.size() - 1)
        Print(a);
}

int main()
{
    vector<int> A;
    Input(A);
    QuickSort(A, 0, A.size() - 1);
    return 0;
}
