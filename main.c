#include "basic.h"
#include "linked_list.h"
#include "array.h"
#include "bs_array.h"
#include "bst.h"
#include "hash.h"
#include "avl_tree.h"
#include "rbt.h"

int main(int argc, char **argv){
	if(argc < 6){
		puts("Too few command line arguments");
		exit(1);
	}


	int tmp_data_insert[MAX_INSERT_LEN];
	int tmp_data_query[MAX_QUERY_LEN];
	DataForProcess *data_insert = (DataForProcess*)calloc(1, sizeof(DataForProcess));
	DataForProcess *data_query = (DataForProcess*)calloc(1, sizeof(DataForProcess));
	int data_structure[MAX_DATA_STRUCTURE_CNT][1];
	//int data_structure_cnt = 0;
	//void (*func_ptr) (char*, char*);
	int i;

	GetRand(tmp_data_insert, tmp_data_query);
	
	for(i=0; i<MAX_DATA_STRUCTURE_CNT; i++){
		data_structure[i][0] = 0;
	}

	argv ++; 	//skip ./
	while(*argv){
		if(strcmp("-d", *argv)==0){
			argv ++;
			data_insert->len = (int)strtod(*argv, NULL);
		}else if(strcmp("-q", *argv)==0){
			argv ++;
			data_query->len = (int)strtod(*argv, NULL);
		} else if(**argv == '-'){
			(*argv) ++;	//skip '-'

			if(!strcmp(*argv, "ll"))
				data_structure[LL][0] = 1;
			else if(!strcmp(*argv, "arr"))
				data_structure[ARR][0] = 1;
			else if(!strcmp(*argv, "bs"))
				data_structure[BS][0] = 1;
			else if(!strcmp(*argv, "bst"))
				data_structure[BST][0] = 1;
			else if(!strcmp(*argv, "avl"))
				data_structure[AVL][0] = 1;
			else if(!strcmp(*argv, "rbt"))
				data_structure[RBT][0] = 1;
			else if(!strcmp(*argv, "hash"))
				data_structure[HASH][0] = 1;
			else
				printf("%s: parameter not found\n", --(*argv));
		}else
			printf("%s: parameter not found\n", *argv);

		argv ++;
	}

	CopyData(data_insert, tmp_data_insert);
	CopyData(data_query, tmp_data_query);

	if(data_structure[LL][0] == 1)
		TestLinkedList(data_insert, data_query);

	if(data_structure[ARR][0] == 1)
		TestArray(data_insert, data_query);

	
	if(data_structure[BS][0] == 1)
		TestBSArray(data_insert, data_query);
	
	
	if(data_structure[HASH][0] == 1)
		TestHash(data_insert, data_query);

	if(data_structure[BST][0] == 1)
		TestBST(data_insert, data_query);

	if(data_structure[AVL][0] == 1)
		TestAVLTree(data_insert, data_query);

	if(data_structure[RBT][0] == 1)
		TestRBT(data_insert, data_query);


	free(data_insert);
	free(data_query);

		
	return 0;
}
