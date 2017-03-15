#include "simplin.h"

Inputs * parseInput(int numArgs, char ** Args)
{
	Inputs * input = malloc(sizeof(Inputs));

	if (!input) {
		return NULL;
	}

	input->flagCheck = malloc(sizeof(bool) * 3);

	if (!input->flagCheck) {
		return NULL;
	}

	for (int i = 0; i < 3; i++)
		input->flagCheck[i] = false;

	input->fileName = NULL;
	input->noCheck = NULL;
	input->numNoCheck = 0;

	for (int i = 1; i < numArgs; i++) {
		if (Args[i][0] != '-') {
			if (!input->fileName) {
				input->fileName = Args[i];
			} else if (input->flagCheck[noKey]) {
				int holder = 0;
				for (int j = 0; Args[i][j] != '\0'; j++) {

					if (Args[i][j] >= '0' && Args[i][j] <= '9') {
						holder += Args[i][j] - '0';
						if (Args[i][j+1] != '\0')
							holder *= 10;
					} else {
						printf ("Err. Invalid input\n");
						input->flagCheck[help] = true;
						return input;
					}
				}

				if (!input->noCheck) {
					input->noCheck = malloc(sizeof(int));

					if(!input->noCheck) {
						free(input->flagCheck);
						free(input);
						return NULL;
					}

					input->noCheck[0] = holder;
					input->numNoCheck = 1;

				} else {
					input->numNoCheck++;
					int * temp = input->noCheck;
					input->noCheck = malloc(sizeof(int) * input->numNoCheck);

					if(!input->noCheck) {
						free(temp);
						free(input->flagCheck);
						free(input);
						return NULL;
					}

					for(int j = 0; j < input->numNoCheck - 1; j++)
						input->noCheck[j] = temp[j];
					input->noCheck[input->numNoCheck - 1] = holder;
					free(temp);
				}

			} else {
				printf ("Err. Invalid input\n");
				input->flagCheck[help] = true;
				return input;
			}
		} else if (Args[i][0] == '-') {
			for (int j = 1; Args[i][j] != '\0'; j++) {
				switch (Args[i][j])
				{
				case 'h':
					input->flagCheck[help] = true;
					break;
				case 'v':
					input->flagCheck[version] = true;
					break;
				case 'n':
					input->flagCheck[noKey] = true;
					break;
				default:
					break;
				}
			}
		}
	}

	if (!input->fileName && !input->flagCheck[version] && !input->flagCheck[help]) {
		printf ("Err. Invalid input\n");
		input->flagCheck[help] = true;
		return input;
	}

	return input;
}
