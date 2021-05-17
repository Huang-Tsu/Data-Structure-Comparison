#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RAND_RANGE ((int)1e6)

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
void make_rand_for_insert(int *base){
	int len;
	initialize_base(base, RAND_RANGE);
	shuffle_base(base, RAND_RANGE);

	len = (int)1e4;
	for(int i=1; i<=3; i++){
		print_rand(base, len, file_for_insert[i]);
		len *= 10;
	}

}
void make_rand_for_query(){
	FILE *fp;
	int random_num;
	int rand_cnt;
	int len = (int)1e3;
	for(int i=1; i<=3; i++){
		rand_cnt = 0;

		fp = fopen(file_for_query[i], "w");	
			if(!fp){
				printf("open %s failed!\n", file_for_query[i]);
				exit(1);
			}

		while(rand_cnt < len){
			random_num = (int)(rand() / (RAND_MAX+1.0) * RAND_RANGE);
			fprintf(fp, "%d\n", random_num);
			rand_cnt ++;
		}
		fclose(fp);
		
		len *= 10;
	}
}


int main(){
	int shuffle_base[RAND_RANGE];

	system("mkdir -p test_data");
	//making data for insert
	make_rand_for_insert(shuffle_base);
	make_rand_for_query();
	//making rand for query
	return 0;
}
