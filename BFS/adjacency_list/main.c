#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S_OK 0
#define S_FAIL 1


typedef struct adjlist {
	int iNode;
	int iMarkFlag;
	struct adjlist *pNext;
} TAdjList;

int InitialMap(TAdjList *ptMap, int iMaxNode)
{
	if (ptMap == NULL)
	{
		printf ("[Error] The map is error\n");
		return S_FAIL;
	}
	int i = 0;

	while (i < iMaxNode)
	{
		ptMap->iNode = -1;
		ptMap->iMarkFlag = 0;
		ptMap->pNext = NULL;
		ptMap++;
		i++;
	}
	return S_OK;
}

int swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return S_OK;
}
int DisplayMap(TAdjList *ptMap, int iMaxNode)
{
	int i = 0;
	TAdjList *ptTemp = NULL;
	for(i = 0; i < iMaxNode; i++)
	{
		ptTemp = ptMap + i;
		while (ptTemp != NULL)
		{
			printf ("(%d) ->", ptTemp->iNode);
			ptTemp = ptTemp->pNext;
		}
		printf ("\n");
	}
	return S_OK;
}
int CreateRandomMap(TAdjList *ptMap, int iMaxNode, int iMaxEdge)
{
       	TAdjList *ptTempNewNode;//My ggc-5.4.0 is strange. it cannot put the later line
	int iTempNode;
	int i = 0;
	int iTempNextNode;
	TAdjList *ptTempCur = NULL;
	TAdjList *ptTempPrev = NULL;

	srand(time(0));
	while (i < iMaxEdge)
	{
		iTempNode = rand() % iMaxNode;
		iTempNextNode = rand() % iMaxNode;

		printf ("Temp Node: %d, NextNode: %d\n", iTempNode, iTempNextNode);

		ptTempNewNode = NULL;
       		ptTempNewNode = malloc(sizeof (TAdjList));//My ggc-5.4.0 is strange. it cannot put the later line
		if ((ptMap + iTempNode)->iNode == -1)
		{
			//represent the node is empty
			(ptMap + iTempNode)->iNode = iTempNextNode;
			(ptMap + iTempNode)->pNext = NULL;
		}
		else
		{
			ptTempNewNode->iNode = iTempNextNode;
			ptTempNewNode->pNext = NULL;

			//sorting and insert the value to list
			ptTempCur = ptMap + iTempNode;
			ptTempPrev = ptTempCur;
			while (1)
			{
				if (ptTempCur->iNode == ptTempNewNode->iNode)
				{
					printf ("Exist %d", ptTempNewNode->iNode);
					ptTempNewNode->iNode = rand() % iMaxNode;
					printf (" to %d\n", ptTempNewNode->iNode);
					ptTempCur = ptMap + iTempNode;
					ptTempPrev = ptTempCur;
				}
				if (ptTempCur->iNode > ptTempNewNode->iNode && ptTempCur == ptTempPrev)
				{
					//means the first node needed to be replace by the new node
					ptTempNewNode->pNext = ptTempCur->pNext;
					ptTempCur->pNext = ptTempNewNode;
					swap(&(ptTempCur->iNode), &(ptTempNewNode->iNode));
					break;
				}
				else if (ptTempCur->iNode > ptTempNewNode->iNode && ptTempCur != ptTempPrev)
				{
					//means the insert between the two node.
					ptTempNewNode->pNext = ptTempCur;
					ptTempPrev->pNext = ptTempNewNode;
					break;
				}
				else if (ptTempCur->pNext == NULL)
				{
					ptTempCur->pNext = ptTempNewNode;
					break;
				}
				ptTempPrev = ptTempCur;
				ptTempCur = ptTempCur->pNext;
			}
		}
		i++;
	}
	return S_OK;
}
int InitialUnweightList(TAdjList **pptMap, int iMaxNode, int iMaxEdge)
{
	if (*pptMap != NULL)
	{
		printf ("[Error] Already Create a address\n");
		return S_FAIL;
	}

	*pptMap = malloc (sizeof (TAdjList) * iMaxNode);
	if (*pptMap == NULL)
	{
		printf ("[Error] Create Error\n");
		return S_FAIL;
	}

	InitialMap(*pptMap, iMaxNode);
	return S_OK;
}

int main()
{
	TAdjList *ptMap = NULL;
	int iMaxNode;
	int iMaxEdge;

	printf ("How many node on the map?");
	scanf ("%d", &iMaxNode);

	printf ("How many edge on the map?");
	scanf ("%d", &iMaxEdge);

	InitialUnweightList(&ptMap, iMaxNode, iMaxEdge);
	CreateRandomMap(ptMap, iMaxNode, iMaxEdge);
	DisplayMap(ptMap, iMaxNode);
	return S_OK;
}
