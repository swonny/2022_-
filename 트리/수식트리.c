#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(struct Node **node)
{
    (*node) = malloc(sizeof(struct Node));
    (*node)->left = NULL;
    (*node)->right = NULL;
    
    return node;
}

int count_str(char postfix[])
{
    int i;
    for(i = 0; postfix[i] != '\0'; i ++) {
    }

    return i;
}

void tree_infix_calc(char postfix[], int count)
{
    if(postfix[count+1] >= '0' && postfix[count+1] <= '9') { 
        
    }
}

int main() {
    struct Node *root;
    char postfix[MAX];

    printf("후위표기법을 입력하세요 : ");
    scanf("%s", postfix);

    int count = count_str(postfix);

    create_node(&root); // 트리 생성
    tree_infix_calc(postfix, count);
}