#include <iostream>
using namespace std;
void heapify(int arr[],int N,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < N && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < N && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,N,largest);
    }
}
void heap_sort(int arr[],int N){
    for(int i=N/2-1;i>=0;i--){
        heapify(arr,N,i);
    }
    for(int i=N-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]= {5,63,2,13,35,62,4,69,4,6};
    int N = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,N);
}