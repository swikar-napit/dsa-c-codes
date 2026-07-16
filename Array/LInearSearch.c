#include<stdio.h>

int linearsearch(int arr[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(key == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {2, 3, 4, 6, 7};
    int key;
    printf("Enter the value of key: ");
    scanf("%d", &key);

    int result = linearsearch(arr, 5, key);

    if(result == -1){
        printf("Item not found\n");
    } else {
        printf("Item found at index %d\n", result);
    }

    return 0;
}