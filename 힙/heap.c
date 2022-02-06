#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

int queue[MAX];
int rear;
int front;

struct Node *root;

struct Node *create_node(int key)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->key = key;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void init_tree(void)
{
    root = malloc(sizeof(struct Node));
    root->left = NULL;
    root->right = NULL;
}

int is_node_full(struct Node *node)
{
    if(node->right != NULL) {
        return 1;
    }
    return 0;
}

void find_last_node(struct Node *root)
{

}

void insert_node(struct Node *node) // 트리 최우측에 삽입
{
    
}

// void create_binary_tree(int arr[], int n)
// {
//     struct Node *parent;
//     for(int i = 0; i < n; i ++) {
//         if(is_node_full(parent) == 1){

//         }
//     }
    
// }

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    // create_binary_tree(arr, sizeof(arr)/sizeof(arr[0]));
}