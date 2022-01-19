/* 주소록 만들기 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dnode {
    char name[10];
    int id; // 10개 숫자
    char address[20];
    int phoneNum; // 9개 숫자
    struct Dnode *next;
    struct Dnode *prev;
};

struct Dnode *head, *tail;

void init_list(void)
{
    head = malloc(sizeof(struct Dnode));
    tail = malloc(sizeof(struct Dnode));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    
    tail->prev = head;
}

/* 학생 추가 */
void insert_dnode_ptr(char s_name[20], int s_id, char s_address[20], int phoneNum)
{
    struct Dnode *t;
    t = malloc(sizeof(struct Dnode));
    
    // 학생 정보 추가
    strcpy(t->name, s_name);
    t->id = s_id;
    strcpy(t->address, s_address);
    t->phoneNum = phoneNum;
    t->prev = tail->prev;
    t->next = tail;
    
    // 연결
    tail->prev->next = t;
    tail->prev = t;
}

/* 학생 검색 */
struct Dnode *search_student(char sName[])
{
    struct Dnode *t = malloc(sizeof(struct Dnode));
    t = head->next;

    while(t != tail)
    {
        if(strcmp(sName, t->name) == 0) {
            return t;
        }
        t = t->next;
    }
    printf("등록되지 않은 정보입니다. (%s)\n", sName);
    return 0;
}

/* 학생 삭제 */
void name_delete_student(char name[])
{
    struct Dnode *t;
    t = search_student(name);
    printf("%s 학생 정보를 삭제합니다.\n", t->name);
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

/* 주소록 전체 출력 */
void print_all(void)
{
    struct Dnode *t = malloc(sizeof(struct Dnode));
    t = head->next;

    printf("\n\n이름     학번       주소   전화번호       \n");
    printf("====================================\n\n");
    while(t != tail)
    {
        printf("%s %d %s %d\n", t->name, t->id, t->address, t->phoneNum);
        t = t->next;
    }
}

/* 한 명 정보 출력 */
void print_info(struct Dnode *t)
{
    printf("%s %d %s %d\n", t->name, t->id, t->address, t->phoneNum);
}

/* 주소록 전체 삭제 */
void delete_all(void)
{
    struct Dnode *t, *s;
    t = head->next;

    while(t != tail)
    {
        s = t->next;
        t->prev->next = s;
        t->next->prev = t->prev;
        printf("%s 학생 정보 삭제\n", t->name);
        free(t);
        t = s;
    }
}

int main() {
    struct Dnode *t;
    t = malloc(sizeof(struct Dnode));
    init_list();

    while(1)
    {
        int n;
        printf("\n1. 학생 정렬 추가\n2. 이름으로 검색\n3. 학생 삭제 (이름) \n4. 주소록 출력\n5. 주소록 전체 삭제\n6. 종료\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("이름, 학번, 주소, 전화번호를 입력하세요 : ");
                scanf("%s %d %s %d", t->name, &t->id, t->address, &t->phoneNum);
                insert_dnode_ptr(t->name, t->id, t->address, t->phoneNum);
                print_all();
                break;
            case 2:
                printf("검색할 이름을 입력하세요 : ");
                scanf("%s", t->name);
                t = search_student(t->name);
                print_info(t);
                break;
            case 3:
                printf("삭제할 학생의 이름을 입력하세요 : ");
                char name[100];
                scanf("%s", name);
                name_delete_student(name);
                break;
            case 4:
                print_all();
                break;
            case 5:
                delete_all();
                break;
            case 6:
                return 0;
                break;
        }
    }
}

// seungwon 2020181818 Korea 136614473
// seungjun 2020301818 Korea 136614473
// seunghee 2020201818 Korea 136614473
// jaeheeee 2010201818 Korea 136614473
// pythonee 2018201818 Korea 136614473