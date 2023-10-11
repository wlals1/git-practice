#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int strsch(char *t, char *p) {
  // t 문자열에서 p 문자열 찾기
  int d = strlen(p);
  int n = 0, j, c;
  for (int i = 0; t[i + d - 1] != 0; i++) {
    j = i;
    n = 0;
    while (j < i + d && t[j] == p[n]) {
      n++;
      j++;
    }
    if (n == d) {
      return 1;
    }
  }
  return 0;
}
int wldsch(char *t, char *p) {
  // t 문자열에서 와일드카드 포함 p 문자열 찾기
  int d = strlen(p);
  int n = 0, j, a, c = 0;
  for (int i = 0; t[i] != 0; i++) {
    j = i;
    n = 0;
    a = 0;
    while (t[j] != 0) {
      if (t[j] == p[a]) {
        n++;
        a++;
      } else if (p[a] == '*') {
        d--;
        a++;
      }
      j++;
    }
    if (n == d) {
      c++;
      continue;
    }
  }
  return c;
}

int main() {
  char text[MAX];
  char pattern[MAX];
  fgets(text, MAX, stdin);
  fgets(pattern, MAX, stdin);
  if (text[strlen(text) - 1] == '\n') {
    text[strlen(text) - 1] = 0;
  }
  if (pattern[strlen(pattern) - 1] == '\n') {
    pattern[strlen(pattern) - 1] = 0;
  }

  int r = wldsch(text, pattern);

  printf("%d", r);
  return 0;
}
