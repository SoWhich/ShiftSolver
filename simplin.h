#ifndef _simplin_h_
#define _simplin_h_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {noZero, version, topN, noKey} Flags;

typedef struct {
	int * noCheck;
	int numNoCheck;
	bool * flagCheck;
	char * fileName;
	int topN;
} Inputs;

Inputs * parseInput(int, char **);

#endif
