#ifndef INPUT__H__
#define INPUT__H__

#define SIZE 100

typedef struct userInput_initial
{
	int k;
	int L;
	char *path;
	int distanceFunction;
	int hashType;
}userInput_initial;

typedef struct userInput_query
{
	char *queryDatasetPath;
	char *outputFilePath;
}userInput_query;

userInput_initial askForInput_initial();
userInput_query askForInput_query();


#endif