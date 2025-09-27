// Liệt kê các vị trí tìm thấy X trong danh sách A bằng thuật toán TÌM KIẾM TUYẾN TÍNH Nếu không tìm thấy thì xuất ra "No Find"
// Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử.
// Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A.

// INPUT
// Nhập giá trị các phần tử của danh sách A.
// Số nguyên X cần tìm.

// OUTPUT
// Nếu tìm thấy, xuất tất cả vị trí tìm thấy. Ngược lại xuất "No Find".

// EXAMPLE
// Input
// 5       8       3       5       87       0
// 87
//
// 5       8       3       5       87       0
// 0
//
// 5       8       3       5       87       0
// 5
// Output:
// 4
//
// No Find
//
// 0 3

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

// ###INSERT CODE HERE -
int X;

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

void linearSearch(vector<int> &v)
{
    int n = v.size();
    bool find = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == X)
        {
            cout << i << " ";
            find = true;
        }
    }
    if (find == false)
       cout << "No Find";
      
}

int main()
{
    vector<int> A;
    Input(A);
    linearSearch(A);
    return 0;
}
