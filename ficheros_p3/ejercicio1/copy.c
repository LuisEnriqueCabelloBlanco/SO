#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy(int fdo, int fdd)
{
	char buff [512];
	
	int count = 1;
	while(count > 0){ 
		count = read(fdo,buff,512);
		int a = write(fdd,buff,count);
		if(a<0){
			printf("Fallo en escritura del fichero %d\n",fdd);
			exit(EXIT_FAILURE);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Uso Invalid \nUsage: <input-file> <new-file-name>");
		exit(EXIT_FAILURE);
	}

	int fdo = open(argv[1],O_RDONLY);
	if(fdo < 0){
		printf("File %s could not open\n",argv[1]);
	}
	int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	int fdd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,mode);
	if(fdd < 0){
                printf("File %s  could not open\n",argv[2]);
        }

	copy(fdo,fdd);

	return 0;
}
