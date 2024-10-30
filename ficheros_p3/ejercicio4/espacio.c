#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

/* Forward declaration */
int get_size_dir(char *fname, size_t *blocks);

/* Gets in the blocks buffer the size of file fname using lstat. If fname is a
 * directory get_size_dir is called to add the size of its contents.
 */
int get_size(char *fname, size_t *blocks)
{
	struct stat buf;
	lstat(fname,&buf);
	if(S_ISDIR(buf.st_mode)){
		return get_size_dir(fname,blocks);
		
	}else{
		(*bocks)+=st_blocks;
	}
	return 0;
}


/* Gets the total number of blocks occupied by all the files in a directory. If
 * a contained file is a directory a recursive call to get_size_dir is
 * performed. Entries . and .. are conveniently ignored.
 */
int get_size_dir(char *dname, size_t *blocks)
{
	DIR* dir =  opendir(name);

	struct dirent* data = readdir(dir);
}

/* Processes all the files in the command line calling get_size on them to
 * obtain the number of 512 B blocks they occupy and prints the total size in
 * kilobytes on the standard output
 */
int main(int argc, char *argv[])
{

	
	for(int i = 1;i<argc;i++){
		int size;
		get_size(argv[i],&size);
	}

	return 0;
}
