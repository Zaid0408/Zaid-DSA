#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int r)
{

    while (1)
    {
        int i = l, j = r;
        while (j >= l && arr[j] > arr[l])
            j--;
        while (i <= r && arr[i] <= arr[l])   
            i++;

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
        else
        {
            swap(arr[l], arr[j]);
            return j;
        }
    }
}

void quickSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{

    int arr[] = {4, 56, 6, 54, 963, 3, 54, 56, 2, 14, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1;
    quickSort(arr, low, high);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}