#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool ifFull(Queue Q);
void enQueue(Queue &Q, int x);
int deQueue(Queue &Q);
void printInfo(Queue Q);

#endif