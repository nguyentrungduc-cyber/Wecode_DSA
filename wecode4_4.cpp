
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

int dem = 0;
void quickSort(vector<int> &a, int b, int e)
{
    if (b >= e)
        return;
    int x = a[(b + e) / 2], i = b, j = e;
    while (i < j)
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
    dem++;
    quickSort(a, b, j);
    quickSort(a, i, e);
}

void Sort(vector<int> &A)
{
    if (A.empty())
    {
        cout << "0";
        return;
    }
    quickSort(A, 0, A.size() - 1);
    cout << dem;
}

int main()
{
    vector<int> A;
    Input(A);
    Sort(A);

    return 0;
}
