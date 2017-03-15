#include "simplin.h"

Inputs * parseInput(int numArgs, char ** Args)
{
	Inputs * input = malloc(sizeof(Inputs));
	input->flagCheck = malloc(sizeof(bool) * 4);
	for (int i = 0; i < numArgs; i++) {
		if (Args[i][0] != '-') {
			if (!input->fileName)
				input->fileName = Args[i];
		} else if (Args[i][0] == '-') {
			for (int j = 1; Args[i][j] != '\0'; j++) {
				switch (Args[i][j])
				{
				case 'z':
					input->flagCheck[noZero] = true;
					break;
				case 'v':
					input->flagCheck[version] = true;
					break;
				case 't':
					input->flagCheck[topN] = true;
					for (int k = 1; Args[i+k][0] >= '0' && Args[i+k][0] <= '9'; k++) {
						int p = 0;
						p++;
					}
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
	return input;
}
