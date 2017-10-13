#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "initial_curves.h"
#include "destroy.h"

void destroyInitialStructures(curves *crvs)
{
	int i;
	
	for( i=0; i<crvs->totalNumOfCurves; i++ )
		free(crvs -> curveArray[i].points);

	free(crvs -> curveArray);
	free(crvs);
}