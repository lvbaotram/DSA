#include <iostream>
#include <time.h>
using namespace std;
void input_array(int *&a, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 100 + 1;
        *(a + i) = temp;
    }
}
void IncreaseArray(int *&a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i)> *(a + j))
            {
                swap(*(a + i), *(a + j));
            }
        }
    }
}
int linearSearch(int *&a, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == x)
            return i;
    }
    return -1;
}

int binarySearch(int *&a, int l, int r, int x)
{
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(*(a + mid) == x)
        {
            return mid;
        }
        else if(*(a + mid) < x)
        {
            l = mid + 1;
        }
        else   
        {     
            r = mid - 1;
        }
    }
    return -1;
}
void out_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< *(a + i)<<" ";
    }
    cout << endl;
}
int main()
{
    int n, x, idx;
    int *a = new int [n];
    cout <<"Nhap so phan tu n: ";
    cin >> n;
    input_array(a, n);
    out_array(a, n);
    cout << "Gia tri can tim la: ";
    cin >> x;
    cout << "Tim kiem bang Linear Search: " << endl;
    idx = linearSearch(a, n, x);
    if (idx == -1)
    {
        cout << "Khong tim duoc phan tu trong mang co gia tri la " << x <<endl;
    }
    else 
    {
        cout << "Vi tri cua phan tu mang gia tri " << x << " trong mang la " << idx +1 <<endl;
    }
    cout << "Tim kiem bang Binary Search: " << endl;
    IncreaseArray(a, n);
    cout << "Mang tang dan: ";
    out_array(a, n);
    idx = binarySearch(a, 0, n, x);
    if (idx == -1)
    {
        cout << "Khong tim duoc phan tu trong mang co gia tri la " << x << endl;
    }
    else 
    {
        cout << "Vi tri cua phan tu mang gia tri " << x << " trong mang la " << idx + 1 <<endl;
    }
    return 0;
}