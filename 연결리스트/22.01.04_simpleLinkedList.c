#include <stdio.h>
#include <stdlib.h>

typedef struct _node 
{
    int key;
    struct _node *next; // node가 정의되기 전 재귀적으로 할 수 있는 이유: 포인터가 무엇을 가리키든 포인터 자체 크기변화는 없으니까
}node;

node *head, *tail;

void init_list(void) 
{ // 연결리스트 초기화
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}

node *insert_after(int key, node *t) 
  /*
  1. s노드 메모리 할당 & key 저장
  2. s노드 -> next == t노드 -> next
  3. t노드 -> next == s노드
  */
{
    node *s;
    s = (node*)malloc(sizeof(node));
    s->key = key;
    s->next = t->next;
    t->next = s;
    return s;
}

node *delete_after(node *t)
{
    /*
    1. tail이 아닌 경우 조건문
    1. 삭제할 노드 t->next를 s에 임시 저장한다.
    2. t -> next -> next 와 연결
    */
   if(t->next == tail) {
       return 0;
   }
    node *s;
    s = t->next;
    t->next = t->next->next;
    free(s);
    return t;
}

node *find_node(int key)
/*
    1. while문으로 key값 찾기 (종료조건 : tail일 경우)
    2. tail이면 0, tail이 아니면 노드 포인터 반환
*/
{
    node *t;
    t = head->next;
    while(t != tail) {
        if(t->key == key) {
            return t;
        }
        t = t->next;
    }
    printf("%d와 일치하는 노드가 없습니다.\n", key);
    return 0;
}

int delete_node(int key)
/*
    delete_node : key값을 이용해 삭제할 노드를 찾는 함수 (삭제노드의 이전 노드를 저장하고 있음)
    1. 노드 s : head 저장
    2. 노드 t : head->next 저장
    3. while 문 : key값과 일치할 때까지, 일치하면 break 일치하지 않으면 p,s의 next에 연결
    4. tail 아니면 삭제, s의 다음을 t의 다음과 연결
*/
{
    node *s;
    node *t;
    s = head;
    t = head->next;

    while(t != tail) 
    {
        if(t->key == key) {
            s->next = t->next;
            free(t);
            return 1;
        }
        s = s->next;
        t = t->next;
    }
    return 0;
}

node *insert_node(int t, int k)
/*
    k앞에 t 삽입
    1. k를 갖는 노드 찾기
    2. t 노드 생성 & key에 t 대입
*/
{
    node *s; // 탐색하는 노드
    node *p; // s의 앞 노드
    node *r; // 삽입할 노드
    s = head->next;
    p = head;

    while(s != tail)
    {
        if(s->key == k) { // k 노드를 찾은 경우 r 삽입
            r = (node*)malloc(sizeof(node));
            r->key = t;
            r->next = s;
            p->next = r;

            return r;
        }
        s = s->next;
        p = p->next;
    }
    return 0;
}

node *ordered_insert(int k)
/*
    순서대로 정렬하여 삽입
    1. k가 들어갈 공간 찾기 (s가 k보다 작거나 같으면 s앞에 삽입)
    2. while을 빠져나오면 무조건 s앞에 삽입
*/
{
    node *s;
    node *p;
    node *r;
    s = head->next;
    p = head;

    while(s != tail)
    {
        if(s->key < k) { // s의 key가 k보다 작은 경우 s 앞에 삽입
            p = p->next;
            s = s->next;
        } else {
            break;
        }
    }
    r = (node*)malloc(sizeof(node));
    r->key = k;
    r->next = s;
    p->next = r;

    return r;
}

void print_list(void)
{ // 모든 노드 출력
    node *t = head->next;

    while(t != tail)
    {
        printf("%d\n", t->key);
        t = t->next;
    }
}

void delete_all(void)
{
    node *t = head->next;
    node *s;

    while(t != tail)
    {
        s = t;
        t = t->next;
        free(s);
    }
    head->next = tail;
}

int main() {
    node *t;

    init_list();
    // 정렬하여 삽입
    ordered_insert(10);
    ordered_insert(1);
    ordered_insert(4);
    ordered_insert(3);
    ordered_insert(11);

    print_list();

    // 노드 찾기
    t = find_node(5);
    t = find_node(4);
    printf("find_node(5) 결과 : %d\n", t->key);

    // 노드 삽입
    insert_after(9, t);
    print_list();

    // 노드 삭제
    delete_node(t->key);
    printf("\n\n");
    print_list();

    // 노드 삽입
    insert_node(20, 11);
    printf("\n\n");
    print_list();

    // 전체 삭제
    delete_all();
    printf("모두 삭제 후 print_all");
    print_list();
}