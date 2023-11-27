#include <iostream>
using namespace std;
void InsertionSort(int arr[],int N){
    for(int i=1;i<N;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]= {5,63,2,13,35,62,4,69,4,6};
    int N = sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr,N);
}