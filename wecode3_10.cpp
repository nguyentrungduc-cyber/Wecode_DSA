/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100

void XuatMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;
}
// ###INSERT CODE HERE -

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void hoanvi(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selection_sort_ascending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }

        hoanvi(a[i], a[min]);
    }
}

void selection_sort_descending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[max] < a[j])
                max = j;
        }

        hoanvi(a[i], a[max]);
    }
}

void SapXepSoDuongGiamAmTangVa0(int a[], int n)
{
    int indexTang = 0, indexGiam = 0, indexKhong = 0;
    int aDuong[MAXN], aAm[MAXN], aKhong[MAXN];

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            aAm[indexTang++] = a[i];

        else if (a[i] > 0)
            aDuong[indexGiam++] = a[i];
        else
            aKhong[indexKhong++] = a[i];
    }

    selection_sort_descending(aDuong, indexGiam);
    selection_sort_ascending(aAm, indexTang);

    int index = 0;
    for (int i = 0; i < indexGiam; i++)
        a[index++] = aDuong[i];
    for (int i = 0; i < indexTang; i++)
        a[index++] = aAm[i];
    for (int i = 0; i < indexKhong; i++)
        a[index++] = aKhong[i];
}

int main()
{
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoDuongGiamAmTangVa0(a, n);
    XuatMang(a, n);
    return 0;
}
