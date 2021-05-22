#include "basic.h"
#include "linked_list.h"
#include "array.h"
#include "bs_array.h"
#include "bst.h"

int main(int argc, char **argv){
	if(argc < 6){
		puts("Too few command line argument");
		exit(1);
	}


	//Timeval start, end;
	int tmp_data_insert[MAX_INSERT_LEN];
	int tmp_data_query[MAX_QUERY_LEN];
	DataForProcess *data_insert = (DataForProcess*)calloc(1, sizeof(DataForProcess));
	DataForProcess *data_query = (DataForProcess*)calloc(1, sizeof(DataForProcess));
	char *data_structure[MAX_DATA_STRUCTURE_CNT];
	int data_structure_cnt = 0;
	//void (*func_ptr) (char*, char*);
	int i;

	GetRand(tmp_data_insert, tmp_data_query);
	
	argv ++; 	//skip ./
	while(*argv){
		if(strcmp("-d", *argv)==0){
			argv ++;
			data_insert->len = (int)strtod(*argv, NULL);
		}else if(strcmp("-q", *argv)==0){
			argv ++;
			data_query->len = (int)strtod(*argv, NULL);
		} else{
			(*argv) ++;
			data_structure[data_structure_cnt++] = strdup(*argv);
		}

		argv ++;
	}



	/*
	for(i=0; i<data_structure_cnt; i++){
		//fptr = 
		//test_data_structure(insert_data, query_data, 
	}
	*/

	CopyData(data_insert, tmp_data_insert);
	CopyData(data_query, tmp_data_query);

	TestLinkedList(data_insert, data_query);

	//TestArray(data_insert, data_query);

	TestBSArray(data_insert, data_query);
	
	TestBST(data_insert, data_query);

	free(data_insert);
	free(data_query);

	for(i=0; i<data_structure_cnt; i++)
		free(data_structure[i]);
		
	return 0;
}
