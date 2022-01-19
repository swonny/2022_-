#include <stdio.h>

int my_atoi(char str[])
{
    int t = 1;
    int result = 0;
    int count;
    for(count = 0; str[count] != '\0'; count ++) {
    }
    for(int j = 0; j < count; j ++) {
        result += (str[count-j-1]-'0')*t;
        t *= 10;
    }
    return result;
}

int main() {
    char a[] = "21";
    int r = my_atoi(a);
    printf("%d\n", r);
} 
