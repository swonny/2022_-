// Q. 함수에서 malloc을 하더라도 전역변수처럼 사용 가능?
// Q. 연결리스트는 논리적으로 연결되어있는 것? 
// 
#include <stdio.h>

struct dnode {
    int key;
    struct dnode *prev;
    struct dnode *next;
};

struct dnode *head, *tail;

void init(void) { // 초기화
    head = malloc(sizeof(struct Dnode)); // struct Dnode 만큼의 공간을 메모리에 할당해 주소를 반환하면 head와 tail 포인터 변수에 저장
    tail = malloc(sizeof(struct Dnode)); // head, tail은 더미변수 head와 tail 포인터변수에 저장된 malloc 반환 주소에는 사용자정의된 구조체 struct Dnode가 할당되어있음
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

void AppendNode()

int main() {
    
}