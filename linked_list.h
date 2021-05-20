typedef struct List List;

void TestLinkedList(DataForProcess *insert, DataForProcess *query);
List *BuildLinkList(DataForProcess *insert);
void QueryLinkedList(List *node, DataForProcess *query);
List *NodeInitilize(int input);
List *InsertNode(List *node, int input);
void FreeList(List *node);
void FindNode(List *node, int input);
