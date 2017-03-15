#include <stdlib.h>
#include <stdio.h>
#include "shiftcypher.h"
#include "simplin.h"

int main(int argc, char ** argv)
{
	Inputs * input;
	if(!argc) {
		printf("Err. no arguments given\n");
		return -1;
	} else {
		input = parseInput(argc, argv);
	}

	char * contents;

	int key;

	if (input)
	{
		FILE * infile = fopen(input->fileName, "r");
		unsigned long long length = 0;

		if (infile) {
			fseek(infile, 0, SEEK_END);
			length = ftell(infile);
			rewind(infile);
			contents = malloc(sizeof(char) * (length + 1));
			if (contents) {
				fread(contents, sizeof(char), (size_t)length, infile);
			} else {
				printf("Err. Memory allocation error");
				return -1;
			}
		} else {
			printf("Err. Memory allocation error");
			return -1;
		}

		if(input->flagCheck[help]) {
			//todo print help data
			return 0;
		} else if(input->flagCheck[version]) {
			printf("This is version 2.1 of the shiftcypher program, written by Matthew Kunjummen\n");
			return 0;
		}

		key = probableKey(contents, input->noCheck, input->numNoCheck);
		printf("%d\n", key);
		if(key >= 0)
			contents = shiftCypher(contents, key);
		printf("%s", contents);
		return 0;
		if(input->noCheck)
			free(input->noCheck);
		free(input->flagCheck);
		free(input);
	} else {
		printf("Err. Memory allocation error");
		return -1;
	}
}
