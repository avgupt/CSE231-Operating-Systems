default: 
	echo "32 bit"
	nasm -f elf32 P4_1.asm 
	gcc -m32 -c P4.c
	gcc -m32 P4.o P4_1.o
	echo "64 bit"
	nasm -felf64 P4_1.asm
	gcc -c P4.c
	gcc P4.o P4_1.o
