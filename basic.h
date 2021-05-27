#ifndef _BASIC_H_
#define _BASIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX_DATA_LEN ((int)1e6)
//#define MAX_INSERT_LEN ((int)1e6)
//#define MAX_QUERY_LEN ((int)1e5)
#define MAX_DATA_STRUCTURE_CNT 7

enum{
	LL,
	ARR,
	BS,
	BST,
	AVL,
	RBT,
	HASH
};

typedef struct timeval Timeval;

typedef struct{
	int data[MAX_DATA_LEN];
	int len;
}DataForProcess;

void GetRand(int *insert, int *query);
void CopyData(DataForProcess *to, int *from);


#endif


