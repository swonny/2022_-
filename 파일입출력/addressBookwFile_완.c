/* 파일 입출력을 활용하여 주소록 만들기 (주소록 기능은 addressBook_완.c에서 가져옴) */

/* 
    22.01.13 (목) ~ 22.01.15 (토) 완성
    [ 기능 ]
    1. 주소록 파일에 학생 정보 등록
    2. 주소록 파일에서 학생 검색
       2.1 찾는 학생이 없을 때 "등록된 정보 없음" 출력
    3. 주소록 파일에서 학생 삭제
       3.1 삭제하려는 학생이 없을 때 "등록된 정보 없음" 출력
    4. 주소록 전체 출력
       4.1 주소록 파일이 비어있는 경우 "파일이 비어있음" 출력
    5. 주소록 전체 삭제
       5.1 주소록 파일이 비어있는 경우 "파일이 비어있음" 출력
    6. 프로그램 종료
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fi;
int count;

struct Dnode {
    char name[20]; // 8개 문자
    int id; // 10개 숫자
    char address[20]; // 5개 문자
    int phoneNum; // 9개 숫자
    struct Dnode *next;
    struct Dnode *prev;
};

struct Dnode *head, *tail;

/* 리스트 초기화 */
void init_list(void)
{
    head = malloc(sizeof(struct Dnode));
    tail = malloc(sizeof(struct Dnode));
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    
    tail->prev = head;
}

/* 파일이 비어있는지 확인 */
int is_file_empty(void)
{
    fi = fopen("addressBook","r");
    char temp[10];
    fscanf(fi, "%s", temp);
    if(strlen(temp) != 0 ){
        return 1;
    } else {
        return 0;
    }
    fclose(fi);
}

/* 파일 초기화 */
void init_file(void)
{
    fi = fopen("addressBook.txt", "w");
    fclose(fi);
}

/* 파일에서 원하는 단어 찾기 */
char *file_find_str(char *find) 
{
    fi = fopen("addressBook", "r");
    char temp[4][40];
    char name[10];
    char *ptr;
    while(strncmp(find, name, 9) != 0 && feof(fi) == 0) {
        fscanf(fi, "%s", name);
    }
    if(feof(fi) == 0) {
        printf("%s ", name);
        for(int i = 0; i < 3; i ++) {
            fscanf(fi, "%s", temp[i]);
            printf("%s ", temp[i]);
        }
        printf("\n");
        ptr = temp[0];
        fclose(fi);
        return ptr;
    }
    printf("등록되지 않은 정보입니다. \n");
    return 0;

}

/* 파일에 출력 */
void print_file(struct Dnode *t) 
{
    fi = fopen("addressBook", "at");
    
    fprintf(fi, "%s ", t->name);
    fprintf(fi, "%d ", t->id);
    fprintf(fi, "%s ", t->address);
    fprintf(fi, "%010d\n", t->phoneNum);

    fclose(fi);
}

/* 파일에서 입력받기 (전체 출력) */
void file_print_all(void)
{   
    fi = fopen("addressBook", "r");
    char temp[4][40];
    int i;
    printf("\n\n이름     학번       주소   전화번호       \n");
    printf("====================================\n\n");
    while(feof(fi) == 0) {
        for(i = 0; i < 4; i ++) {
            fscanf(fi, "%s ", temp[i]);
            printf("%s ", temp[i]);
        }
        printf("\n");
    }
    fclose(fi);
}


/* 학생 추가 */
void insert_dnode_ptr(char f, char s_name[20], int s_id, char s_address[20], int phoneNum)
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

    // 파일에 추가
    print_file(t);
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

/* 파일에 출력 (rewrite) */
void rewrite_file(char student[100][40], int num)
{
    fi = fopen("addressBook", "wt");
    for(int i = 0; i < num-1; i ++){
        fprintf(fi, "%s ", student[i]);
        if((i+1) % 4 == 0 && i != 0) {
            fprintf(fi, "\n");
        }
    }
    fclose(fi);
}

/* 파일 학생 삭제 */
int file_name_delete_student(char name[])
{
    char temp[40];
    char student[100][40];
    int i = 0;
    int flag =0;
    fi = fopen("addressBook", "rt"); // "rt" : 파일이 존재한다면 기존 파일에 덮어씀
    while(feof(fi) == 0) {
        fscanf(fi, "%s", temp);
        if(strncmp(temp, name, 8) == 0) {
            flag++;
            for(int i = 0; i < 3; i ++) {
                fscanf(fi, "%s", temp);
            }
            continue;
        }
        strcpy(student[i++], temp);
    }
    if(flag == 0) {
        return 0;
    }
    rewrite_file(student, i);
    fclose(fi);
    return 1;
}

/* 한 명 정보 출력 */
void print_info(struct Dnode *t)
{
    printf("%s %d %s %d\n", t->name, t->id, t->address, t->phoneNum);
}

/* 파일 주소록 전체 삭제 */
void file_delete_all(void)
{
    fi = fopen("addressBook", "wt");
    fprintf(fi, "");
    printf("학생 정보가 모두 삭제되었습니다.\n");
    fclose(fi);
}

int main() {
    struct Dnode *t;

    t = malloc(sizeof(struct Dnode));
    init_list();

    while(1)
    {
        int n;
        printf("\n1. 학생 추가\n2. 이름으로 검색\n3. 학생 삭제 (이름) \n4. 주소록 출력\n5. 주소록 전체 삭제\n6. 종료\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                printf("이름, 학번, 주소, 전화번호를 입력하세요 : ");
                scanf("%s %d %s %d", t->name, &t->id, t->address, &t->phoneNum);
                insert_dnode_ptr('a', t->name, t->id, t->address, t->phoneNum);
                break;
            case 2:
                printf("검색할 이름을 입력하세요 : ");
                scanf("%s", t->name);
                file_find_str(t->name);
                break;
            case 3:
                printf("삭제할 학생의 이름을 입력하세요 : ");
                char name[10];
                scanf("%s", name);
                if(file_name_delete_student(name) == 0) {
                    printf("등록된 정보가 없습니다.\n");
                    break;
                } else {
                    printf("%s 학생 정보가 삭제되었습니다.\n", name);
                    break;
                }
                
            case 4:
                if(is_file_empty() == 0) {
                    printf("현재 파일이 비어있습니다.\n");
                    break;
                }
                file_print_all();
                break;
            case 5:
                if(is_file_empty() == 0) {
                    printf("현재 파일이 비어있습니다.\n");
                    break;
                }
                file_delete_all();
                break;
            case 6:
                return 0;
                break;
        }
    }
}

// seungwon 2020181818 Korea 136614473
// seungjun 2020301818 Korea 0136614473
// seunghee 2020201818 Korea 136614473
// jaeheeee 2010201818 Korea 136614473
// pythonee 2018201818 Korea 136614473
// koreaero 2011121222 mexic 121123211
// yongjune 2001121222 japan 0112122233
// hyeriiii 2023101010 Germa 0111222111
// choiseun 2030102010 korea 102232123
// helloooo 2342341232 korea 0123123123
