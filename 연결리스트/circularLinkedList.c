/*  Joshep's problem - c로 배우는 알고리즘 p.142~143 */

#include <stdio.h>

typedef struct _node{
    int key;
    struct _node *next;
} node;

node *head, *tail;

void init_list(void) {
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail;
    tail->next = head;
}

int main() {

}