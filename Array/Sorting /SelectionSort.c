#include<stdio.h>
int selectionsort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
            }
        }
    }
}
int main(){
    int arr[6]={6,5,8,2,7,4};
    int res=selectionsort(arr,2);
    for(int i=0;i<6;i++){
        printf("%d", arr[i]);
    }
return 0;
}