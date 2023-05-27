default: preprocessor compiler assembler assembly_code linker

assembly_code:
	nasm -felf64 sum.asm

preprocessor:
	gcc -E prog-add.c -o prog-add.i

compiler:
	gcc -S prog-add.i -o prog-add.s

assembler:
	gcc -c prog-add.s -o prog-add.o

linker:
	gcc prog-add.o sum.o -o prog-add
