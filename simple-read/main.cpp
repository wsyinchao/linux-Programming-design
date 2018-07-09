/*
	º¯ÊýÔ­ÐÍ

	#include<unistd.h>

	size_t read(int fileds, void *buff, size_t nbytes);
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	char buffer[128];
	int nread;

	nread = read(0, buffer, 128);
	if (nread == -1) {
		//read failed
		write(2, "Here is a read error\n", 21);
	}
	
	//write
	if (nread != write(1, buffer, nread)) {
		write(2, "Here is a write error\n", 22);
	}

	return 0;
}