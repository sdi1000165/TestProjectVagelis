#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "initial_curves.h"
#include "destroy.h"

int dim = 2;	//dimension

int main(int argc, char* argv[])
{
	userInput_initial input_initial;	
	userInput_query input_query;	// eisodos xristi gia to arxeio me ta queries kai to arxeio eksodou apotelesmaton
	curves *crvs;

	input_initial = askForInput_initial();	// arxiki eisodos apo xristi (k, L, dataset path klp)

	printf("Yo\n");

	crvs = parseAndSave(input_initial.path);	//sinartisi pou kanei parse to arxiko dataset kai kataskeuazei vasi autou tis arxikes domes

	printf("Yo2\n");

	destroyInitialStructures(crvs);

	free(input_initial.path);

	return 0;
}