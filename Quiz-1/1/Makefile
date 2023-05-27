default:
	gcc -c problem1.c
	echo "Without global _start"
	nasm -felf64 assembly2.asm
	gcc assembly2.o problem1.o

	echo "With global _start"
	nasm -felf64 assembly1.asm
	gcc assembly1.o problem1.o	


