#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

enum readType{BEGIN,END};

int main(int argc, char *argv[])
{
	enum readType type = BEGIN;
	int offset=0;
	int opt;
	while((opt = getopt(argc,argv,"n:e"))!=-1){
		
		switch(opt)
		{
		case 'n':
			offset = atoi(optarg);
			break;
		case 'e':
			type = END;
			break;
		default:
			exit(EXIT_FAILURE);
		}
	}

	char* filename = argv[optind];

	int ind = open(filename,O_RDONLY);

	if(type == BEGIN){
	
		lseek(ind,offset,SEEK_SET);
	
	}else{
		lseek(ind,-offset,SEEK_END);
	}

	FILE* stream = fdopen(ind,"r");

	while(feof(stream)==0){
		printf("%c",fgetc(stream));
	}
	return 0;
}
