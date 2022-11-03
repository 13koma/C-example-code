#include <stdio.h>
#include <stdlib.h>

char norm(char c);

int main() {
    char str[101];
    int size = 0;
    int flag = 1;
    
    while (scanf("%c", &str[size]) == 1 && str[size] != '\n') {
        size++;
    }
    for (int i = 0, j = size - 1; i <= j; i++, j--) {
        str[i] = norm(str[i]);
        str[j] = norm(str[j]);
        if (str[i] != str[j]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("yes");
    } else {
        printf("No");
    }
    return 0;
}

char norm(char c) {
    if (c >= 'A' && c <= 'Z') {
    c = c + 'a' - 'A';
    }
    return c;
}
