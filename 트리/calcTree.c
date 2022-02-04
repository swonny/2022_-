/* 
    수식트리 - 비재귀
    !!! 배열로 바꿔서 고쳐보기
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* 스택 */

struct StackNode{
    char key;
    struct StackNode *next;
};

struct StackNode *head;

void init_stack(void)
{
    head = malloc(sizeof(struct Node));
    head->next = NULL;
}

struct StackNode *pop(void)
{
    return head->next;
}

void push(struct StackNode *node)
{
    node->next = head->next;
    head->next = node;
}

struct StackNode *create_stack_node(char key)
{
    struct StackNode *new = malloc(sizeof(struct StackNode));
    new->key = key;
    new->next = NULL;

    return new;
}
/* 스택 */

struct Node {
    char key;
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

struct Node *create_node(char key)
{
    struct Node *new = malloc(sizeof(struct Node));
    new->key = key;

    return new;
}

int is_node_full(struct Node *node)
{
    if(node->right != NULL) {
        if(node->left != NULL) {
            return 2; // full
        } else {
            return 1; // right o, left x
        }
    } else {
        return 0; // none
    }
}

void link_tree(char postfix[], int cnt)
{
    struct Node *current = root;
    int numChild = -1;
    for(int i = cnt-1; i >= 0; i --) {
        if((numChild = is_node_full(current)) == 0) {
            current = pop();
        }
        struct Node *new = create_node(postfix[i]);
        if(postfix[i] >= '0' && postfix[i] <= '9') { // 숫자
            if(numChild == 0) {
                current->right = new;
            } else {
                current->left = new;
            }
        } else { // 연산자
            if(numChild == 0) {
                current->right = new;
                push(current);
                current = postfix[i];
            } else {
                current = pop();
                current->left = new;
                current = postfix[i];
            }
        }
    }
}

int main() {
    char postfix[] = "12*78-+"; // 7개

    init_tree();
}