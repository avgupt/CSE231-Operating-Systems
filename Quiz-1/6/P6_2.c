#include <stdio.h>

void main(){
	FILE *fp = fopen("name.txt","w");
	fputs("Avishi\n", fp);
	fclose(fp);
}
