/*
	fopen()
	fwrite()
	fread()
	fclose()
	
	printf()
	sprintf()
	fprintf()

	fgets()
	gets()

	fputc()
	putc()
	putchar()

	fgetc()
	getc()
	getchar()

	fseek()

	fflush()

	TIMEFORMAT="" time ./xxx --输出程序运行所用时间等信息
*/

/*
	simple-copyfile.cpp
*/

#include<stdio.h>
#include<unistd.h>

#include <stdlib.h>

struct threeNum
{
	int n1, n2, n3;
};

int seek_main()
{
	int n;
	struct threeNum num;
	FILE *fptr;

	if ((fptr = fopen("main.out", "rb")) == NULL) {
		printf("Error! opening file");

		// Program exits if the file pointer returns NULL.
		exit(1);
	}

	// Moves the cursor to the end of the file
	fseek(fptr, sizeof(struct threeNum), SEEK_END);

	for (n = 1; n < 5; ++n)//because cursor on the end of file, so this output is no declaration variable.
	{
		fread(&num, sizeof(struct threeNum), 1, fptr);
		printf("n1: %d\tn2: %d\tn3: %d", num.n1, num.n2, num.n3);
	}
	fclose(fptr);

	return 0;
}

void testPrintfFormat(void)
{
	int n = 1234;
	char str[10] = "Hello";

	float fn = 12.34;

	putchar(10);

	printf("%10s\n", str);
	printf("%-10s\n", str);
	printf("%10d\n", n);
	printf("%-10d\n", n);
	printf("%010d\n", n);
	printf("%10.4f\n", fn);
}

void testScanfFormat(void)
{
	char s[256];
	int n;
	float f;
	char c;

	scanf("Hello, %d, %g, %c, %[^\n]", &n, &f, &c, s);

	putchar(10);
	printf("%d\n", n);
	printf("%g\n", f);
	printf("%c\n", c);
	printf("%s\n", s);
}

int main()
{
	/*FILE *pfile = fopen("main.cpp", "r");
	if (pfile != NULL) {
		FILE *pfile_out = fopen("main.putout", "w");
		if (pfile_out != NULL) {

			char buff[1024];
			size_t nread = 1;
			while (pfile_out != EOF) {
				if (nread == fread(buff, sizeof(buff), 1, pfile)) {
					if (nread != fwrite(buff, sizeof(buff), 1, pfile_out)) {
						write(2, "There is a error when written\n", 30);
						break;
					}
				}
			}
			fclose(pfile_out);
		}
	}
	fclose(pfile);*/

	printf("seek main start here!\n");
	seek_main();
	testPrintfFormat();
	testScanfFormat();

	return 0;
}
