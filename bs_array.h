int compare(const void *a, const void *b);
void TestBSArray(DataForProcess *insert, DataForProcess *query);
int *BuildBSArray(DataForProcess *insert);
void QueryBSArray(int *array, int array_len, DataForProcess *query);
void BinarySearch(int *array, int len, int input);

