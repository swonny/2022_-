#include <stdio.h>
#include <string.h>
FILE *fi;

char *find_str(char *find) 
{
    fi = fopen("addressBook", "r");
    char temp[4][40];
    char *ptr;
    while(strncmp(find, temp[0], 2) != 0) {
        for(int i = 0; i < 4; i ++) {
            fscanf(fi, "%s", temp[i]);
            printf("%s ", temp[i]);
        }
    }
    fclose(fi);
    ptr = temp[0];

    return ptr;
}

int main() {
    fi = fopen("addressBook.txt", "r");
    char a[] = "seungwon";
    char *temp;
    temp = find_str(a);

    printf("\n");
    fclose(fi);
}