#include "strutils.h"
#include <stdbool.h>
#include <string.h>

bool str_equals(char a[], char b[], int n) {
    int alen = strnlen(a, n);
    int blen = strnlen(b, n);

    if (alen != blen)
        return false;

    for (int i = 0; i < alen; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void str_to_lower(char s[], int n) {
    int len = strnlen(s, n);
    int offset = 'a' - 'A';

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + offset;
        }
    }
}

void str_to_upper(char s[], int n) {
    int len = strnlen(s, n);
    int offset = 'a' - 'A';

    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - offset;
        }
    }
}

bool str_equals_ignore_case(char* a, char* b, int n) {
    int alen = strnlen(a, n);
    int blen = strnlen(b, n);

    if (alen != blen) {
        return false;
    }

    char acopy[alen + 1];
    char bcopy[blen + 1];

    memset(acopy, 0, sizeof(char) * alen + 1);
    memset(bcopy, 0, sizeof(char) * alen + 1);

    strncpy(acopy, a, alen);
    strncpy(bcopy, b, blen);

    str_to_lower(acopy, alen);
    str_to_lower(bcopy, blen);

    return str_equals(acopy, bcopy, alen);
}
