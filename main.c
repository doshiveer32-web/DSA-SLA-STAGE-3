#include <stdio.h>
#include "playlist.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "graph.h"

int main()
{
    int choice;
    char song[50];

    printf("====================================\n");
    printf("    MUSIC AND VIDEO STREAMING APP\n");
    printf("====================================\n");

    while (1)
    {
        printf("\n========== MENU ==========\n");
        printf("1. Add Song to Playlist\n");
        printf("2. Display Playlist\n");
        printf("3. Add Song to Recently Played\n");
        printf("4. Remove Recently Played Song\n");
        printf("5. Display Recently Played\n");
        printf("6. Add Song to Playback Queue\n");
        printf("7. Play Next Song\n");
        printf("8. Display Playback Queue\n");
        printf("9. Create Music Category Tree\n");
        printf("10. Display Music Category Tree\n");
        printf("11. Add Related Song Connection\n");
        printf("12. Display Song Recommendations\n");
        printf("13. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                push(song);
                break;

            case 4:
                pop();
                break;

            case 5:
                displayRecent();
                break;

            case 6:
                printf("Enter song name: ");
                scanf(" %49[^\n]", song);
                enqueue(song);
                break;

            case 7:
                dequeue();
                break;

            case 8:
                displayQueue();
                break;

            case 9:
                createCategories();
                break;

            case 10:
                displayCategories();
                break;

            case 11:
                addConnection();
                break;

            case 12:
                displayRecommendations();
                break;

            case 13:
                printf("Thank you for using the application!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}