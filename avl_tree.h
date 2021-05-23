
typedef struct AVLNode AVLNode;

void TestAVLTree(DataForProcess *insert, DataForProcess *query);
AVLNode *BuildAVLTree(DataForProcess *insert);
void QueryAVLTree(AVLNode *node, DataForProcess *query);
AVLNode *InsertAVLTreeNode(AVLNode *node, int input);
AVLNode *InitializeAVLTreeNode(int input);
void FreeAVLTree(AVLNode *node);
void FindAVLTreeNode(AVLNode *node, int input);
int GetHeight(AVLNode *node);
AVLNode *RightRotation(AVLNode *root);
AVLNode *LeftRotation(AVLNode *root);
int Max(int a, int b);
