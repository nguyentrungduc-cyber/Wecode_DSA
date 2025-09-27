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

int binary_search_first_occurrence(int a[], int n, int x)
{
    int mid;
    int right = n - 1;
    int left = 0;
    int minMid;
    int step = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (a[mid] == x)
        {
            if (mid < minMid)
            {
                minMid = mid;
                step++;
            }
        }
        if (x > a[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (step != 0)
        return minMid;
    return -1;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_first_occurrence(a, n, x);

    return 0;
}
