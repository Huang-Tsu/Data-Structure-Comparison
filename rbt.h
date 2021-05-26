typedef struct RBTNode RBTNode;
#define RED 0
#define BLACK 1

void TestRBT(DataForProcess *insert, DataForProcess *query);
void BuildRBT(DataForProcess *insert);
void QueryRBT(DataForProcess *query);
void InsertRBTNode(int input);
RBTNode *InitializeRBTNode(int input);
void FreeRBT(RBTNode *node);
void FindRBTNode(RBTNode *node, int input);
void RBTRightRotation(RBTNode *node);
void RBTLeftRotation(RBTNode *node);
int IsLeftNode(RBTNode *node);
void FixUpInsert(RBTNode *now);
	void Traversal(RBTNode *node);
