#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

struct Node *head = NULL;

void addSong()
{
    struct Node *newNode;
    struct Node *temp;
    int choice;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n===== ADD SONG TO PLAYLIST =====\n");
    printf("1. Believer\n");
    printf("2. Perfect\n");
    printf("3. Faded\n");
    printf("4. Blinding Lights\n");

    printf("Enter song number: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input!\n");

        while (getchar() != '\n');

        free(newNode);
        return;
    }

    switch (choice)
    {
        case 1:
            strcpy(newNode->song, "Believer");
            break;

        case 2:
            strcpy(newNode->song, "Perfect");
            break;

        case 3:
            strcpy(newNode->song, "Faded");
            break;

        case 4:
            strcpy(newNode->song, "Blinding Lights");
            break;

        default:
            printf("Invalid song number!\n");
            free(newNode);
            return;
    }

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Song added successfully!\n");
}

void displayPlaylist()
{
    struct Node *temp = head;

    printf("\n===== MY PLAYLIST =====\n");

    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("- %s\n", temp->song);
        temp = temp->next;
    }
}