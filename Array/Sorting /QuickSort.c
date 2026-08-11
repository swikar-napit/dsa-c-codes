#include<stdio.h>

int partition(int a[], int L, int H){ // L is first index & H is last index
    int pivot = a[H];
    int i = L - 1;

    for(int j = L; j < H; j++){
        if(a[j] <= pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[H];
    a[H] = temp;
    return i + 1;
}

void quickSort(int a[], int L, int H){
    if(L < H){
        int j = partition(a, L, H);
        quickSort(a, L, j - 1);
        quickSort(a, j + 1, H);
    }
}

int main(){
    int a[10] = {35, 25, 23, 30, 40, 15, 4, 3, 5, 17};
    quickSort(a, 0, 9);
    printf("Element after sorting: ");
    for(int i = 0; i < 10; i++){
        printf("%d \t", a[i]);
    }
    return 0;
}