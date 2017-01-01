//Author : prakel
//Date : 31/12/2016
//Maurice J. Bach | page 9 | figure 1.3
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

char buffer[2048];
int version = 1;

void copy(int fdold,int fdnew);

int main(int argc,char *argv[])
{
	int fdold,fdnew;
	if(argc != 3)
	{
		printf("[ERROR] Need 2 arguments for copy program\n");
		exit(1);
	}

	fdold = open(argv[1], O_RDONLY); /*open source file read only*/
	if(fdold == -1)
	{
		printf("[ERROR] Cannot open file - %s\n",argv[1]);
		exit(1);
	}
	printf("[INF]fdold = %d\n",fdold);
	
	fdnew = creat(argv[2],0666);
	if(fdnew == -1)
	{
		printf("[ERROR] Cannot create file - %s\n",argv[2]);
		exit(1);
	}
	printf("[INF]fdnew = %d\n",fdnew);
	copy(fdold,fdnew);
	exit(0);
}

void copy(int fdold,int fdnew)
{
	int count;
	while((count = read(fdold, buffer, sizeof(buffer)))>0)
		write(fdnew,buffer,count);
}	

//exit(1) -> stdlib.h
//read/write -> unistd.h
//open/creat ->fcntl.h
/*
chapter_1 $ ./file_copy_program a b
[INF]fdold = 3
[INF]fdnew = 4
*/
