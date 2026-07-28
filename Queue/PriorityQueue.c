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
    else{ //Ascending Priority Queue
        int item = queue[FRONT];
        int index = FRONT;
        for(int i=FRONT; i<=REAR; i++){
            if(queue[i]<item){
                item = queue[i];
                index = i;
            }
        }
        //SHift the items one step backward
        for(int i=index; i<=REAR; i++){
            queue[i]=queue[i+1];
        }
        REAR--;
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
    enqueue(10);
    enqueue(5);
    enqueue(12);
    enqueue(2);
    enqueue(7);
    display();
    printf("Deleted Item: %d\n", dequeue());
    display();
    display();
    printf("Deleted Item: %d\n", dequeue());
    display();
    return 0;
}