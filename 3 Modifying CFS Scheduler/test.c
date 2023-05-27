/* Name: Avishi Gupta
   Roll_Number: 2019155 */

#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
	int pid;
	pid = fork();

	//printf("Hello");

	if(pid != 0)
	{
		syscall(441,pid,100);

		clock_t parent_begin = clock();
		for(long i=0;i<1000000000;i++);
		clock_t parent_end = clock();		
		printf("\n%lf (parent)\n", (double)(parent_end - parent_begin)/CLOCKS_PER_SEC);

		wait(NULL);
	}
	else
	{
		clock_t child_begin = clock();
		for(long i=0;i<1000000000;i++);
		clock_t child_end = clock();

		printf("\n%lf (child)\n", (double)(child_end - child_begin)/CLOCKS_PER_SEC);
		

	}
	return 0;

}
