#include<stdio.h>
#include<stdlib.h>

struct Node{
    int info;
    struct Node*next, * previous;
};
struct Node*first = NULL;
struct Node*last = NULL;

void insertfirst(int data){
    //create a newnode
    struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> info = data;
    newnode -> next = NULL;
    newnode -> previous = NULL;

    if(first == NULL){
        first = last = newnode;
        return;
    }
    else{
        newnode -> next = first;
        first -> previous = newnode;
        first = newnode;
    }
}

void insertlast(int data){
    //create a newnode
    struct Node*newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> info = data;
    newnode -> next = NULL;

    if(last == NULL){
        first = last = newnode;
        return;
    }
    else{
        last -> next = newnode;
        newnode -> previous = last;
        last = newnode;
    }
}

void deleteFirst(){
    if(first == NULL){
        printf("Enter list");
        return;
    }
    else if(first == last){
        free(first);
        first = last = NULL;
    }
    else{
        struct Node*temp = first;
        first = first -> next;
        free(temp);
        first -> previous = NULL;
    }
}

void deleteLast(){
    if(first == NULL){
        printf("Empty list");
        return;
    }
    else if(first == last){
        free(last);
        first = last = NULL;
    }
    else{
        struct Node*temp = last -> previous;
        while(temp -> next != last){
            temp = temp -> next;
        }
        free(last);
        last = temp;
        last -> next = NULL;
    }
}

void display(){
    if(first == NULL){
        printf("Empty list");
        return;
    }
    else{
        struct Node*temp = first;
        while(temp != NULL){
            printf("%d ->", temp -> info);
            temp = temp -> next;
        }
        printf("\n");
    }
}



int main(){
    insertfirst(10);
    insertfirst(5);
    display();

    insertlast(20);
    insertlast(25);
    display();

    deleteFirst();
    display();

    deleteLast();
    display();
    return 0;
}