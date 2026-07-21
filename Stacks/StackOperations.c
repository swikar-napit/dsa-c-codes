//IMPORTANT FOR EXAMINATION 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node *next;
};
struct Node *TOP = NULL;

void push(int data){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = data;
    newnode->next = NULL;
    if(TOP == NULL){
        TOP = newnode;
    }
    else{
        newnode->next = TOP;
        TOP = newnode;
    }
}

int pop(){
    if(TOP==NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        struct Node *temp=TOP;
        int item = TOP->info;
        TOP = TOP->next;
        free(temp);
        return item;
    }
}

int peek(){
    if(TOP == NULL){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return TOP->info;
    }
}

void view(){
    if(TOP==NULL){
        printf("Empty Stack\n");
    }
    else{
        struct Node *temp = TOP;
        while(temp!=NULL){
            printf("%d->",temp->info);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    view();                  // 30->20->10->
    printf("Peek: %d\n", peek());   // 30

    printf("Popped: %d\n", pop());  // 30
    printf("Popped: %d\n", pop());  // 20

    view();                  // 10->

    printf("Popped: %d\n", pop());  // 10
    printf("Popped: %d\n", pop());  // Stack Underflow, -1

    return 0;
}