#include "shiftcypher.h"

const int ALPHABETSIZE = 26;

char * shiftCypher(char * cryptDat, int key)
{
	while (key < 0)
		key += ALPHABETSIZE;
	key = key % ALPHABETSIZE;
	for (int i = 0; cryptDat[i] != '\0'; i++)
	{
		if ((cryptDat[i] >= 'A' && cryptDat[i] <= 'Z') || (cryptDat[i] >= 'a' && cryptDat[i] <= 'z')) {
			if (cryptDat[i] >= 'A' && cryptDat[i] <= 'Z')
				cryptDat[i] = ((cryptDat[i] - 'A' + key) % ALPHABETSIZE) + 'A';
			else if (cryptDat[i] >= 'a' && cryptDat[i] <= 'z')
				cryptDat[i] = ((cryptDat[i] - 'a' + key) % ALPHABETSIZE) + 'a';
		}
	}
	return cryptDat;
}

double * lettFreq(char * cryptDat)
{
	double * freq = malloc(sizeof(double) * ALPHABETSIZE);
	for (int i = 0; i < ALPHABETSIZE; i++)
		freq[i] = 0;

	for (int i = 0; cryptDat[i] != '\0'; i++) {
		if (cryptDat[i] >= 'A' && cryptDat[i] <= 'Z')
			freq[(cryptDat[i] - 'A') % ALPHABETSIZE]++;
		else if (cryptDat[i] >= 'a' && cryptDat[i] <= 'z')
			freq[(cryptDat[i] - 'a') % ALPHABETSIZE]++;
	}
	return freq;
}

int probableKey(char * cryptDat, int * nogo, int numnogo)
{
	double * freq = lettFreq(cryptDat);
	long numletts = 0;
	for(int i = 0; i < ALPHABETSIZE; i++)
		numletts += freq[i];

	double trueFreq[] = {.08167, .01492, .02782, .04253, .12702, .02228, .02015, .06094, .06966, .00153, .00772, .04025, .02406, .06749, .07507, .01929, .00095, .05987, .06327, .09056, .02758, .00978, .02360, .00150, .01974, .00074};

	int maxkey = -1;
	int total = -1;
	for(int i = 0; i < ALPHABETSIZE; i++) {
		int go = 1;
		if(nogo) {
			for(int j = 0; j < numnogo; j++)
				if(i == nogo[j])
					go = 0;
		}
		if (go) {
			int temptotal = 0;
			for(int j = 0; j < ALPHABETSIZE; j++)
				temptotal += trueFreq[(j + i) % 26] * freq[j];
			if (temptotal > total) {
				total = temptotal;
				maxkey = i;
			}
		}
	}
	free(freq);
	return maxkey;
}
