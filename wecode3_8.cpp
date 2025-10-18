/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100

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

void SapXepSoAmTangDan(int a[], int n)
{
    int index = 0;
    int b[MAXN];                // mảng phụ lưu các giá trị âm
    for (int i = 0; i < n; i++) // cần duyệt hết mảng chính để kiểm tra
    {
        if (a[i] < 0)
            b[index++] = a[i];
    }

    selection_sort_ascending(b, index); // sắp xếp mảng phụ

    int index2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            a[i] = b[index2++];
    }
}

void XuatMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}

int main()
{
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
