/*
	#include<sys/types.h>
	#include<sys/stat.h>

	int open(const char *path, int oflags);
	int open(const char *path, int oflags, mode_t modw);
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int file_handle = open("./main.cpp", O_RDONLY);
	if (file_handle != -1) {
		while (file_handle != 0) {
			char buffer[128];
			int nread = read(file_handle, buffer, 128);
			if (nread != -1) {
				if (nread != write(1, buffer, nread)) {
					write(2, "There is a write error\n", 23);
				}
			}
		}

		close(file_handle);
	}

	exit(0);
}