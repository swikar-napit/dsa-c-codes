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
    int choice,data;
    while(1){
        printf("1.Push\n2.Pop\n3.Peek\n4.View\n5.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter value to insert: ");
                    scanf("%d", &data);
                    push(data);
                    break;

            case 2: printf("Deleted Item : %d\n", pop());
                    break;

            case 3: printf("Item at Top : %d\n", peek());
                    break;

            case 4: view();
                    break;

            case 5: printf("Exiting...\n");
                    return 0;

            default: printf("Invalid Choice\n");
        }
    }
}