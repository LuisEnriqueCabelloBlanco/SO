#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy(int fdo, int fdd)
{
	char buff [512];
	
	int count = 0;
	while(count > 0){ 
		count = read(fdo,buff,512);
		write(fdo,buff,count);
	}
	
}

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Uso Invalid \nUsage: <input-file> <new-file-name>");
		exit(EXIT_FAILURE);
	}

	int fdo = open(argv[1],O_RDONLY|O_TRUNC);
	if(fdo < 0){
		printf("File %s could not open\n",argv[1]);
	}

	int fdd = open(argv[2],O_WRONLY|O_RDONLY|O_CREAT);
	if(fdd < 0){
                printf("File %s  could not open\n",argv[2]);
        }

	copy(fdo,fdd);

	return 0;
}
