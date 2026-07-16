#include<stdio.h>
int InsertionSort(int arr[], int n){
    for(int i=1; i<n;i++){
        int key = arr[i];
        int j= i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[5]={2,5,8,4,3};
    int i;
    InsertionSort(arr,5);
    for(i=0;i<5;i++){
        printf("%d", arr[i]);
    }
    return 0;
}