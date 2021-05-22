#include "basic.h"
#include "bst.h"

struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
};

	static long long g_query_cnt = 0;
	static int g_node_cnt = 0;
	static int g_find_cnt = 0;

void TestBST(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	TreeNode *root = NULL;

	puts("\t\033[3m\033[1mLinked TreeNode:\033[m");
	
	gettimeofday(&start, NULL);
	root = BuildBST(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryBST(root, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");
	FreeBST(root);
	//free(root);


	return;
}
TreeNode *BuildBST(DataForProcess *insert){
	TreeNode *root = NULL;
	int i;
	int len = insert->len;

	for(i=0; i<len; i++){
		root = InsertBSTNode(root, insert->data[i]);
	}

	return root;

}
void QueryBST(TreeNode *node, DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		FindBSTNode(node, query->data[i]);
	}

	return;
}
TreeNode *InsertBSTNode(TreeNode *node, int input){
	if(!node){
		node = InitializeBSTNode(input);
		return node;
	}

	if(input < node->value)
		node->left = InsertBSTNode(node->left, input);
	else
		node->right = InsertBSTNode(node->right, input);

	return node;


}
TreeNode *InitializeBSTNode(int input){
			g_node_cnt ++;
	static TreeNode *new_node;
	new_node = (TreeNode*)calloc(1, sizeof(TreeNode));
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->left = new_node->right =  NULL;

	return new_node;
}
void FreeBST(TreeNode *node){
	if(!node)
		return;

	FreeBST(node->left);
	FreeBST(node->right);
	
	free(node);
}
void FindBSTNode(TreeNode *node, int input){
	if(!node)
		return;
	
		g_query_cnt ++;
	if(input == node->value){
			g_find_cnt++;
		return;
	}
	if(input < node->value)
		FindBSTNode(node->left, input);
	else
		FindBSTNode(node->right, input);

	return;
}
/*
TreeNode *DeNode(TreeNode *node){
	static TreeNode *new_node;
	new_node = node->next;

	free(node);

	return new_node;
}
*/
