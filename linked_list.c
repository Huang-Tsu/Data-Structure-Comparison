#include "basic.h"
#include "linked_list.h"

struct List{
	int value;
	List *next;
};

	static long long g_query_cnt = 0;
	static int g_node_cnt = 0;
	static int g_find_cnt = 0;

void TestLinkedList(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	List *root = NULL;

	puts("\t\033[3m\033[1mLinked List:\033[m");
	
	gettimeofday(&start, NULL);
	root = BuildLinkList(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryLinkedList(root, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");
	FreeList(root);
	//free(root);


	return;
}
List *BuildLinkList(DataForProcess *insert){
	List *root, *tail;
	root = tail = NodeInitilize(insert->data[0]);
	int i;

	for(i=1; i<insert->len; i++){
		tail = InsertNode(tail, insert->data[i]);
	}

	return root;

}
void QueryLinkedList(List *node, DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		FindNode(node, query->data[i]);
	}

	return;
}
List *InsertNode(List *ptr, int input){
	return ptr->next = NodeInitilize(input);
}
List *NodeInitilize(int input){
			g_node_cnt ++;
	static List *new_node;
	new_node = (List*)calloc(1, sizeof(List));
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->next = NULL;

	return new_node;
}
void FreeList(List *ptr){
	List *next_node;

	for(ptr; ptr->next; ptr=next_node){
		next_node = ptr->next;
		free(ptr);
	}

}
void FindNode(List *ptr, int input){
	static List *previous_node;
	/*
		for(ptr; ptr->next; ptr=ptr->next){
			g_query_cnt++;
			if(ptr->value == input){
					g_find_cnt++;
				return;
			}
		}
		*/
	/*
			g_query_cnt++;
			if(ptr->value == input){
				g_find_cnt++;
				return;
			}
		while(ptr->next){
				g_query_cnt ++;
			if(ptr->next->value == input){
				g_find_cnt++;
				ptr->next = DeNode(ptr->next);
				return;
			}

			ptr = ptr->next;
		}
		*/
	for(ptr; ptr; ptr=ptr->next){
			g_query_cnt ++;
		if(ptr->value == input){
				g_find_cnt++;
			previous_node->next = DeNode(ptr);
			return;
		}
		previous_node = ptr;
	}

	return;
}
List *DeNode(List *node){
	static List *new_node;
	new_node = node->next;

	free(node);

	return new_node;
}
