/* 후위법 계산기 */
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
            postfix[j++] = ' ';
            compare_priority(infix[i],postfix, &j);
            i++;
        }
    }
    do {
        postfix[j++] = ' ';
        postfix[j++] = pop();
    } while(top != -1);
    result = postfix;

    return result;;
}

int str_to_int(void)
{
    int i = 0;
    int t = 1;
    int result = 0;
    char temp;
    pop(); // 공백 버리는 용도
    while(stack[top-1] != ' ') { // 정수형으로 변환 후 배열에 저장
        if(top == -1) {
            break;
        }
        result += (pop() - '0') * t;
        t *= 10;
    }
    return result;
}

int calculate_postfix(char operator)
{
    int i = 0;
    int t = 1;
    int result1 = 0; // 첫 번째 pop()을 정수형으로 변환한 결과
    int result2 = 0; // 두 번째 pop()을 정수형으로 변환한 결과
    /* 중복되는 코드 */
    result1 = str_to_int();
    result2 = str_to_int();

    printf("result1 : %d\nresult2 : %d\n", result1, result2);
    /* 중복되는 코드 */
    switch(operator){
        case '*':
            return (result1 * result2);
        case '+':
            return (result1 + result2);
        case '-':
            return (result2 - result1);
        case '/':
            return (result2 / result1);
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
            while(postfix[i] != ' ') {
                push(postfix[i++]);
            }
            push(postfix[i++]); // 공백 push
        } else { // 연산자라면 pop()*2 -> 계산 후 push()
            result = calculate_postfix(postfix[i++]);
            printf("result : %d\n", result);
            push(result+'0');
            push(' ');
        }
    }
    postfix[i] = '\0';
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
    printf("\n%s\n", postfix);
    
    /* 후위표기법 계산 */
    result = get_postfix_result(postfix);
    printf("후위표기법 계산 결과 : %d\n", result);
}