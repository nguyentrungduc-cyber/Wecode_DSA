/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 200000

void NhapMang(int A[], int &N)
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ###INSERT CODE HERE -
void Heapify(int A[], int n, int k)
{
    int j = 2 * k + 1;
    while (j < n)
    {
        if (j + 1 < n && A[j] > A[j + 1])
            j = j + 1;
        if ((A[k] <= A[j]))
            return;
        swap(A[k], A[j]);
        k = j;
        j = 2 * k + 1;
    }
}

void buildHeap(int a[], int n)
{
    int i = (n - 1) / 2;
    while (i >= 0)
    {
        Heapify(a, n, i);
        i--;
    }
}

void HeapSort(int a[], int n)
{
    int heapSize;
    heapSize = n;
    buildHeap(a, heapSize);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapSize -= 1;
        Heapify(a, heapSize, 0);
    }
}

void XuatMang(int A[], const int &N)
{
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main()
{
    int a[MAXN], n;

    NhapMang(a, n);

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}
