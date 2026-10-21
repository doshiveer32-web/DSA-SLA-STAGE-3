#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX 5

char recentSongs[MAX][50];
int top = -1;

void push(char song[])
{
    if (top == MAX - 1)
    {
        printf("Recently played stack is full!\n");
        return;
    }

    top++;
    strcpy(recentSongs[top], song);

    printf("Song added to recently played.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Recently played stack is empty.\n");
        return;
    }

    printf("Removed: %s\n", recentSongs[top]);
    top--;
}

void displayRecent()
{
    int i;

    printf("\n===== RECENTLY PLAYED =====\n");

    if (top == -1)
    {
        printf("No recently played songs.\n");
        return;
    }

    for (i = top; i >= 0; i--)
    {
        printf("%d. %s\n", top - i + 1, recentSongs[i]);
    }
}