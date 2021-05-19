#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basic.h"

int main(int argc, char **argv){
	if(argc < 6){
		puts("Too few command line argument");
		exit(1);
	}


	DataForProcess data_for_insert;
	DataForProcess data_for_query;
	char *data_structure[MAX_DATA_STRUCTURE_CNT];
	int data_structure_cnt = 0;
	void (*func_ptr) (char*, char*);
	int i;

	
	argv ++; 	//skip ./
	while(*argv){
		if(strcmp("-d", *argv)==0){
			argv ++;
			data_for_insert.len = (int)strtod(*argv, NULL);
		}else if(strcmp("-q", *argv)==0){
			argv ++;
			data_for_query.len = (int)strtod(*argv, NULL);
		} else{
			(*argv) ++;
			data_structure[data_structure_cnt++] = strdup(*argv);
		}

		argv ++;
	}



	for(i=0; i<data_structure_cnt; i++){
		//fptr = 
		//test_data_structure(insert_data, query_data, 
	}

	for(i=0; i<data_structure_cnt; i++)
		free(data_structure[i]);
		
	return 0;
}

