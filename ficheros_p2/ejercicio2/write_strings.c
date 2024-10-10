#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

int main(int argc, char* argv[])
{
	if (argc <2) {
		fprintf(stderr,"Usage: %s <file_name>\n",argv[0]);
		exit(1);
	}
	FILE* file = fopen(argv[1],"w");
	char* buffer;
	for(int i=2;i<argc;i++){
		fwrite(argv[i],sizeof(char),strlen(argv[i])+1,file);
	}
	
	fclose(file);
	/* To be completed */
	return 0;
}
