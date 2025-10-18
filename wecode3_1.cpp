/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

// ###INSERT CODE HERE -
#include <iostream>
#include <algorithm>

#define MAXN 100000

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
}

bool is_ascending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
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

int main()
{
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_sort_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
