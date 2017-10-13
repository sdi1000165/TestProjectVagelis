#ifndef INITIAL_CURVES__H__
#define INITIAL_CURVES__H__

#define lineSize_dataset 30000

typedef struct curveInfo
{
	int curveID;
	int dimension;
	int numOfPoints;
	int nextAvailablePos;
	double *points;

}curveInfo;

typedef struct curves
{
	int curveArray_size;
	int nextAvailablePos;
	int totalNumOfCurves;
	curveInfo *curveArray;
}curves;

curves* parseAndSave(char *);

#endif