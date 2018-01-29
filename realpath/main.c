#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <libgen.h>
#define MAX_PATH FILENAME_MAX

int main(int argc, char* argv[]) {
	char absolutePath[MAX_PATH];
	char *ptr = NULL;

	ptr = (char*)malloc(sizeof(char)*10);

	printf("%s\n", argv[0]);
	ptr = realpath(dirname(argv[0]),absolutePath);

	printf("%s\n",ptr);
	return 0;
}
