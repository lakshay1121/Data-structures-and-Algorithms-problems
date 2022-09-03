//Most Important.



#include <bits/stdc++.h>
using namespace std;

void print(int arr[] , int n){

    for(int i = 0 ; i < n ; i++){

        cout<<arr[i] <<" ";

    }

    cout<<endl;
}

void heapify(int arr[] , int n , int i){

    int largest = i;

    int leftIdx = 2 * i + 1;

    int rightIdx = 2 * i + 2;

    if(leftIdx < n && arr[leftIdx] > arr[largest]){

        largest = leftIdx;
    }

    if(rightIdx < n && arr[rightIdx] > arr[largest]){

        largest = rightIdx;
    }

    if(largest != i){
    
      swap(arr[largest] , arr[i]);

      heapify(arr, n , largest);

    }
}

void buildTree(int arr[] , int n ){

    for(int i = n / 2 ; i >= 0 ; i--){

        heapify(arr , n , i );
    }
}





int main()
{

    int arr[] = {54,53,55,52,50};

    int n = sizeof(arr) / sizeof(arr[0]);

    buildTree(arr, n);

    print(arr , n);

    return 0;
}
