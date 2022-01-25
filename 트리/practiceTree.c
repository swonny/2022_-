#include <stdio.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *root;

void append_child(struct Node *root)
{
    if(root->left != NULL) {
        if(root->right != NULL) {
            root->left->left = malloc(sizeof(struct Node));
        }
    }
}

int main() {
    
}