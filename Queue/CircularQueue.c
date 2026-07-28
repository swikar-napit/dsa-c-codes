#include <stdio.h>

int queue[5], QSIZE = 5;
int FRONT = -1, REAR = -1, count = 0;

void enqueue(int data) {
    if (count == QSIZE) {
        printf("Queue Overflow!\n");
        return;
    }

    if (FRONT == -1) {
        FRONT = 0;
    }

    REAR = (REAR + 1) % QSIZE;
    queue[REAR] = data;
    count++;
}

int dequeue() {
    if (count == 0) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int item = queue[FRONT];

    if (count == 1) {
        FRONT = -1;
        REAR = -1;
    } else {
        FRONT = (FRONT + 1) % QSIZE;
    }

    count--;
    return item;
}

void display() {
    if (count == 0) {
        printf("Empty Queue!\n");
        return;
    }

    int i = FRONT;
    for (int j = 0; j < count; j++) {
        printf("%d -> ", queue[i]);
        i = (i + 1) % QSIZE;
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();

    printf("Deleted Item: %d\n", dequeue());
    display();

    enqueue(20);
    enqueue(25);
    display();

    return 0;
}