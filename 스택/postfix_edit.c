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
            postfix[(*j)++] = ' '; // 공백추가
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
            do {
                postfix[j++] = infix[i++];
            } while(infix[i] > '0' && infix[i] < '9');
            postfix[j++] = ' '; // 공백 추가
        } else {
            compare_priority(infix[i], postfix, &j);
            i++;
        }
    }
    do {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    } while(top != -1);
    postfix[j] = '\0';
    result = postfix;
    return result;
}

int str_to_int(char temp[])
{
    int t = 1;
    int result = 0;
    for(int i = 0; temp[i] != '\0'; i ++) {
        result += (temp[i]-'0') * t;
        t *= 10;
    }
    printf("result : %d\n", result);
    return result;
}

void num_token(char temp[]) // 스택에서 숫자 최소단위로 잘라주는 함수
{
    int i=0;
    pop(); // 공백을 버리기 위한 용도
    while(stack[top-1] != ' ' &&  top > 0) {
        temp[i++] = pop();
        // printf("temp[%d] :  %c\n",  i-1, temp[i-1]);
    }
    temp[i] = '\0';
    printf("temp : %s\n",  temp);
}

int calculate_postfix(char operator) // pop하여 문자열 str_to_temp에 전달, 원래 숫자가 뒤집힌 모양의 문자열 전달
{
    char strNum1[MAX]; // 문자열로 저장된 숫자 1
    char strNum2[MAX]; // 문자열로 저장되 숫자 2
    char t;
    num_token(strNum1); // reversed num (str)
    printf("strNum1 : %s\n", strNum1);
    num_token(strNum2); // reversed num (str)
    printf("strNum2 : %s\n", strNum2);

    int num1 = str_to_int(strNum1);
    int num2 = str_to_int(strNum2);
    switch(operator){
        case '*':
            return (num1 * num2);
        case '+':
            return (num1 + num2);
        case '-':
            return (num2 - num1);
        case '/':
            return (num2 / num1);
    }
    return 0;
}

/* 후위표기법 계산 */
int get_postfix_result(char postfix[])
{
    int i = 0;
    int result = 0;
    top ++;
    while(postfix[i] != '\0') {
        if(postfix[i] >= '0' && postfix[i] <= '9') { // 숫자라면 push()
            do { // 연산자가나오기전까지 숫자 push
                push(postfix[i++]);
                printf("stack[%d] : %c\n", top-1, stack[top-1]);
            } while (postfix[i] >= '0' && postfix[i] <= '9');
            push(postfix[i++]); // 공백 추가
            printf("stack[%d] : %c\n", top-1, stack[top-1]);
        } else { // 연산자라면 pop()*2 -> 계산 후 push()
            if(postfix[i] == ' ' ) {
                if(postfix[i+1] == '\0') { // 없어도 같은 결과 나옴
                    printf("break 할 때 i: %d\n", i);
                    top--; // temp
                    break;
                }
                i++;
                continue;
            }
            result = calculate_postfix(postfix[i++]);
            printf("push : %d\n", result);
            push(result+'0');
            push(' ');
            printf("stack[%d] : %d", top-1, stack[top-1]);
            // printf("stack[%d] : %d\n", top-2, stack[top-2]); 
            // puts("");
        }
    }
    pop();
    // printf("before return top(%d) : %c\n", top-1, stack[top-1]);
    // return pop()-'0';
    return stack[0]-'0';
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