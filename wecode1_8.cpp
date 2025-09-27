/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// ###INSERT CODE HERE -
int binary_search_last_occurrence(int a[], int n, int x)
{
    int mid;
    int right = n - 1;
    int left = 0;
    int maxMid = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            if (mid > maxMid)
            {
                maxMid = mid;
                continue;
            }
        }
        if (x > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

    return maxMid;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}
