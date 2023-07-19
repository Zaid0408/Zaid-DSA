#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool isPrime(int n){

    if(n < 2)
        return false;
        
    for(int i= 2; i<= sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

void merge(int arr[], int low, int high, int mid)
{
    int i = low, j = mid + 1;
    int b[high - low + 1];
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        b[k++] = arr[i++];
    }

    while (j <= high)
    {
        b[k++] = arr[j++];
    }

    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = b[k++];
    }
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

int main()
{
    auto start = high_resolution_clock::now();
    // cout<<start<<endl;

    int arr[] = {4, 56, 6, 54, 963, 1947, 71, 54, 56, 14, 4, 1};
    // int n = size(arr)/size(arr[0]);
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1;
    mergeSort(arr, low, high);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int flag = 0;
    for(int i=0; i<n; i++){
        if(isPrime(arr[i])){
            flag = 1;
            cout<<"First Prime = "<<arr[i]<<endl;
            break;
        }
    }

    if(flag == 0){
        cout<<"No Prime Number is present in the array"<<endl;
    }

    auto stop = high_resolution_clock::now();
    // cout << stop<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}