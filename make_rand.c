#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RAND_RANGE ((int)1e6)
#define START_VALUE_FOR_INSERT ((int)1e4)
#define START_VALUE_FOR_QUERY ((int)1e3)

char *file_for_insert[] = {
	"",
	"./test_data/1e4_insert",
	"./test_data/1e5_insert",
	"./test_data/1e6_insert"
};
char *file_for_query[] = {
	"",
	"./test_data/1e3_query",
	"./test_data/1e4_query",
	"./test_data/1e5_query"
};
char **file_name[] = {
	file_for_insert,
	file_for_query
};
void swap(int *array, int idx1, int idx2){
	static int temp;
	temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}
void initialize_base(int *data, int len){
	int i;
	for(i=0; i<len; i++){
		data[i] = i;
	}
}
void shuffle_base(int *data, int len){
	int i;
	int idx;
	for(i=len-1; i>0; i--){
		idx = (int)(rand() / (RAND_MAX+1.0) * i);	
		swap(data, i, idx);
	}

}
void print_rand(int *data, int len, char *file_name){
	FILE *fp;
	int total = 0;

	fp = fopen(file_name, "w");
		if(!fp){
			printf("open %s failed!\n", file_name);
			exit(1);
		}

	while(total < len){
		fprintf(fp, "%d\n", data[RAND_RANGE - 1 - total]);
		total ++;
	}
	fclose(fp);
}
void make_rand(int *base){
	int i, k;
	int len[] = {
		START_VALUE_FOR_INSERT,
		START_VALUE_FOR_QUERY
	};

	for(k=0; k<2; k++){
		initialize_base(base, RAND_RANGE);
		shuffle_base(base, RAND_RANGE);

		for(i=1; i<=3; i++){
			print_rand(base, len[k], file_name[k][i]);
			len[k] *= 10;
		}
	}

}


int main(){
	int shuffle_base[RAND_RANGE];

	system("mkdir -p test_data");
		//making data for insert
	make_rand(shuffle_base);

	return 0;
}
