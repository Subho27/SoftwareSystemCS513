#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *args[]){
	struct flock lock, lockStatus;
	char *filename;
	if(argc != 2){
		printf("Please enter a filename to check status.\n");
	}
	else{
		/* F_RDLCK = 0
		 * F_WRLCK = 1
		 * F_UNLCK = 2 */

		filename = args[1];

		lock.l_type = 1;

		int fd = open(filename, O_RDONLY);

		fcntl(fd, F_GETLK, &lockStatus);
		
		if(lockStatus.l_type == 0){
			printf("File is already locked with reading lock.\n");
		}
		else{
			int status = fcntl(fd, F_SETLK, &lock);
			if(status == -1){
				printf("Can not aquire Write lock as it is already locked for reading.\n");
			}
			else{
				printf("Primary process could not lock for reading.\n");
			}
		}

	}
	return 0;
}
