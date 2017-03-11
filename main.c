#include <stdlib.h>
#include <stdio.h>
#include "shiftcypher.h"

int main()
{
	FILE * infile = fopen("tobechecked.txt", "r");
	unsigned int length = 0;
	char * contents;
	int key;
	if (infile) {
		fseek(infile, 0, SEEK_END);
		length = ftell(infile);
		rewind(infile);
		contents = malloc(sizeof(char) * (length + 1));
		if (contents)
			fread(contents, sizeof(char), (size_t)length, infile);
		else
			return -1;
	} else
		return -1;

	key = probableKey(contents);
	printf("%d\n", key);
	if(key >= 0)
		contents = shiftCypher(contents, key);
	printf("%s", contents);
	return 0;
}
