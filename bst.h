typedef struct TreeNode TreeNode;

void TestBST(DataForProcess *insert, DataForProcess *query);
TreeNode *BuildBST(DataForProcess *insert);
void QueryBST(TreeNode *node, DataForProcess *query);
TreeNode *InsertBSTNode(TreeNode *node, int input);
TreeNode *InitializeBSTNode(int input);
void FreeBST(TreeNode *ptr);
void FindBSTNode(TreeNode *node, int input);
/*
TreeNode *DeNode(TreeNode *node){
	static TreeNode *new_node;
	new_node = node->next;

	free(node);

	return new_node;
}
*/
