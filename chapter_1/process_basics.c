//Author : prakel
//Date : 01/01/2017
//Maurice J. Bach | Page 11 | Program 1.4
#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fork_ret;
	fork_ret = fork();
	printf("Value of fork = %d\n",fork_ret);
	if(fork()==0)
		execl("file_copy_program","file_copy_program",argv[1],argv[2],0);
	wait((int *)0);
	printf("Copy done!\n");
	return 0;
}
//fork()->unistd.h
//doubt, lines - 12,13,14

/*
chapter1 $ ./process_basics a b
Value of fork = 2640
Value of fork = 0
[INF]fdold = 3
[INF]fdold = 3
[INF]fdnew = 4
[INF]fdnew = 4
Copy done!
Copy done!
*/
