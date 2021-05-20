#include "basic.h"
#include "linked_list.h"

struct List{
	int value;
	List *next;
};

	int g_query_cnt = 0;
	int g_node_cnt = 0;

void TestLinkedList(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	List *root = NULL;

		printf("insert->len:%d\n", insert->len);
	puts("Linked List");
	
	gettimeofday(&start, NULL);
	root = BuildLinkList(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n\n", insert->len, diff/1000000.0);
		puts("Done building.");

	gettimeofday(&start, NULL);
	QueryLinkedList(root, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("Query_cnt:%d\n", g_query_cnt);

	FreeList(root);
	//free(root);

	puts("--------------------");

	return;
}
List *BuildLinkList(DataForProcess *insert){
	List *root = NULL;
	int i;

	for(i=0; i<insert->len; i++){
		root = InsertNode(root, insert->data[i]);
			if(i == insert->len/2)
			puts("Done half");
	}

	return root;

}
void QueryLinkedList(List *node, DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		FindNode(node, query->data[i]);
			if(i == (query->len)/2)
			puts("Done half");
			//FindNode(node, 214748354);
	}

	return;
}
List *InsertNode(List *node, int input){
	if(!node){
			if(g_node_cnt > 82000){
				printf("In InsertNode g_node_cnt:%d\n", g_node_cnt);
			}
		node = NodeInitilize(input);
		return node;
	}

	node->next = InsertNode(node->next, input);

	return node;
}
List *NodeInitilize(int input){
			g_node_cnt ++;
	static List *new_node;
			if(g_node_cnt > 82000){
				printf("In NodeIni g_node_cnt:%d\n", g_node_cnt);
			}
	new_node = (List*)calloc(1, sizeof(List));
			if(g_node_cnt > 82000){
				printf("In NodeIni g_node_cnt:%d\n", g_node_cnt);
			}
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->next = NULL;

	return new_node;
}
void FreeList(List *node){
	if(!node)
		return;


	FreeList(node->next);

	free(node);

	return;
}
void FindNode(List *node, int input){
	if(!node)
		return;

			g_query_cnt++;
	if(node->value == input)
		return;

	FindNode(node->next, input);
}
