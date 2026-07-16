// binary search 
#include<stdio.h>
int binarysearch(int arr[], int key, int low, int high){
    while(low<=high){
        int mid= low+(high-low)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key>=arr[mid]){
            low = mid+1;
        }
        else if(key<arr[mid]){
            high = mid-1;
        }

    }
    return -1;
}
int main(){
    int arr[5]={1,2,3,4,5};
    int key;
    printf("Enter the value of Key ");
    scanf("%d",&key);
    int res = binarysearch(arr,key,0,4);
    if(res==-1){
        printf("Item Not FOund");
    }
    else{
        printf("The item is %d", res);
    }
    return 0;
}