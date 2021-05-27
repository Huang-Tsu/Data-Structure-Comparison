#include "basic.h"
#include "avl_tree.h"

struct AVLNode{
	int value;
	int height;
	AVLNode *left;
	AVLNode *right;
};

	static long long g_query_cnt = 0;
	static int g_node_cnt = 0;
	static int g_find_cnt = 0;

void TestAVLTree(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	AVLNode *root = NULL;

	puts("\t\033[3m\033[1mAVL Tree:\033[m");

	gettimeofday(&start, NULL);
	root = BuildAVLTree(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryAVLTree(root, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");
	FreeAVLTree(root);
	//free(root);


	return;
}
AVLNode *BuildAVLTree(DataForProcess *insert){
	AVLNode *root = NULL;
	int i;
	int len = insert->len;

	for(i=0; i<len; i++){
		root = InsertAVLTreeNode(root, insert->data[i]);
	}

	return root;

}
void QueryAVLTree(AVLNode *node, DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		FindAVLTreeNode(node, query->data[i]);
	}

	return;
}
AVLNode *InsertAVLTreeNode(AVLNode *node, int input){
	if(!node)
		return InitializeAVLTreeNode(input);

		//insert
	if(input < node->value)
		node->left = InsertAVLTreeNode(node->left, input);
	else
		node->right = InsertAVLTreeNode(node->right, input);

		//check status

	int left_height = GetHeight(node->left);
	int right_height = GetHeight(node->right);
	node->height = 1 + Max(left_height, right_height);

	int balance = left_height - right_height;

	if(balance > 1){
		if(input > node->left->value)	//left right
			node->left = LeftRotation(node->left);

			//轉成left left 的形式再向右旋
		return RightRotation(node);
	}else if(balance < -1){
		if(input < node->right->value)		//right left
			node->right = RightRotation(node->right);

			//轉成right right 的形式再向左旋
		return LeftRotation(node);
	}

	return node;


}
AVLNode *InitializeAVLTreeNode(int input){
			g_node_cnt ++;
	static AVLNode *new_node;
	new_node = (AVLNode*)calloc(1, sizeof(AVLNode));
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->left = new_node->right =  NULL;
	new_node->height = 1;

	return new_node;
}
void FreeAVLTree(AVLNode *node){
	if(!node)
		return;

	FreeAVLTree(node->left);
	FreeAVLTree(node->right);

	free(node);
}
void FindAVLTreeNode(AVLNode *node, int input){
	if(!node)
		return;

		g_query_cnt ++;
	if(input == node->value){
			g_find_cnt++;
		return;
	}
	if(input < node->value)
		FindAVLTreeNode(node->left, input);
	else
		FindAVLTreeNode(node->right, input);

	return;
}
inline int GetHeight(AVLNode *node){
	if(!node)
		return 0;

	return node->height;
}
AVLNode *RightRotation(AVLNode *root){
	static AVLNode *old_root;
	static AVLNode *new_root;
	old_root = root;
	new_root = root->left;

	old_root->left = new_root->right;
	new_root->right = old_root;

	old_root->height = 1 + Max(GetHeight(old_root->left),
							GetHeight(old_root->right));
	new_root->height = 1 + Max(GetHeight(new_root->left),
							GetHeight(new_root->right));

	return new_root;

}
AVLNode *LeftRotation(AVLNode *root){
	static AVLNode *old_root;
	static AVLNode *new_root;
	old_root = root;
	new_root = root->right;

	old_root->right = new_root->left;
	new_root->left = old_root;

	old_root->height = 1 + Max(GetHeight(old_root->left),
							GetHeight(old_root->right));
	new_root->height = 1 + Max(GetHeight(new_root->left),
							GetHeight(new_root->right));

	return new_root;
}
inline int Max(int a, int b){
	return (a>b)? a : b;
}
