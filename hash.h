typedef struct HashTable HashTable;

#define HASH_SIZE ((int)1e5)
void TestHash(DataForProcess *insert, DataForProcess *query);
HashTable **BuildHashTable(DataForProcess *insert);
void QueryHashTable(HashTable **root, DataForProcess *query);
void InsertHashNode(HashTable **node, int input);
HashTable *InitializeHashNode(int input);
void LookUpTable(HashTable **table, int input);
int Hash(int input);
void FreeHashTable(HashTable **table);
void FreeTableList(HashTable *ptr);
