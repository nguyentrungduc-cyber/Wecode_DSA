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
void Heapify(vector<int> &A, int k, int n)
{
    int j = 2 * k + 1;
    while (j < n)
    {
        if (j + 1 < n && A[j] < A[j + 1])
            j = j + 1;
        if (A[k] >= A[j])
            return;
        swap(A[k], A[j]);
        k = j;
        j = 2 * k + 1;
    }
}

void print(vector<int> v, int n)
{
    if (n >= 2)
    {
        cout << "N=" << n << "\n";
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
                cout << "       ";
        }
        cout << "\n";
    }
}

void buildHeap(vector<int> &A, int n)
{
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        Heapify(A, i, n);
        i--;
    }
}

void Sort(vector<int> &A)
{
    if (A.empty())
        return;
    int n = (int)A.size();
    buildHeap(A, n);

    while (n > 0)
    {
        swap(A[0], A[n - 1]);
        print(A, n);
        n = n - 1;
        Heapify(A, 0, n);
    }
}

int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
