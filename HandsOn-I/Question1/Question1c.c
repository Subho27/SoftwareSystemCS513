#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *mkfifoName = "./mymkfifo";  
    char *mknodName = "./mymknod-fifo"; 

    int mkfifo_status, mknod_status; 

    mkfifo_status = mkfifo(mkfifoName, S_IRWXU);

    if (mkfifo_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    mkfifo_status = mknod(mknodName, __S_IFIFO | S_IRWXU, 0);

    if (mknod_status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
}
