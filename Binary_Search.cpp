#include <iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int key){
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int main(){
    int key;
    int arr[15] = {1,2,4,5,6,7,8,9,11,13,34,56,67,87,98};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"enter key: ";
    cin>>key;
    cout<<BinarySearch(arr,1,size,key);
}