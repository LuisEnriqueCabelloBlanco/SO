#include <stdio.h>
#include <stdlib.h>
#include <err.h>

int main(int argc, char* argv[]) {
	FILE* file=NULL;

	if (argc!=2) {
		fprintf(stderr,"Usage: %s <file_name>\n",argv[0]);
		exit(1);
	}
	/* Open file */
	if ((file = fopen(argv[1], "r")) == NULL)
		err(2,"The input file %s could not be opened",argv[1]);
	unsigned int val;
	fseek(file,0,SEEK_END);
	val = ftell(file);
	fseek(file,0,SEEK_SET); 
	unsigned char* buffer;
	
	buffer = malloc(val);
	

	size_t ret1 = fread(buffer,val,sizeof(*buffer),file);

	if (ret1 != 1) {
        	fprintf(stderr, "fread() failed: %zu\n", ret1);
        	exit(EXIT_FAILURE);
        }
	
	fseek(file,0,SEEK_SET);

	fwrite(buffer,val,sizeof(*buffer),stdout);

	fclose(file);
	return 0;
}
