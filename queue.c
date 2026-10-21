#include <stdio.h>
#include <string.h>
#include "queue.h"

#define MAX_QUEUE 5

char queue[MAX_QUEUE][50];
int front = -1;
int rear = -1;

void enqueue(char song[])
{
    if (rear == MAX_QUEUE - 1)
    {
        printf("Playback queue is full!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    strcpy(queue[rear], song);

    printf("Song added to playback queue.\n");
}

void dequeue()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Playback queue is empty!\n");
        return;
    }

    printf("Now playing: %s\n", queue[front]);

    for (i = front; i < rear; i++)
    {
        strcpy(queue[i], queue[i + 1]);
    }

    rear--;

    if (rear < front)
    {
        front = -1;
        rear = -1;
    }
}

void displayQueue()
{
    int i;

    printf("\n===== PLAYBACK QUEUE =====\n");

    if (front == -1 || front > rear)
    {
        printf("Playback queue is empty.\n");
        return;
    }

    for (i = front; i <= rear; i++)
    {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}