#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc , char *argv[]){
	if(argc==1){
		printf("Usage : <path><target>\n");
		printf("Usage: <path>...<dir>\n");
		return 0;
	}
	const char *target =argv[argc-1];
	argc--;

	struct stat st;

	if(stat(target , &st)){
		if(errno == ENOENT && argc == 2){
			const char *path = argv[1];
			if(rename(path,target)){
				perror(path);
				return 1;
			}	
			return 0;
		}
		perror(target);
		return 1;
	}
	return 0;


}

