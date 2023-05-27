default: preprocessor compiler assembler linker

preprocessor:
	gcc -E hello.c -o hello.i

compiler:
	gcc -S hello.i -o hello.s

assembler:
	gcc -c hello.s -o hello.o

linker:
	gcc hello.o -o hello
