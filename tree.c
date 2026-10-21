#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct TreeNode *root = NULL;

struct TreeNode* createNode(char category[])
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(newNode->category, category);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void createCategories()
{
    root = createNode("Music");

    if (root == NULL)
    {
        return;
    }

    root->left = createNode("Pop");
    root->right = createNode("Rock");

    root->left->left = createNode("Believer");
    root->left->right = createNode("Perfect");

    root->right->left = createNode("Thunder");

    printf("Music category tree created successfully!\n");
}

void displayTree(struct TreeNode *node, int level)
{
    int i;

    if (node == NULL)
    {
        return;
    }

    for (i = 0; i < level; i++)
    {
        printf("  ");
    }

    printf("- %s\n", node->category);

    displayTree(node->left, level + 1);
    displayTree(node->right, level + 1);
}

void displayCategories()
{
    if (root == NULL)
    {
        printf("Category tree is empty.\n");
        return;
    }

    printf("\n===== MUSIC CATEGORY TREE =====\n");

    displayTree(root, 0);
}