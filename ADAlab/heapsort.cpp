#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < N && arr[left] > arr[largest])
    largest = left;
 if (right < N && arr[right] > arr[largest])
    largest = right;
 if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
    heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
    }
}

int main()
{
  int arr[10000],n=1000,i;
clock_t start, end;
  double time_taken;
  for(i=0; i<n; i++)  
  {
  	arr[i]= rand();
  	printf("%d\t",arr[i]);
  }
  start=clock();
  heapSort(arr, n);
  end=clock();
  printf("\nelements of the array after sorting: ");
  for(i=0; i<n; i++)
  printf("%d\t",arr[i]);
  time_taken=((double)(end-start))/CLOCKS_PER_SEC;
  printf("\ntime taken to execute heap sort is %f seconds",time_taken);
}


