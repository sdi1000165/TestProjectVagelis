#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

userInput_initial askForInput_initial()
{
	int k,L, len, distanceFunction, hashType;
	char userLine[SIZE];
	char *split, *path, *zero ="0";
	userInput_initial input;

	printf("\n> Provide value for k (type 0 for default value)\n");
	printf("> ");

	fgets(userLine, SIZE, stdin);
	split = strtok(userLine, "\r\n");
	if (strcmp(split, zero) == 0)
		input.k = 2;
	else
		input.k = atoi(split);

	printf("\n> Provide value for L (type 0 for default value)\n");
	printf("> ");

	memset(userLine, 0, SIZE);

	fgets(userLine, SIZE, stdin);
	split = strtok(userLine, "\r\n");
	if (strcmp(split, zero) == 0)
		input.L = 3;
	else
		input.L = atoi(split);

	printf("k= %d    L= %d\n", input.k, input.L);

	printf("\n> Provide Dataset Path, Distance Function (1:Frechet, 2:DTW), Hash Type (1:Deterministic, 2:LSH) [tab separated]\n");
	printf("> ");

	memset(userLine, 0, SIZE);

	fgets(userLine, SIZE, stdin);

	split = strtok(userLine, "\t\r\n");
	len = strlen(split);
	input.path = malloc( (len+1) * sizeof(char) );
	strcpy(input.path, split);

	split = strtok(NULL, "\t\r\n");	
	input.distanceFunction = atoi(split);

	split = strtok(NULL, "\t\r\n");	
	input.hashType = atoi(split);

	printf("Path: %s, Distance Function: %d, Hash Type: %d\n", input.path, input.distanceFunction, input.hashType);

	//free(input.path);

	return input;
}


userInput_query askForInput_query()
{

}

