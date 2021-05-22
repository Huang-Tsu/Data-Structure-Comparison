#include "basic.h"
#include "array.h"


	static long long g_query_cnt = 0;
	static int g_find_cnt = 0;

void TestArray(DataForProcess *insert, DataForProcess *query){
	Timeval start;
	Timeval end;
	unsigned long diff;
	int *array;

	puts("\t\033[3m\033[1mArray:\033[m");
	
	gettimeofday(&start, NULL);
	array = BuildArray(insert);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Build %d data time: %f sec.\n", insert->len, diff/1000000.0);

	puts("--------------------");

		puts("\t(Start querying...");
	gettimeofday(&start, NULL);
	QueryArray(array, insert->len, query);
	gettimeofday(&end, NULL);
	diff = 1000000*(end.tv_sec-start.tv_sec) + end.tv_usec-start.tv_usec;
	printf("Querying %d data time: %f sec.\n", query->len, diff/1000000.0);
		printf("\tFind cnt:%d\n", g_find_cnt);
		printf("\tQuery_cnt:%lld\n", g_query_cnt);

		puts("____________________\n");

	free(array);


	return;
}
int *BuildArray(DataForProcess *insert){
	int len = insert->len;
	int *array = (int*)calloc(len, sizeof(int));
	int i;

	for(i=0; i<len; i++){
		array[i] = insert->data[i];
	}

	return array;

}
void QueryArray(int *array, int array_len, DataForProcess *query){
	int i;
	int query_len = query->len;
	for(i=0; i<query_len; i++){
		FindNumber(array, array_len, query->data[i]);
	}

	return;
}
void FindNumber(int *array, int len, int input){
	static int i;

	for(i=0; i<len; i++){
			g_query_cnt ++;
		if(array[i] == input){
			g_find_cnt ++;
			return;
		}
	}
}
