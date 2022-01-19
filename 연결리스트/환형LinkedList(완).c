#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int i) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->key = i;

    return newNode;
}

/*
    1. head->next가 NULL이라면 : 리스트의 노드 없는 상태 
       -> 넘겨받은 head를 조작하여 head가 newNode를 가리킬 수 있도록
    2. head->next가 NULL이 아니라면 : 리스트의 노드 존재
       -> head를 조작할 필요 없음
       -> head의 next부터 탐색하여 next가 head를 가리키는 노드일 때 그 다음 노드로 삽입
*/
void AppendNode(struct node **head, struct node *newNode) {
    // static int count = 0;
    struct node *tail;
    if((*head) == NULL) {
        *head = newNode;
        tail = *head;
    } else {
        tail = *head;
        // switch(count){
        //     case 0:
        //         break;
        //     case 1:
        //         break;
        //     case 2:
        //         tail = tail->next;
        //         break;
        //     case 3:
        //         tail = tail->next->next;
        //         break;
        //     case 4:
        //         tail = tail->next->next->next;
        //         break;
        // } 
        while(tail->next != *head) { // 진짜 tail노드 찾기
            tail = tail->next;
            printf("key : %d\n", tail->key);
        }
    }
    // tail 이라면 tail의 next에 연결
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
    tail->next = newNode;
    // count++;
}

void printNode(struct node *head) {
    struct node *tail = head;
    while(1) {
        printf("%d번째 노드\n", tail->key);
        tail = tail->next;
        if(tail == head) {
            break;
        }
    }
}

int main() {

    struct node *newNode = NULL;
    struct node *current = NULL;
    struct node *List = NULL;
    int i;

    for(i=0; i<5; i ++) {
        newNode = createNode(i); // 인덱스를 넘겨주고 메모리할당한 구조체를 가리키는 포인터 반환
        AppendNode(&List, newNode);
    }
    printNode(List);
}
