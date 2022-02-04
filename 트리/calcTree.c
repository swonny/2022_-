/* 
    수식트리 - 비재귀
    !!! 배열로 바꿔서 고쳐보기
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    char key;
    struct Node *left;
    struct Node *right;
};

/* 스택 */

struct Node *stack[MAX];
int top;

void init_stack(void)
{
    top = 0;
}

int push(struct Node *node)
{
    if(top >= MAX) {
        printf("Stack Overflow\n");
        return -1;
    }
    stack[top++] = node;
    return 1;
}

struct Node *pop(void)
{
    if(top <= 0) {
        printf("Stack Underflow\n");
        return NULL;
    }
    return stack[--top];
}

/* 스택 */

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

int link_tree(char postfix[], int cnt)
{
    root->key = postfix[cnt-1];
    struct Node *current = root;
    int numChild = -1;
    for(int i = cnt-2; i >= 0; i --) {
        printf("!!!! %c\n", postfix[i]);
        if((numChild = is_node_full(current)) == 2) {
            if((current = pop()) == NULL) {
                return -1;
            };
            numChild = 1;
        }
        struct Node *new = create_node(postfix[i]);
        if(postfix[i] >= '0' && postfix[i] <= '9') { // 숫자
            if(numChild == 0) {
                current->right = new;
            } else if(numChild == 1) {
                current->left = new;
            }
        } else { // 연산자
            if(numChild == 0) {
                current->right = new;
                push(current);
            } else if(numChild == 1){
                current->left = new;
            }
            current = new;
        }
    }
    return 1;
}

int print_tree(struct Node *node)
{
    if(node == NULL){
        return 0;
    }
    printf("%c\n", node->key);
    print_tree(node->left);
    print_tree(node->right);


    return 1;
}

int free_tree(struct Node *node)
{
    if(node == NULL) {
        return 0;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);

    return 1;
}

int main() {
    char postfix[] = "312*78-+-"; // 7개

    // free_tree(root);
    init_tree();
    init_stack();

    link_tree(postfix, sizeof(postfix)/sizeof(postfix[0]) - 1);
    print_tree(root);
    free_tree(root);
}