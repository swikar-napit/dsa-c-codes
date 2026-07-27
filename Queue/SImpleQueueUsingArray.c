#include<stdio.h>
int queue[5], QSIZE = 5;
int FRONT = -1, REAR = -1;
void enqueue(int data){
    if(REAR == QSIZE -1){
        printf("Queue Overflow!");
    }
    else if(REAR == -1){
        REAR++;
        queue[REAR] = data;
        FRONT = 0;
    }
    else{
        REAR++;
        queue[REAR] = data;
    }
}
int dequeue(){
    if(FRONT == -1){
        printf("Queue Underflow!");
    }
    else{
        int item = queue[FRONT];
        FRONT++;
        return item;
    }
}
void display(){
    if(FRONT == -1){
        printf("Empty Queue!");
    }
    else{
        for(int i=FRONT; i<=REAR; i++){
            printf("%d ->", queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    printf("Deleted Item: %d\n", dequeue());
    display();
    return 0;
}