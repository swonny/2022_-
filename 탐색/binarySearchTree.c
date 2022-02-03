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
}

struct Node *search_node(int key)
{
    struct Node *temp = root->left;
    while(temp->key != key) {
        if(temp->key > key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return temp;
}

void delete_node(int key)
{
    // struct Node *temp = search_node(key);
    struct Node *parent = root;
    struct Node *temp = parent->left;
    struct Node *del;

    while(temp->key != key) {
        parent = temp;
        if(temp->key > key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    /* Q. free를 해도 parent를 NULL로 초기화시켜야하는지 */
    if(temp->left == NULL && temp->right == NULL) { // 외부노드일 때
        if(temp == parent->left) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(temp);
    } else if(temp->left != NULL && temp->right == NULL) { // 오른쪽만 NULL 일 때
        parent->left = temp->left;
        free(temp);
    } else if (temp->right != NULL && temp->left == NULL) { // 왼쪽만 NULL 일 때
        parent->right = temp->right;
        free(temp);
    } else { // 둘 다 NULL이 아닐 때
        if(temp->right->left != NULL)  {
            del = temp;
            temp = temp->right;
            while(temp->left !=  NULL) { // 오른쪽 자식의 왼쪽 자식 중 외부노드 찾기
                temp = temp->left;
            }
            printf("!!!! 왼쪽 외부노드 : %d\n", temp->key);
            if(temp->right != NULL) {
                del->left = temp->right;
            }
            if(parent == root || parent->key > temp->key) {
                parent->left = temp;
            } else {
                parent->right = temp;
            }
            free(del);
        } else if(temp->right->left == NULL)  {
            parent->right = temp->right;
            free(temp);
        }
    }
}

int print_tree(struct Node *temp)
{
    if(temp == NULL) {
        return 0;
    }
    printf("%d\n", temp->key);
    print_tree(temp->left);
    print_tree(temp->right);

    return 0;
}

int main() {
    init_tree();
    insert_node(3);
    insert_node(2);
    insert_node(5);
    insert_node(4);
    insert_node(1);
    insert_node(10);
    insert_node(11);

    delete_node(2);
    // delete_node(3);
    delete_node(4);
    // delete_node(5);
    // delete_node(1);
    // delete_node(10);
    // delete_node(11);

    // printf("%d\n", root->left->key);
    print_tree(root->left);
}