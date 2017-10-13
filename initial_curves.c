#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "initial_curves.h"

extern int dim;

curves* parseAndSave(char *path)
{
	int curveID, i, size, totalCurves, nextAvailablePos, nextAvailablePos_points, maxNumOfPoints, numOfPoints;
	double *points;
	char *split, datasetLine[lineSize_dataset];
	FILE *dataset, *dataset_firstRun;
	curves *crvs;
	curveInfo *curveArray;

	totalCurves = 0;
	nextAvailablePos = 0;
	size = 1;

	crvs = malloc( sizeof(curves) );	//dimiourgia struct tipou curves pou krataei plirofories gia ton pinaka curveArray pou periexei oles tis kampiles
	crvs -> curveArray_size = size;
	crvs -> nextAvailablePos = 0;
	crvs -> totalNumOfCurves = 0;
	crvs -> curveArray = malloc( size * sizeof(curveInfo) );	//dimiourgia pinaka apo curves pou krataei plirofories gia kathe curve tou dataset
	curveArray = crvs -> curveArray;

	dataset = fopen(path, "r");
	dataset_firstRun = dataset;	//antigrafo

	maxNumOfPoints = 0;
	while( fgets(datasetLine, lineSize_dataset, dataset_firstRun) )	//kanoume ena run sthn arxh gia na vroume ton max arithmo simeion pou mporei na exei mia curve
	{
		split = strtok(datasetLine, " ,()\t\r\n");
		split = strtok(NULL, " ,()\t\r\n");
		//printf("%s\n", split);
		numOfPoints = atoi(split);
		if( numOfPoints > maxNumOfPoints )
			maxNumOfPoints = numOfPoints;
	}

	printf("max number of points: %d\n", maxNumOfPoints);

	fclose(dataset);
	dataset = fopen(path, "r");

	memset(datasetLine, 0, lineSize_dataset);

	while( fgets(datasetLine, lineSize_dataset, dataset) )	//deutero perasma gia na kataskeuasoume oses extra domes xreiazetai kai na tis gemisoume
	{
		split = strtok(datasetLine, " ,()\t\r\n");
		if(split)
		{
			printf("curve: %d\n", totalCurves);

			if( nextAvailablePos == size )	//tote realloc giati gemise o pinakas me tis curves
			{
				crvs -> curveArray = realloc(crvs -> curveArray, (2 * size) * sizeof(curveInfo) );
				curveArray = crvs -> curveArray;
				size = 2 * size;
			}

		 
			curveArray[nextAvailablePos].curveID = atoi(split);
			curveArray[nextAvailablePos].dimension = dim;

			split = strtok(NULL, " ,()\t\r\n");
			curveArray[nextAvailablePos].numOfPoints = atoi(split);
			numOfPoints = curveArray[nextAvailablePos].numOfPoints;	//antigrafo
			printf("numOfPoints: %d\n", numOfPoints);

			curveArray[nextAvailablePos].points = malloc( (maxNumOfPoints * dim) * sizeof(double) );
			points = curveArray[nextAvailablePos].points;	//antigrafo
			
			nextAvailablePos_points = 0;

			for( i=0; i<numOfPoints; i++ )	//gemisma pinaka points me simeia
			{
				split = strtok(NULL, " ,()\t\r\n");
				points[nextAvailablePos_points] = atof(split);

				nextAvailablePos_points++;

				split = strtok(NULL, " ,()\t\r\n");
				points[nextAvailablePos_points] = atof(split);

				nextAvailablePos_points++;
				//printf("nextAvailablePos_points: %d\n", nextAvailablePos_points);
			}

			if( maxNumOfPoints > numOfPoints )	//gemisma ean perisepse xoros me midenika
			{
				for( i=(numOfPoints*dim); i<(maxNumOfPoints*dim); i++)
					points[i] = 0.0;
			}

			totalCurves++;
			nextAvailablePos++;
		}
		else
			printf("split is NULL\n");
		

	}
	
	crvs -> totalNumOfCurves = totalCurves;
	crvs -> nextAvailablePos = nextAvailablePos;
	crvs -> curveArray_size = size;

	fclose(dataset);
	
	return crvs;


}
