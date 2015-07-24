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
    int h, i, j,
        length = strlen(buffer);

    while (h < (length / 3)) h = 3 * h + 1;
    while (h >= 1) {
        for (i = 1; i < length; i++) {
            for (j = i; ((j >= h) && (buffer[j] < buffer[(j - h)])); j -= h) {
                exchange(buffer, j, (j - h));
            }
        }
        h /= 3;
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
