### Problem

1.3.9 Write a program that takes from standard input an express without left parentheses and prints the equivalent infix expression with the parenthese inserted. For example, given the input:

    1 + 2 ) * 3 - 4 ) * 5 -  6 ) ) )

your program should print

    ( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) ) )

### Results

```sh
$ make
clang -Wall   -c -o stack.o stack.c
clang -Wall   -c -o queue.o queue.c
clang -Wall   -c -o node.o node.c
clang -Wall    infix.c stack.o queue.o node.o   -o infix

$ ./infix '1 + 2 ) * 3 - 4 ) * 5 -  6 ) ) )'
( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) ) )
```
