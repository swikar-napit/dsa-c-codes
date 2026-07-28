#include<stdio.h>
int queue[5], QSIZE = 5;
int FRONT = -1, REAR = -1;
void enqueue(int data){
    if(REAR == QSIZE -1 && FRONT == 0){
        printf("Queue Overflow!");
    }
    else if(REAR == -1){
        REAR = (REAR+1)%QSIZE;
        queue[REAR] = data;
        FRONT = 0;
    }
    else{
        REAR = (REAR+1)%QSIZE;
        queue[REAR] = data;
    }
}
int dequeue(){
    if(FRONT == -1){
        printf("Queue Underflow!");
    }
    else{
        int item = queue[FRONT];
        FRONT = (FRONT+1)%QSIZE;
        return item;
    }
}
void display(){
    if(FRONT == -1){
        printf("Empty Queue!");
    }
    else{
        if(FRONT <= REAR){
             for(int i=FRONT; i<=REAR; i++){
                printf("%d ->", queue[i]);
             }
        }
        else{
            for(int i=FRONT; i<5; i++){
                printf("%d ->", queue[i]);
            }
            for (int i=0; i<=REAR; i++){
                printf("%d ->", queue[i]);
            }
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
    printf("Deleted Item: %d\n", dequeue());
    display();
    enqueue(30);
    enqueue(35);
    display();
    return 0;
}