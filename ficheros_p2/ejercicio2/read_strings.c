#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

/** Loads a string from a file.
 *
 * file: pointer to the FILE descriptor
 *
 * The loadstr() function must allocate memory from the heap to store
 * the contents of the string read from the FILE.
 * Once the string has been properly built in memory, the function returns
 * the starting address of the string (pointer returned by malloc())
 *
 * Returns: !=NULL if success, NULL if error
 */
char *loadstr(FILE *file)
{	
	
	int ind = 'a';
	int size = 0;
	while(ind != '\0'){
		ind =fgetc(file);
		size++;
	}
	fseek(file,-size,SEEK_CUR);
	char* buff= malloc(size);
	fread(buff,sizeof(char),size,file);
	/* To be completed */
	return buff;	
}

int main(int argc, char *argv[])
{
	FILE* file = fopen(argv[1],"r");
	

	while(getc(file)!=EOF){
		fseek(file,-1,SEEK_CUR);
		char* word = loadstr(file);
		printf("%s\n",word);
	}
	/* To be completed */
	fclose(file);
	return 0;
}
