#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RAND_RANGE ((int)1e8)
//#define INSERT_DATA_LEN ((int)1e6)
//#define QUERY_DATA_LEN ((int)1e5)
#define DATA_LEN ((int)1e6)

void Swap(int *array, int idx1, int idx2){
	static int temp;
	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
void InitializeBase(int *data, int len){
	int i;
	for(i=0; i<len; i++){
		data[i] = i;
	}
}
void ShuffleBase(int *data, int len){
	int i;
	int idx;
	for(i=len-1; i>0; i--){
		idx = (int)(rand() / (RAND_MAX+1.0) * i);	
		Swap(data, i, idx);
	}

}
void PrintRand(int *data, int len, char *file_name){
	FILE *fp;
	int total = 0;

	fp = fopen(file_name, "w");
		if(!fp){
			printf("open %s failed!\n", file_name);
			exit(1);
		}

	while(total < len){
		fprintf(fp, "%d\n", data[len - 1 - total]);
		total ++;
	}
	fclose(fp);
}
void GetRand(int *to, int *from, int len){
	for(int i=0; i<len; i++){
		to[i] = from[len-1-i];
	}
}
void MakeRand(int *base){
	int output[DATA_LEN];
	int i;

	InitializeBase(base, RAND_RANGE);

		//make rand for insert
	for(i=0; i<2; i++)
		ShuffleBase(base, RAND_RANGE);

	GetRand(output, base, DATA_LEN);
	PrintRand(output, DATA_LEN, "./test_data/1e6_insert");

		//make rand for query base on insert_data
	for(i=0; i<2; i++)
		ShuffleBase(output, DATA_LEN);

	PrintRand(output, DATA_LEN, "./test_data/1e5_query");

}


int main(){
	int *shuffle_base = (int*)calloc((int)RAND_RANGE, sizeof(int));

	system("mkdir -p test_data");
	MakeRand(shuffle_base);

	free(shuffle_base);

	return 0;
}
