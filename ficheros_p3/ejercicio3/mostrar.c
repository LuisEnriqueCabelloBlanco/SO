#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum readType{BEGIN,END};

int main(int argc, char *argv[])
{
	readType type = BEGIN;
	int offset=0;
	while((opt = getopt(argc,argv,"n:e"))!=-1){
		
		switch(opt)
		{
		case 'n':
			offset = optarg;
			break;
		case 'e':
			type = END;
			break;
		default:
			exit(EXIT_FAILURE);
		}
	}

	
	return 0;
}
