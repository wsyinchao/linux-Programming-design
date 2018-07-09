/*
	write 文件调用原型

	#include<unistd.h>

	size_t write(int file, const void *buf, size_t nbytes);
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	if (write(1, "Here is some data\n", 18) != 18) {
		write(2, "A write error has occurred on file descriptor 1\n", 46);
	}

	return 0;
}