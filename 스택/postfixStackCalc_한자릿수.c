/* 후위법 계산기 _ 한 자릿수 버전 */
#include <stdio.h>
#define MAX 100

char stack[MAX];
int top;

void init_stack(void)
{
    top = 0;
}

int push(char value)
{
    if(top == MAX) {
        printf("Stack Overflow\n");
        return 0;
    }
    stack[top++] = value;
    return 1;
}

char pop(void)
{
    if(top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[--top];
}

int get_priority(char operand)
{
    switch(operand) {
        case '(':
            return 0;
        case ')':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
    }
    return 0;
}

void compare_priority(char t, char postfix[], int *j)
{
    char temp;
    while(get_priority(stack[top-1]) > get_priority(t) && top != 0 ) {
        if(t == '(') {
            break;
        }
        if((temp=pop()) != '(') {
            postfix[(*j)++] = temp;
        }
    }
    if(t == ')') { // '('를 만나면 pop을 하기 전 while문을 빠져나오기 때문에 아직 stack에 '('이 남아있는 상황이다.
        pop(); // 따라서 '('를 버리기 위해 pop한 뒤 저장 x
    } else {
        push(t);
    }
}

/* 중위표기법 -> 후위표기법 변환 */
char *infix_to_postfix(char infix[])
{
    int i = 0; // 중위표기법 배열 인덱스
    int j = 0; // 후위표기법 배열 인덱스
    char t;
    char postfix[MAX];
    char *result; // return 값
    while(infix[i] != '\0') {
        if(infix[i] > '0' && infix[i] < '9') {
            postfix[j++] = infix[i++];
        } else {
            compare_priority(infix[i], postfix, &j);
            i++;
        }
    }
    do {
        postfix[j++] = pop();
    } while(top != -1);
    result = postfix;
    return result;;
}

int calculate_postfix(char operator)
{
    char temp;
    switch(operator){
        case '*':
            return ((pop()-'0')*(pop()-'0'));
        case '+':
            return ((pop()-'0')+(pop()-'0'));
        case '-':
            temp = pop();
            return ((pop()-'0')-(temp-'0'));
        case '/':
            temp = pop();
            return ((pop()-'0')/(temp-'0'));
    }
    return 0;
}


/* 후위표기법 계산 */
int get_postfix_result(char postfix[])
{
    int i = 0;
    int result = 0;
    while(postfix[i] != '\0') {
        if(postfix[i] >= '0' && postfix[i] <= '9') { // 숫자라면 push()
            push(postfix[i++]);
        } else { // 연산자라면 pop()*2 -> 계산 후 push()
            result = calculate_postfix(postfix[i++]);
            push(result+'0');
        }
    }
    return pop()-'0';
}

int main() {
    char infix[MAX];
    char *postfix;
    int result=0;
    init_stack();
    printf("수식연산을 입력하세요 : ");
    scanf("%s", infix);

    /* 후위표기법 변환 */
    postfix = infix_to_postfix(infix); 
    printf("%s\n", postfix);
    
    /* 후위표기법 계산 */
    result = get_postfix_result(postfix);
    printf("후위표기법 계산 결과 : %d\n", result);
}