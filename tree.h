#ifndef TREE_H
#define TREE_H

struct TreeNode
{
    char category[50];
    struct TreeNode *left;
    struct TreeNode *right;
};

void createCategories();
void displayCategories();

#endif