#1
It is “believed” that a program can have only one entry point. Your tasks is
test out this hypothesis. You need to write a program in standalone assembly
language program that has two functions – a start function (not main) where
the execution begins, and a second function, lets call it checkGreater. The

program should begin execution from the start function. The start func-
tion should call the checkGreater along with two arguments x and y such that

the function checks is x >y. If yes, then the function should print a string ”1”,
else it should print a string ”0” using the write(). You could call the write()
system call using assembly language code snippet. For your convenience you
could use the following reference:
https://jameshfisher.com/2018/03/10/linux-assembly-hello-world/
Your task is to explore if it is possible to write a regular C program, having
a main() that should be able to call the checkGreater function, like you would
normally do in other scenarios where a C program calls a assembly function.
Like previous cases, you need to compile (not link) the programs separately
and thereafter link them together in a single binary.

#2
Try to compile the following code snippet (no need to link).
```
add (float a, float b)
{
return (float)(round(a)+round(b));
}
```
Would the compilation of this code snippet result in errors or warnings if
any ? Accurately describe your answers and the reason as to why you observe
what you observe.

#3
The following code snippet is being provided to you:
```
void main()
{
char x[64];
.
.
}
```
You need to complete the above code snippet to firstly store eight 64-bit
integers using a pointer to type long int. Repeat the same exercise to store
sixteen 32-bit integers using a pointer to type int.

#4
1. Write a function called ’long add’ in x86 (32-bit) assembly, which takes
four integers and returns their sum. Then, write a C program that calls
this assembly function.

2. Is there any change needed in ’long add’ function if we want to run the
assembly function in x86-64 (64-bit)? If change is needed, modify the
function and name it ’extended add’. Justify why such change is needed
or is not needed.

#5
Suppose you have an x86-64 processor in an embedded system with only 320KB
of RAM. Then, would you ever use the long mode (64-bit mode) or would you
prefer to use real mode (16-bit mode) for running your program. Please justify
your answer.

#6
1. Write a program to store a string containing your name in main memory.

2. Would your program change if you want to store this string on the disk?
If so, write the program. If not, justify why the program does not change.

