#include <stdio.h>

int strlen(char* str, int max_len) {
    int i;
    for (i = 0; i < max_len; i++) {
        if (str[i] == '\0') {
            break;
        }
    }
    return i;
}

int strcomp(char* a, char* b, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int strstr(char* str, char* sub, int strlen, int sublen) {
    int i;
    for (i = 0; i <= strlen - sublen; i++) {
        if (1 == strcomp(str + i, sub, sublen)) {
            return i;
        }
    }
    return -1;
}


int main() {
    char str[256], sub[256];
    int len_str, len_sub, pos, counter = 0;
    char* cursor;

    printf("Input string: ");
    gets_s(str, 256);
    len_str = strlen(str, 256);

    if (len_str == 0) {
        printf("Empty string\n");
        return 0;
    }

    printf("Input model: ");
    gets_s(sub, 256);
    len_sub = strlen(sub, 256);

    if (len_sub == 0) {
        printf("No data\n");
        return 0;
    }

    cursor = str;

    for (;;) {

        pos = strstr(cursor, sub, len_str, len_sub);
        if (pos == -1) {
            if (counter == 0) {
                printf("Model not found\n");
            }
            break;
        }
        counter += 1;

        printf("Position: %d\n", cursor - str + pos);
        cursor += pos + len_sub;
    }
    return 0;
}

