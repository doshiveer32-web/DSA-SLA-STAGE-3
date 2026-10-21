#ifndef PLAYLIST_H
#define PLAYLIST_H

struct Node
{
    char song[50];
    struct Node *next;
};

void addSong();
void displayPlaylist();

#endif