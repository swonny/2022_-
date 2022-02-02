#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *root;

void init_tree(void)
{
    root = malloc(sizeof(struct Node));
    root->left = NULL;
    root->right = NULL;
}

void insert_node(int key)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;
    struct Node *prev = root;
    struct Node *temp = prev->left;

    while(temp != NULL) {
        prev = temp;
        if(key < temp->key) {
            temp = temp->left;
        } else if(key > temp->key) {
            temp = temp->right;
        }
    }
    temp = malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    if(prev == root || key < prev->key) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
    // struct Node *temp = root;
    // if(temp->left != NULL) {
    //     temp = temp->left;
    //     while(temp->left != NULL || temp->right != NULL) {
    //         if(key < temp->key) {
    //             temp = temp->left;
    //         } else if(key > temp->key) {
    //             temp = temp->right;
    //         }
    //     }
    // }

    // struct Node *new = malloc(sizeof(struct Node));
    // new->key = key;
    // new->left = NULL;
    // new->right = NULL;
    // if(temp->key > key || temp->left == NULL) {
    //     temp->left = new;
    // } else {
    //     temp->right = new;
    // }
}

void print_tree(void)
{
    struct Node *temp = root->left;
    while(temp != NULL) {
        printf("%d\n", temp->key);
        temp = temp->left;
    }
    // printf("%d\n", temp->key);
    // printf("%d\n", temp->left->key);
    // printf("%d\n", temp->right->key);
    // printf("%d\n", temp->right->right->key);
}

int main() {
    init_tree();
    insert_node(3);
    insert_node(2);
    insert_node(4);
    insert_node(5);
    print_tree();
}