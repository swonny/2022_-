#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 주소록 만들기
/*
    1. 이름, 학번, 과, 주소, 전화번호 구조체
    2. 삽입, 삭제
    3. print_all
    4. delete_all
*/

struct Dnode {
    char name[20];
    int id;
    char major[30];
    char address[50];
    int phoneNum;
    struct _dnode *next;
    struct _dnode *prev;
};

struct Dnode *head, *tail;

/* 초기화 */
void init_list(void)
{
    head = malloc(sizeof(struct Dnode));
    tail = malloc(sizeof(struct Dnode));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;
}

/* 주소록 정보로 노드 삽입 (학생추가) */
void insert_dnode_info(char s_name[], int s_id, char s_major[], char s_address[], int s_phoneNum)
{
    struct Dnode *new;
    new = malloc(sizeof(struct Dnode));
    // 학생정보 입력
    strcpy(new->name, s_name);
    new->id = s_id;
    strcpy(new->major, s_major);
    strcpy(new->address, s_address);
    new->phoneNum = s_phoneNum;

    // 노드 연결
    new->prev = tail->prev;
    new->next = tail;
    tail->prev->next = new;
    tail->prev = new;
}

/* 주소록 노드 자체 삽입 */
void insert_dnode_ptr(struct Dnode *s)
{
    s->prev = tail->prev;
    s->next = tail;
    tail->prev->next = s;
    tail->prev = s;
}

/* 학번순으로 삽입 */
struct Dnode *ordered_insert_dnode(struct Dnode *s)
{
    struct Dnode *t;
    t = head->next;

    while(t != tail) {
        if(s->id > t->id) {
            t = t->next;
        } else {
            break;
        }
    }
    insert_dnode_ptr(s);
    // s->prev = t->prev;
    // s->next = t;
    // t->prev->next = s;
    // t->prev = s;

    return 0;
}

/* 노드 삭제 (특정 id 갖는 노드 삭제) */
void delete_dnode_id(int id)
{
    struct Dnode *t;
    t = head->next;

    while(t != tail) {
        if(t->id == id) {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            free(t);
            break;
        } else {
            t = t->next;
        }
    }
}

void delete_dnode_name(char name[])
{
    struct Dnode *t;
    t = head->next;

    while(t != tail) {
        if(strcmp(name, t->name) == 0) {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            free(t);
            break;
        } else {
            t = t->next;
        }
    }
}

/* 이름으로 주소록 검색 */
struct Dnode *search_dnode(char name[])
{
    struct Dnode *t;
    t = head->next;

    while(t != tail) {
        if(strcmp(name, t->name) == 0) {
            printf("\n");
            printf("검색결과 : %s    %d    %s    %s    %d\n", t->name, t->id, t->major, t->address, t->phoneNum);
            break;
        } else {
            t = t->next;
        }
    }
    return t;
}

void print_all(void)
{
    printf("print_all() called\n");
    struct Dnode *t;
    t = head->next;

    printf("\n\n이름     학번       과  주소     전화번호       \n");
    printf("==================================================\n\n");
    while(t != tail)
    {
        printf("%s %d %s %s %d\n", t->name, t->id, t->major, t->address, t->phoneNum);
        t = t->next;
    }
}

/* 주소록 모두 삭제 */
void delete_all(void)
{
    struct Dnode *t, *s;
    t = head->next;

    while(t != tail){
        s = t->next;
        printf("%s %d %s %s %d\n", t->name, t->id, t->major, t->address, t->phoneNum);
        free(t);
        t = s;
        printf("%s %d %s %s %d\n", t->name, t->id, t->major, t->address, t->phoneNum);
    }
}

int main() {
    struct Dnode *t;
    t = (struct Dnode*)malloc(sizeof(struct Dnode));

    init_list();
    int n;
    char tName[20];
    int tNum;

    while(1) {
        printf("\n1. 학생 정렬 추가\n2. 이름으로 검색\n3. 학생 삭제 (학번)\n4. 학생 삭제 (이름) \n5. 주소록 출력\n6. 주소록 전체 삭제\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("이름, 학번, 과, 주소, 전화번호를 입력하세요 : ");
                scanf("%s %d %s %s %d", t->name, &t->id, t->major, t->address, &t->phoneNum);
                insert_dnode_info(t->name, t->id, t->major, t->address, t->phoneNum);
                // ordered_insert_dnode(t);
                break;
            case 2:
                printf("검색할 이름을 입력하세요 : ");
                scanf("%s", tName);
                search_dnode(tName);
                break;
            case 3:
                printf("삭제할 학생의 학번을 입력하세요 : ");
                scanf("%d", &tNum);
                delete_dnode_id(tNum);
                break;
            case 4:
                printf("삭제할 학생의 이름을 입력하세요 : ");
                scanf("%s", tName);
                break;
            case 5:
                print_all();
                break;
            case 6:
                delete_all();
                break;
        }
    }
}

/* 구조체를 포인터로 선언하는 이유
    1. 구조체 내부의 next 포인터 변수에는 '다음 노드의 메모리 주소'가 저장
        따라서 다음 노드와 이전노드의 메모리 주소를 저장하여 논리적으로 연결시킴
*/

// seungwon 2020181818 BM Korea 136614473
// seungjun 2020301818 BM Korea 136614473
// seunghee 2020201818 BM Korea 136614473
// jaeheeee 2010201818 BM Korea 136614473
// pythonee 2018201818 BM Korea 136614473