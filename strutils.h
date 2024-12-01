#ifndef STRUTILS_H_INCLUDED
#define STRUTILS_H_INCLUDED

#include <stdbool.h>

bool str_equals(char a[], char b[], int n);
bool str_equals_ignore_case(char a[], char b[], int n);
void str_to_upper(char s[], int n);
void str_to_lower(char s[], int n);


#endif // STRUTILS_H_INCLUDED
