#include "basic.h"
#include "rbt.h"

struct RBTNode{
	int value;
	int color;
	RBTNode *left;
	RBTNode *right;
	RBTNode *parent;
};

	static long long g_query_cnt = 0;
	static int g_node_cnt = 0;
	static int g_find_cnt = 0;

	static RBTNode *nil;
	static RBTNode *root;

void TestRBT(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	nil = (RBTNode*)calloc(1, sizeof(RBTNode));
	nil->color = BLACK;
	nil->parent = nil->left = nil->right = NULL;

	puts("\t\033[3m\033[1mRed-Black Tree:\033[m");

	gettimeofday(&start, NULL);
	BuildRBT(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryRBT(query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");

			//Traversal(root);
	FreeRBT(root);
	free(nil);
	//free(root);


	return;
}
void BuildRBT(DataForProcess *insert){
	root = InitializeRBTNode(insert->data[0]);
		root->color = BLACK;
	int i;
	int len = insert->len;


	for(i=1; i<len; i++){
		InsertRBTNode(insert->data[i]);
	}

}
void QueryRBT(DataForProcess *query){
	int i;
	for(i=0; i<query->len; i++){
		FindRBTNode(root, query->data[i]);
	}

	return;
}
void InsertRBTNode(int input){
	static RBTNode *new_node;
	new_node = InitializeRBTNode(input);
	static RBTNode *current;
	static RBTNode *pre;
	current = root;

	while(current != nil){
		pre = current;

		if(input < current->value)
			current = current->left;
		else
			current = current->right;
	}
	new_node->parent = pre;

	if(input < pre->value){
		pre->left = new_node;
	}else{
		pre->right = new_node;
	}

	FixUpInsert(new_node);
}
void FixUpInsert(RBTNode *now){
	RBTNode *grandpa = now->parent->parent;
	RBTNode *uncle;

	while(now->parent->color == RED){
		grandpa = now->parent->parent;

		if(IsLeftNode(now->parent)){ //parent is left
			uncle = grandpa->right;

			if(uncle->color == RED){
				now->parent->color = uncle->color = BLACK;
				grandpa->color = RED;

				now = grandpa;
			}else{	//uncle is black
				if(!IsLeftNode(now)){ //left right case
					now = now->parent;
					RBTLeftRotation(now);	//turn to left left case
				}

				grandpa->color = RED;
				now->parent->color = BLACK;
				RBTRightRotation(grandpa);
			}
		}else{ //parent is right
			uncle = grandpa->left;

			if(uncle->color == RED){
				now->parent->color = uncle->color = BLACK;
				grandpa->color = RED;

				now = grandpa;
			} else{	//uncle is black
				if(IsLeftNode(now)){ //right left case
					now = now->parent;
					RBTRightRotation(now);	//turn to right right case
				}

				grandpa->color = RED;
				now->parent->color = BLACK;
				RBTLeftRotation(grandpa);
			}

		}
	}

	root->color = BLACK;
}
RBTNode *InitializeRBTNode(int input){
			g_node_cnt ++;
	static RBTNode *new_node;
	new_node = (RBTNode*)calloc(1, sizeof(RBTNode));
		if(!new_node){
			puts("Memory allocation failed.");
			exit(1);
		}

	new_node->value = input;
	new_node->left = new_node->right = new_node->parent = nil;
	new_node->color = RED;

	return new_node;
}
void FreeRBT(RBTNode *node){
	if(node == nil)
		return;

	FreeRBT(node->left);
	FreeRBT(node->right);

	free(node);
}
void FindRBTNode(RBTNode *node, int input){
	if(node == nil)
		return;

		g_query_cnt ++;
	if(input == node->value){
			g_find_cnt++;
		return;
	}
	if(input < node->value)
		FindRBTNode(node->left, input);
	else
		FindRBTNode(node->right, input);

	return;
}
void RBTRightRotation(RBTNode *node){
	static RBTNode *old;
	static RBTNode *new;
	old = node;
	new = node->left;

	old->left = new->right;
	if(new->right != nil)
		new->right->parent = old;

	new->right = old;
	new->parent = old->parent;
	if(old != root){
		if(IsLeftNode(old))
			new->parent->left = new;
		else
			new->parent->right = new;
	}else{
		root = new;
	}
	old->parent = new;
}
void RBTLeftRotation(RBTNode *node){
	static RBTNode *old;
	static RBTNode *new;
	old = node;
	new = node->right;

	old->right = new->left;
	if(new->left != nil)
		new->left->parent = old;

	new->left = old;
	new->parent = old->parent;
	if(old != root){
		if(IsLeftNode(old))
			new->parent->left = new;
		else
			new->parent->right = new;
	}else{
		root = new;
	}
	old->parent = new;
}
int IsLeftNode(RBTNode *node){
	if(!node)
		return 0;

	return (node->parent->left == node)? 1 : 0;
}
	void Traversal(RBTNode *node){
		if(node == nil)
			return;

		Traversal(node->left);
		printf("%d\t%d\n", node->value, node->color);
		Traversal(node->right);
	}
