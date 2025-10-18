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
void Print(vector<int> &A, int b, int e, int x)
{
    cout << "Phan hoach doan left=" << b << " - right=" << e << " - pivot=" << x << ":\n";
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
        if (i != A.size() - 1)
            cout << "       ";
    }
    cout << endl;
}

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
    Print(a, b, e, x);

    quickSort(a, b, j);
    quickSort(a, i, e);
    // ouput
    // Print(a, b, e, x);
    // if (b < j)
    //     quickSort(a, b, j);
    // if (i < e)
    //     quickSort(a, i, e);
}

void Sort(vector<int> &A)
{
    if (A.empty())
        return;
    quickSort(A, 0, A.size() - 1);
}

int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
