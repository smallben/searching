#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S_OK 0
#define S_FAIL 1

typedef struct item {
	int iData;
	struct item *pNext;
} TItem;

int InitiialHashTable(TItem *ptHashTable, int iHashTableLength)
{
	int i = 0;
	while (i < iHashTableLength)
	{
		(ptHashTable + i)->iData = -1;
		(ptHashTable + i)->pNext = NULL;
		i++;
	}
	return S_OK;
}

int CreateHashTable(TItem **pptHashTable, int iHashTableLength)
{
	if (*pptHashTable != NULL)
	{
		printf ("[Error] The table is already existed\n");
		return S_FAIL;
	}

	*pptHashTable = malloc (sizeof (TItem) * iHashTableLength);
	if (*pptHashTable == NULL)
	{
		printf ("[Error] The table array cannot create\n");
		return S_FAIL;
	}

	InitiialHashTable(*pptHashTable, iHashTableLength);

	return S_OK;
}

int DisplayHashTable(TItem *ptHashTable, int iHashTableLength)
{
	int i = 0;
	TItem *ptCur = ptHashTable;
	while(i < iHashTableLength)
	{
		ptCur = ptHashTable + i;
		while (ptCur != NULL)
		{
			printf ("%d ", ptCur->iData);
			ptCur = ptCur->pNext;
		}
		printf ("\n");
		i++;
	}
	return S_OK;
}

int main()
{
	int iHashTableLength = 0;
	TItem *ptHashTable = NULL;
	printf ("Enter the hash table length ?");
	scanf("%d", &iHashTableLength);

	CreateHashTable(&ptHashTable, iHashTableLength);
	DisplayHashTable (ptHashTable, iHashTableLength);


	return S_OK;
}
