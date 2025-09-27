// Liệt kê các phân đoạn Left-Right-Mid của thuật toán TÌM KIẾM NHỊ PHÂN trong quá trình tìm kiếm giá trị X có trong danh sách A hay không?
// Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử.
// Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A.

// INPUT
// Nhập giá trị các phần tử của danh sách A.
// Số nguyên X cần tìm.
// OUTPUT
// Xuất ra danh sách A sau khi sắp xếp tăng dần
// Xuất ra các phân đoạn Left-Right-Mid trong quá trình tìm kiếm.
// EXAMPLE
// Input:
// 5       8       3       5       87       0
// 5

// 5       8       3       5       87       0
// 6

// Output:
// 3       5       5       8       87
// Left=0   Right=4         Mid=2

// 3       5       5       8       87
// Left=0   Right=4         Mid=2
// Left=3   Right=4         Mid=3

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

// ###INSERT CODE HERE -
int X;

void insertSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int x = v[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (v[j] < x)
            {
                break;
            }
            v[j + 1] = v[j];
        }
        v[j + 1] = x;
    }
}

void Input(vector<int> &v)
{
    int x;
    cin >> x;
    while (x != 0)
    {
        v.push_back(x);
        cin >> x;
    }
    cin >> X;
}

void binarySearch(vector<int> &v)
{
    int n = v.size();

    insertSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "       ";
    }
    cout << endl;

    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cout << "Left=" << left << "   " << "Right=" << right << "         " << "Mid=" << mid << endl;
        if (X == v[mid])
        {
            return;
        }
        if (X > v[mid])
        {
            left = mid + 1;
        }
        else if (X < v[mid])
        {
            right = mid - 1;
        }
    }
}

int main()
{
    vector<int> A;
    Input(A);
    binarySearch(A);
    return 0;
}
