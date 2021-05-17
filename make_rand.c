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
void make_rand(int *base){
	int len;
	char **file_name;

		//making data for insert
	for(int k=0; k<2; k++){
		initialize_base(base, RAND_RANGE);
		shuffle_base(base, RAND_RANGE);

		if(k==0){
			file_name = file_for_insert;
			len = (int)1e4;
		} else{
			file_name = file_for_query;
			len = (int)1e3;
		}

		for(int i=1; i<=3; i++){
			print_rand(base, len, file_name[i]);
			len *= 10;
		}
	}

		//making data for query

}


int main(){
	int shuffle_base[RAND_RANGE];

	system("mkdir -p test_data");
		//making data for insert
	make_rand(shuffle_base);

	return 0;
}
