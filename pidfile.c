#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// without checking error opening file

int main()
{
pid_t pid = fork();
if (pid)
{
int i = getpid();
char filename[15];

sprintf(filename,"file_%d.txt",i);
FILE *file1 = fopen(filename, "w");

fprintf(file1, "Pid: %d\n",i);
fprintf(file1, "child Pid: %d",pid);

fclose (file1);
printf("file parent: %s, created\n",filename);
wait();
}
else
{
int i = getpid();
char filename[15];

sprintf(filename,"file_%d.txt",i);
FILE *file1 = fopen(filename, "w");

fprintf(file1, "Pid: %d\n",i);
fprintf(file1, "parent Pid: %d",getppid());

printf("file child: %s, created\n",filename);

fclose(file1);

}
}
