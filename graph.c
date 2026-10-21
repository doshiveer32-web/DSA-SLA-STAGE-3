#include <stdio.h>
#include <string.h>
#include "graph.h"

#define MAX_SONGS 5

char songs[MAX_SONGS][50] = {
    "Believer",
    "Perfect",
    "Faded",
    "Thunder",
    "Blinding Lights"
};

int graph[MAX_SONGS][MAX_SONGS] = {0};

void addConnection()
{
    int i, j;

    printf("\n===== AVAILABLE SONGS =====\n");

    for (i = 0; i < MAX_SONGS; i++)
    {
        printf("%d. %s\n", i + 1, songs[i]);
    }

    printf("Enter first song number: ");

    if (scanf("%d", &i) != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter second song number: ");

    if (scanf("%d", &j) != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    if (i < 1 || i > MAX_SONGS ||
        j < 1 || j > MAX_SONGS || i == j)
    {
        printf("Invalid song selection!\n");
        return;
    }

    graph[i - 1][j - 1] = 1;
    graph[j - 1][i - 1] = 1;

    printf("Connection added between %s and %s.\n",
           songs[i - 1], songs[j - 1]);
}

void displayRecommendations()
{
    int choice, i;
    int found = 0;

    printf("\n===== AVAILABLE SONGS =====\n");

    for (i = 0; i < MAX_SONGS; i++)
    {
        printf("%d. %s\n", i + 1, songs[i]);
    }

    printf("Choose a song to find related songs: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    if (choice < 1 || choice > MAX_SONGS)
    {
        printf("Invalid song number!\n");
        return;
    }

    printf("\nSongs related to %s:\n", songs[choice - 1]);

    for (i = 0; i < MAX_SONGS; i++)
    {
        if (graph[choice - 1][i] == 1)
        {
            printf("- %s\n", songs[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No related songs yet. Add a connection first.\n");
    }
}