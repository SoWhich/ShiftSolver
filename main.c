#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "shiftcypher.h"
#include "simplin.h"

int main(int argc, char ** argv)
{
	Inputs * input;
	if(argc == 1) {
		printf("Err. no arguments given\n");
		input = malloc(sizeof(Inputs));
		if(input) {
			input->flagCheck = malloc(sizeof(bool) * 3);
			input->flagCheck[help] = true;
		} else {
			printf("Err. Memory allocation error");
			return -1;
		}
	} else {
		input = parseInput(argc, argv);
	}

	char * contents;

	int key;

	if (input)
	{

		if(input->flagCheck[help]) {
			//todo print help data
			if(input->noCheck)
				free(input->noCheck);
			free(input->flagCheck);
			free(input);
			return 0;
		} else if(input->flagCheck[version]) {
			printf("This is version 2.1 of the shiftcypher ");
			printf("program written by Matthew Kunjummen\n");
			if(input->noCheck)
				free(input->noCheck);
			free(input->flagCheck);
			free(input);
			return 0;
		}

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

		key = probableKey(contents, input->noCheck, input->numNoCheck);
		printf("%d\n", key);
		if(key >= 0)
			contents = shiftCypher(contents, key);
		printf("%s", contents);
		if(input->noCheck)
			free(input->noCheck);
		free(input->flagCheck);
		free(input);
		return 0;
	} else {
		printf("Err. Memory allocation error");
		return -1;
	}
}
