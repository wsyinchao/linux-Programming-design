/*
	copy file program.
*/

#include<stdio.h>
#include<stdlib.h>

void copyFileCharByChar()
{
	char c;

	FILE *in = fopen("main.cpp", "r");
	FILE *out = fopen("m.out", "w");

	while ((c = fgetc(in)) != EOF) {
		fputc(c, out);
	}
}

int main()
{
	copyFileCharByChar();

	return 0;
}
