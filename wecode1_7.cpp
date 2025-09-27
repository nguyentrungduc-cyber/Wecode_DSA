// Tìm vị trí cuối cùng của số lớn nhất nhưng nhỏ hơn giá trị X trong mảng 1 chiều lưu n phần tử ( <=400,000) các số nguyên (< 2 tỷ).
//  Nếu không tìm thấy xuất ra -1. Chú ý: Sử dụng hàm tìm kiếm nhị phân (không dùng đệ quy), giá trị X có thể không tồn tại trong mảng.

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N)
{
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_greatestLesser_last_occurrence(int a[], int n, int x)
{
    int left = 0, right = n - 1, mid, result = -1;
    while (left <= right)
    {
        mid = (right + left) / 2;
        if (a[mid] < x)
        {
            left = mid + 1;
            result = mid;
        }
        else
            right = mid - 1;
    }
    return result;
}

int main()
{
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_greatestLesser_last_occurrence(a, n, x);
    return 0;
}
