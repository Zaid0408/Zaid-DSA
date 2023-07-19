#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <time.h>
//#include <chrono>
#include<windows.h> 
#include <unistd.h>
//using namespace std::chrono;

void bubbleSort(int a[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){

    int t = 7;
    int elements[] = {5000,10000,15000,20000,25000,30000,35000};
    int k= 0;
    while(t--){
        // auto start = high_resolution_clock::now();
        clock_t tStart = clock();
        srand (time(NULL));
//        int n = rand()%1000;
		int n = elements[k++];
        int a[n];
        cout<<"Enter "<<n<<" elements:"<<endl;

        for(int i=0; i<n; i++){
            a[i] = rand()%10000;
        }

        bubbleSort(a, n);

//        cout<<"Sorted Elements :"<<endl;
        
//        for(int i=0; i<n; i++){
//            cout<<a[i]<<" ";
//        }
//        cout<<endl;

        // auto stop = high_resolution_clock::now();
        // auto duration = duration_cast<microseconds>(stop - start);
        printf("Time taken for %d size of array: %.4fs\n",n ,(double)(clock() - tStart)/CLOCKS_PER_SEC);
        // cout<<"Time taken by the program in microseconds: "<<(duration.count())<<endl;
        sleep(5);
        
    }
    return 0;

}
