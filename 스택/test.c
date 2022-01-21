#include <stdio.h>
#define MAX 100

char stack[MAX];
int top; // 스택에 담긴 요소의 개수

void init_stack(void)
{
    top = 0;
}

int push(char data)
{
    if (top == MAX) {
        printf("Stack Overflow\n");
        return -1;
    }
    stack[top++] = data;
    return 1;
}

char pop(void) 
{
    if (top == 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[--top];
}

void priority_calc_push(char operator, char infix[], int *i)
{
    switch(operator){
        case '*':
            push(((pop()-'0') * (infix[(*i)]-'0')) + '0'); 
            break;
        case '/':
            push(((pop()-'0') / (infix[(*i)]-'0')) + '0');
            break;
        case '+':
            push(((infix[0]-'0') + (infix[2]-'0')) + '0' );
            break;
        case '-':
            push(((infix[0]-'0') - (infix[2]-'0')) + '0' );
            break;
    }
}

int infix_calc(char infix[])
{
    int i;
    char t;
    char temp[MAX];
    for(i = 0; infix[i] != '\0'; i ++) { // 괄호, '*', '/' 를 먼저 계산하여 스택에 push
        if(infix[i] >= '0' && infix[i] <= '9' || infix[i] == '+' || infix[i] == '-' || infix[i] == '(') {
            push(infix[i]);
        } else if(infix[i] == ')') {
            while(stack[top-2] != '(') { // 중위표기법이니까 연산자는 stack[top-2]에 위치
                for(int i = 2; i >= 0; i --) { // 반대로 넣기
                    temp[i] =  pop();
                }
                priority_calc_push(temp[1], temp, 0);
            }
            t = pop(); // '(' 제거 작업
            pop(); // '(' 제거 작업
            push(t); // '(' 제거 작업
        } else {
            priority_calc_push(infix[i++], infix, &i);
        }
    }

    char t1;
    char t2;
    i = 0;
    while(top != 1) {
        t1 = pop();
        if((t2 = pop()) == '-') {
            t1 = (-1 * (t1-'0')) + '0';
        }
        temp[i++] = t1;
    }
    temp[i++] = pop();
    temp[i] = '\0';

    int result = 0;
    for(int i = 0; temp[i] != '\0'; i ++) {
        result += temp[i] - '0';

    }
    return result;
}

int main() {
    char infix[MAX];
    printf("수식을 입력하세요: ");
    scanf("%s", infix);

    int result = infix_calc(infix);
    printf("중위표기법 계산 결과 : %d\n", result);
}