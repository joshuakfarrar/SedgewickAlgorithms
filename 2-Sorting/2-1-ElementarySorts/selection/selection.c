#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void fillBuffer(char[], FILE*);
void sort(char[]);
void exchange(char[], int, int);

void fillBuffer(char buffer[], FILE *stream) {
  char c;
  int i = 0;
  while((c = fgetc(stream)) != EOF) {
    if (i == MAX_SIZE) {
        fprintf(stderr, "Error: buffer overflow!\n");
        exit(1);
    }
    switch(c) {
      case ' ':
      case '\n':
        break;
      default:
        buffer[i++] = c;
        break;
    }
  }
  buffer[i] = '\0';
}

void sort(char buffer[]) {
    int i, j,
        length = strlen(buffer);

    for (i = 0; i < length; i++) {
        int min = i;
        for (j = i + 1; j < length; j++) {
          if (buffer[j] < buffer[min]) {
              min = j;
          }
        }
        exchange(buffer, i, min);
    }

    return;
}

void exchange(char buffer[], int current, int with) {
    char placeholder = buffer[current];
    buffer[current] = buffer[with];
    buffer[with] = placeholder;
    return;
}

int main(int argc, char * argv[]) {
    char buffer[MAX_SIZE];

    fillBuffer(buffer, stdin);
    printf("%s\n", buffer);

    sort(buffer);
    printf("%s\n", buffer);

    return 0;
}
