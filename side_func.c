
#include "basic.h"

void GetRand(int *insert, int *query){
	FILE *fp;
	int i;
	fp = fopen("./test_data/1e6_insert", "r");
	i = 0;
	while(fscanf(fp, "%d", &insert[i]) != EOF)
		i ++;
	fclose(fp);

	fp = fopen("./test_data/1e5_query", "r");
	i = 0;
	while(fscanf(fp, "%d", &query[i]) != EOF)
		i ++;
	fclose(fp);
}
void CopyData(DataForProcess *to, int *from){
	int i;
	for(i=0; i<to->len; i++){
		to->data[i] = from[to->len-1-i];
	}
}
