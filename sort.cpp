#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define SIZE 100000
using namespace std;
void input_array(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 1000 + 1;
        a[i] = temp;
    }
}
// Selection Sort
void SelectionSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
    int min = i;
    for(int j = i + 1; j < n; j++)
        if(a[j] < a[min])
        {
            min = j;
        }
        if(min != i)
        {
            swap(a[i], a[min]); 
        }
    }
}
// Insertion Sort
void InsertionSort(int a[], int n){
	for (int i = 1; i < n; ++i) {
        int value = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > value; --j)
            a[j + 1] = a[j];
        a[j + 1] = value;
    }
}
//Binary Insertion Sort
int binarySearch(int a[], int item, int low, int high){
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
  
    int mid = (low + high) / 2;
    if (item == a[mid])
        return mid + 1;
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);

    return binarySearch(a, item, low, mid - 1);
}

void BinaryInsertionSort(int a[], int n){
	for (int i = 1; i < n; i++){
		int j = i - 1;
		int value = a[i];
        int location = binarySearch(a,value,0,j);
			while (j >= location){
				a[j + 1] = a[j];
				j--;
			}
		a[j+1] = value;
	}
}
//Bubble Sort
void BubbleSort(int a[], int n){
    for (int j = n; j > 1; --j) 
        for (int i = 1; i < j; ++i)
            if (a[i - 1] > a[i]) 
                swap(a[i - 1], a[i]);
} 
//Shaker Sort
void ShakerSort(int a[], int n)
{
    int L = 0, R = n - 1;
    while (L < R) {
        for (int i = L; i < R; ++i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        --R;
        for (int i = R - 1; i >= L; --i)
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        ++L;
    }
}
//Shell Sort
void ShellSort(int a[], int n)
{
    int gaps[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    for (int gap : gaps) 
    {
        for (int i = gap; i < n; ++i) 
        {
            int cur = a[i];
            int j = i;
            for (; j >= gap && a[j - gap] > cur; j-= gap)
                a[j] = a[j - gap];
            a[j] = cur;
        }
    }
}
//Heap Sort
void heapify(int a[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i +2;
    int largest = i;
    if (l <n && a[l] >a[largest])
    {
        largest = l;
    }
    if (r <n && a[r] >a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap (a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void HeapSort(int a[], int n)
{
    for (int i= n/2 -1 ; i>= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n-1; i>= 0 ; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
//Merge Sort
void Merge (int a[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    int n = right - left + 1;
    int *B = new int[n];
    while ((i < mid + 1) && (j < right + 1))
    {
        if (a[i] < a[j])
        {
            B[k] = a[i];
            k++; i++;
        }
        else
        {
            B[k] =a[j];
            k++; j++;
        }
    }
    while (i <mid+1)
    {
        B[k] = a[i];
        k++; i++;
    }
    while (j < right+1)
    {
        B[k] = a[j];
        k++; j++;
    }
    i = left;
    for(k = 0; k <n; k++){
        a[i] = B[k];
        i++;
    }
    delete [] B;
}
void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right )/2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        Merge(a, left, mid, right);
    }
}
//Quick Sort
int partition(int a[], int l, int r) 
{
	int i = l - 1, j = r; 
	int32_t v = a[r];
	for (;;) {
		while (a[++i] < v);
		while (v < a[--j]) if (j == l) break;
		if (i >= j) break;
			swap(a[i], a[j]);
	}
	swap(a[i], a[r]);
	return i;
}

void QuickSort(int a[], int l, int r) 
{
	if (r <= l) return;
	int i = partition(a, l, r);
	QuickSort(a, l, i - 1);
	QuickSort(a, i + 1, r);
}
//Counting Sort
class cSort
{
public:
    void sort( int* arr, int len )
    {
	int mi, mx, z = 0; findMinMax( arr, len, mi, mx );
	int nlen = ( mx - mi ) + 1; int* temp = new int[nlen];
	memset( temp, 0, nlen * sizeof( int ) );
 
	for( int i = 0; i < len; i++ ) temp[arr[i] - mi]++;
 
	for( int i = mi; i <= mx; i++ )
	{
	    while( temp[i - mi] )
	    {
		arr[z++] = i;
		temp[i - mi]--;
	    }
	}
 
	delete [] temp;
    }
 
private:
    void findMinMax( int* arr, int len, int& mi, int& mx )
    {
	mi = INT_MAX; mx = 0;
	for( int i = 0; i < len; i++ )
	{
	    if( arr[i] > mx ) mx = arr[i];
	    if( arr[i] < mi ) mi = arr[i];
	}
    }
};

//Radix Sort
int getMax(int a[], int n) 
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
  return max;
}

void countingSort(int a[], int n, int place) 
{
    const int max = 10;
    int output[200000];
    int count[max];
    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / place) % 10]++;
    }
    for (int i = 1; i < max; i++)
    {   
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
void radix_sort_DnC(int a[], int level, int l, int r) {
    if (l == r || level < 0) return;
    int left = l, right = r;
    while (left <= right) {
        while (!(a[left] >> level & 1)) ++left;
        while (a[right] >> level & 1) --right;
        if (left <= right) {
            swap(a[left], a[right]);
            ++left;
            --right;
        }
    }
    if (left < r)
        radix_sort_DnC(a, level - 1, left, r);
    if (l < right)
        radix_sort_DnC(a, level - 1, l, right);
}

void RadixSort(int a[], int n) 
{
    int level = 0;
    while ((1 << level) < n) ++level;
    radix_sort_DnC(a, level, 0, n - 1);
}
//Flash Sort
void FlashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	InsertionSort(a, n);
}

//Run time random input
double out_random(int a[], int n, int i)
{
    input_array(a, n);
    clock_t start, end;
    double duration;	
	start = clock();
    if (i == 0)
    {
        SelectionSort(a, n);
    }
    if (i == 1)
    {
        InsertionSort(a, n);
    }
    if (i == 2)
    {
        BinaryInsertionSort(a, n);
    }
    if (i == 3)
    {
        BubbleSort(a, n);
    }
    if (i == 4)
    {
        ShakerSort(a, n);
    }
    if (i == 5)
    {
        ShellSort(a, n);
    }
    if (i ==6 )
    {
        HeapSort(a, n);
    }
    if (i == 7)
    {
        MergeSort(a, 0, n);
    }
    if (i == 8)
    {
        QuickSort(a, 0, n);
    }
    if (i == 9)
    {
        cSort s; 
        s.sort( a, n );
    }
    if (i == 10)
    {
        RadixSort(a, n);
    }
    if (i == 11)
    {
        FlashSort(a, n);
    }
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}
//Ham sap xep tang dan
void inscrease_sort(int a[], int n)
{
    srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
			a[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i +1 ; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
//Run time Sorted Input
double out_increase(int a[], int n, int i)
{
    clock_t start, end;
    double duration;	
	start = clock();
    if (i == 0)
    {
        SelectionSort(a, n);
    }
    if (i == 1)
    {
        InsertionSort(a, n);
    }
    if (i == 2)
    {
        BinaryInsertionSort(a, n);
    }
    if (i == 3)
    {
        BubbleSort(a, n);
    }
    if (i == 4)
    {
        ShakerSort(a, n);
    }
    if (i == 5)
    {
        ShellSort(a, n);
    }
    if (i ==6 )
    {
        HeapSort(a, n);
    }
    if (i == 7)
    {
        MergeSort(a, 0, n);
    }
    if (i == 8)
    {
        QuickSort(a, 0, n);
    }
    if (i == 9)
    {
        cSort s; 
        s.sort( a, n );
    }
    if (i == 10)
    {
        RadixSort(a, n);
    }
    if (i == 11)
    {
        FlashSort(a, n);
    }
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}

//Ham tao giam dan
void Reversed(int a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
	{
		for (int j = i +1 ; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}
//Run time Reversed Input
double out_reversed (int a[], int n, int i)
{
    clock_t start, end;
    double duration;	
    start = clock();
    if (i == 0)
    {
        SelectionSort(a, n);
    }
    if (i == 1)
    {
        InsertionSort(a, n);
    }
    if (i == 2)
    {
        BinaryInsertionSort(a, n);
    }
    if (i == 3)
    {
        BubbleSort(a, n);
    }
    if (i == 4)
    {
        ShakerSort(a, n);
    }
    if (i == 5)
    {
        ShellSort(a, n);
    }
    if (i ==6 )
    {
        HeapSort(a, n);
    }
    if (i == 7)
    {
        MergeSort(a, 0, n);
    }
    if (i == 8)
    {
        QuickSort(a, 0, n);
    }
    if (i == 9)
    {
        cSort s; 
        s.sort( a, n );
    }
    if (i == 10)
    {
        RadixSort(a, n);
    }
    if (i == 11)
    {
        FlashSort(a, n);
    }
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    return duration;
}
string intToStr(int n)
{
    stringstream temp;
    temp <<n;
    return temp.str();
}
int main()
{
    int n;
    int *a = new int[SIZE];
    string filename;
    int arr[5] = {1000, 3000, 10000, 30000, 100000};
    //mkdir("C://Users//Tram//DSA//EX//Output");
    ofstream file;
    ofstream file1("Runtime.csv");
    file1 <<"Input State"<<","<<"Input Size"<<","<<"Selection"<<",""Insertion"<<","<<"Binary Insertion"<<","<<"Bubble"<<","<<"Shaker"<<","<<"Shell"<<","<<"Heap"<<","<<"Merge"<<","<<"Quick"<<","<<"Counting"<<","<<"Radix"<<","<<"Flash"<<endl;
    string sort[12] = {"Selection","Insertion","Binary Insertion","Bubble","Shaker","Shell","Heap","Merge","Quick","Counting","Radix","Flash"};
    for (int i = 0; i < 5; i++)
    {
        int k=0;
        file1 <<"Random"<<","<<arr[i]<<",";
        for (int j = 0; j < 12; j++)
        {
            file1 << out_random(a, arr[i], j)<<",";
            filename = sort[j] + "_Random_" + intToStr(arr[i]) +".txt";
            file.open(filename.c_str());
            for (int k = 0; k < arr[i]; k++)
            {
                file<< a[k]<<" ";
            }
            file <<"\n======================================================================================\n";
            file.close();
        }
        file1 << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        file1 <<"Sorted"<<","<<arr[i]<<",";
        for (int j = 0; j < 12; j++)
        {
            inscrease_sort(a, arr[i]);
            file1 << out_increase(a, arr[i], j)<<",";
            filename = sort[j] + "_Sorted_" + intToStr(arr[i]) +".txt";
            file.open(filename.c_str());
            for (int k = 0; k < arr[i]; k++)
            {
                file<< a[k]<<" ";
            }
            file <<"\n======================================================================================\n";
            file.close();
        }
        file1 << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        file1 <<"Decrease"<<","<<arr[i]<<",";
        for (int j = 0; j < 12; j++)
        {
            Reversed(a, arr[i]);
            file1 << out_reversed(a, arr[i], j)<<",";
            filename = sort[j] + "_Reversed_" + intToStr(arr[i]) +".txt";
            file.open(filename.c_str());
            for (int k = 0; k < arr[i]; k++)
            {
                file<< a[k]<<" ";
            }
            file <<"\n======================================================================================\n";
            file.close();
        }
        file1 << endl;
    }
    file1.close();
    delete[] a;
    return 0;
}
