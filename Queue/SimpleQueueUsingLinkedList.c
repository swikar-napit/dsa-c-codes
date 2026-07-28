//ALGORITHMS
//  Assumption -> FRONT and REAR are two global pointers initially set to NULL.

//Enqueue
//  1.START
//  2.Read/Input data items to insert.
//  3.Create a newnode
//  4.Assign data to info.
//      eg: newnode -> info = data
//  5.Assign NULL to next
//      eg: newnode->next = NULL
//  6.IF REAR = NULL Then
//      REAR = FRONT = newnode
//    ELSE 
//      REAR -> NEXT = newnode
//      REAR = newnode
//    END IF
//  7.STOP

//Dequeue
//  1.START
//  2.IF FRONT = NULL Then
//      print "Queue Underflow" & return
//    ELSE 
//      struct Node *temp = FRONT
//      item = FRONT -> info
//      FRONT = FRONT-> next
//      free(temp)
//      return item
//    END IF
//  3.STOP

//Display
//  1.START
//  2.IF FRONT = NULL Then
//      print "Empty Queue" & return
//    ELSE 
//      struct Node *temp = FRONT
//      while(temp!=NULL){
//          print(temp->info)
//          temp = temp->next
//          }
//    END IF
//  3.STOP

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *next;
};
struct Node *FRONT = NULL, *REAR = NUll;

void enqueue(int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode-> info = data;
    newnode-> next = NULL;
    if(REAR = NULL) {
        REAR = FRONT = newnode;
    }
    else{
        REAR -> next=newnode;
        REAR = newnode;
    }

}

int dequeue(){
    if(FRONT == NULL){
        printf("Queue Underflow!");
    }
    else{
        struct Node *temp = FRONT;
        int item= FRONT -> info;
        FRONT = FRONT -> next;
        free(temp);
        return item;
    }
}
void display(){
    if(FRONT == NULL){
        printf("Empty Queue");
    }
    else{
        struct Node *temp = FRONT;
        while(temp!=NULL){
            printf("%d->", temp-> info);
            temp = temp->next;
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