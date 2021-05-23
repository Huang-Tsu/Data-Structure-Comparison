#include "basic.h"
#include "hash.h"

struct HashTable{
	int value;
	HashTable *next;
	HashTable *tail;
};

	static long long g_query_cnt = 0;
	static int g_find_cnt = 0;
		static int g_HASH_SIZE = (int)1e4;

void TestHash(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	HashTable **root;

		for(int i=0; i<3; i++){
			g_query_cnt = 0;
			g_find_cnt = 0;
	printf("\t\033[3m\033[1mHash:\t(table size:%d\033[m\n", g_HASH_SIZE);
	
	gettimeofday(&start, NULL);
	root = BuildHashTable(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryHashTable(root, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");
	FreeHashTable(root);
		g_HASH_SIZE *= 10;
		}
	//free(root);


	return;
}
HashTable **BuildHashTable(DataForProcess *insert){
	int i;
	int insert_len = insert->len;
	HashTable **root = (HashTable**)calloc(g_HASH_SIZE, sizeof(HashTable*));

	
	for(i=0; i<g_HASH_SIZE; i++)
		root[i] = NULL;

	for(i=0; i<insert_len; i++){
		InsertHashNode(root, insert->data[i]);
	}

	return root;
}
void QueryHashTable(HashTable **root, DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		LookUpTable(root, query->data[i]);
	}

	return;
}
void InsertHashNode(HashTable **table, int input){
	static int idx;
			//static HashTable *hash_list;
	idx = Hash(input);
			//hash_list = table[idx];

	if(!table[idx]){
		table[idx] = InitializeHashNode(input);
		return;
	}else{
			//for(hash_list; hash_list->next; hash_list=hash_list->next)	
				//;
			//hash_list->next = InitializeHashNode(input);
		table[idx]->tail->next = InitializeHashNode(input);
		table[idx]->tail = table[idx]->tail->next;
	}

}
HashTable *InitializeHashNode(int input){
	static HashTable *new_node;
	new_node = (HashTable*)calloc(1, sizeof(HashTable));
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->next = NULL;
	new_node->tail = new_node;

	return new_node;
}
void FreeHashTable(HashTable **table){
	for(int i=0; i<g_HASH_SIZE; i++){
		if(table[i])
			FreeTableList(table[i]);
	}
	free(table);
}
void FreeTableList(HashTable *ptr){
	static HashTable *next_node;

	for(ptr; ptr; ptr=next_node){
		next_node = ptr->next;
		free(ptr);
	}
}
void LookUpTable(HashTable **table, int input){
	static int idx;
	static HashTable *table_list;
	idx  = Hash(input);
	table_list = table[idx];

	if(!table_list){
			g_query_cnt++;
		return;
	} else{
		for(table_list; table_list!=NULL; table_list=table_list->next){
				g_query_cnt++;
			if(table_list->value == input){
					g_find_cnt++;
				return;
			}
		}
	}
}
inline int Hash(int input){
	return input%g_HASH_SIZE;	
}
