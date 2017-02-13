#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define S_OK 0
#define S_FAIL 1

#define MAX_NODE 5
#define MAX_EDGE 8

int InitializeMatrix(int **ppMap)
{
	if (ppMap == NULL)
	{
		printf ("[Error] Map is empty\n");
		return S_FAIL;
	}
	int i = 0, j = 0;
	printf ("first array: %p\n", ppMap);
	for (i = 0; i < 5; i++)
	{
			printf ("%p\n", ppMap[i]);
			//memset (ppMap[i], 0, MAX_NODE);
			//printf ("%d\n", ppMap[i][j]);
	}
	return S_OK;
}

int CreateRandomMatrix(int ***pppMap)
{
	if (*pppMap != NULL)
	{
		printf ("[Error] Pointer is existed\n");
		return S_FAIL;
	}

	int i = 0, iCol = 0, iRow = 0;
	*pppMap = calloc(MAX_NODE, sizeof(int));
	if (*pppMap == NULL)
	{
		printf ("[Error] The malloc is failed\n");
		return S_FAIL;
	}
	printf ("First Address: %p, %ld\n", *pppMap, sizeof(int *));
	while (i < MAX_NODE)
	{
		printf ("List Addres: %p, %d\n", (*pppMap) + i, i);

		*((*pppMap) + i) = calloc(MAX_NODE, sizeof(int));
		
		printf("Second Array: %p\n", *((*pppMap) + i));
		i ++;
	}

	return S_OK;
}

int main()
{
	int **ppMap = NULL;
	srand(time(0));

	int i;
	CreateRandomMatrix(&ppMap);
	printf ("Main First Address: %p\n", ppMap);
	//InitializeMatrix (ppMap);

	printf ("%p\n", ppMap[4]);
	return S_OK;
}
