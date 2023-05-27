# Combining C and Assembly Language Programs
You need to do the following:

1. Write a program that takes two integers as user inputs. Lets call it prog-
add.c.

2. The program calls a function add, that is written in assembly languge
(x86-64). The program takes two arguments from the stack – viz. the two
integers that are passed from the main() function of prog-add.c.
3. The add function takes two integer arguments, add them and returns
them. The main function of prog-add.c should print this sum (that has
been computed by the add function.