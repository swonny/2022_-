#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode {
    int key;
    struct _dnode *prev;
    struct _dnode *next;
} dnode;

dnode *head, *tail;

void init_list(void)
{
    head = (dnode*)malloc(sizeof(dnode));
    tail = (dnode*)malloc(sizeof(dnode));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

dnode *insert_dnode_ptr(int k, dnode *t)
/*
    t노드 앞에 key값 k를 갖는 노드 삽입
    1. k 메모리 할당
    2. while문 : t가 tail이 아니면 k 삽입
        2.1 k 노드 prev, next 연결
        2.2 나머지 연결
*/
{   
    if(t == head) {
        return 0;
    }
    dnode *p = (dnode*)malloc(sizeof(dnode));
    p->key = k;
    p->next = t;
    p->prev = t->prev;
    t->prev->next = p;
    t->prev = p;

    return p;
}

int delete_dnode_ptr(dnode *p)
/*
    p노드 삭제
    1. p의 앞 뒤 서로 연결
    2. p 삭제
*/
{
    if(p == head || p == tail) {
        return 0;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    free(p);

    return 1;
}

dnode *find_dnode(int k)
/*
    k를 갖는 노드 찾기
    1. while문으로 k 찾기
*/
{
    dnode *t = head->next;
    while(t != tail)
    {
        if(t->key == k)
        {
            return t;
        }
        t = t->next;
    }
    printf("k를 갖는 노드가 없습니다.\n");
    return 0;
}

void print_list(void)
{
    dnode *t;
    t = head->next;

    while(t != tail)
    {
        printf("%d ", t->key);
        t = t->next;
    }
}

int delete_dndoe(int k)
{
    dnode *s;
    s = head->next;

    while(s != tail)
    {
        if(s->key == k)
        {
            s->prev->next = s->next;
            s->next->prev = s->prev;
        }
        s = s->next;
    }
    return 0;
}

dnode *insert_dnode(int k, int t)
/*
    t 앞에 k 삽입
*/
{
    dnode *s = find_dnode(t);
    dnode *p = (dnode*)malloc(sizeof(dnode));
    p->key = k;
    p->next = s;
    p->prev = s->prev;
    s->prev->next = p;

    return s;
}

dnode *ordered_insert(int k)
/*
    정렬하여 k 저장
*/
{
    dnode *r;
    dnode *p = head->next;

    while(p->key < k && p != tail)
    {
        p = p->next;
    }
    r = (dnode*)malloc(sizeof(dnode));
    r->key = k;
    r->prev = p->prev;
    r->next = p;
    p->prev->next = r;
    p->prev = r;

    return r;
}

int main() {
    dnode *t;

    // 리스트 초기화
    init_list();

    // 노드 삽입
    ordered_insert(3);
    ordered_insert(10);
    ordered_insert(1);
    ordered_insert(5);
    // insert_dnode_ptr(3, tail);
    // insert_dnode_ptr(10, tail);
    // insert_dnode_ptr(1, tail);
    // insert_dnode_ptr(5, tail);

    // 리스트 출력
    print_list();

    // 노드 찾기
    // t = find_dnode(5);
    // printf("\n\nfind_dnode(5)의 결과 : %d\n", t->key);

    // // 노드 삭제
    // delete_dnode_ptr(t);
    // print_list();

    // printf("\n\n");
    // delete_dndoe(10);
    // print_list();

    // // 노드 삽입
    // printf("\n\n");
    // insert_dnode(4, 1);
    // insert_dnode(6, 4);
    // print_list();
}