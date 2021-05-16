#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum{
	INSERT = 1, QUERY = 2
};

int g_mode;

int main(){
	int total_data;
	int data_cnt = 0;
	char mode_input[2];
	int i=0;
	int output[(int)1e6] = {0};

	puts("Hi welcome to makeing-random-data!");
	puts("How you gonna use this data?");
	puts("\t(\"i\" For insert");
	puts("\t(\"q\" For query");
	printf("Your answer:");

	scanf("%1s", mode_input);
	switch(*mode_input){
		case 'i':
			g_mode = INSERT;
			break;
		case 'q':
			g_mode = QUERY;
			break;
		default:
			puts("Wrong option");
			exit(1);
			break;
	}
	puts("Option received.");
	srand(g_mode);
	puts("");

	puts("How many do you want?");
	printf("Your answer:");
	scanf("%d", &total_data);
	puts("Option received.");
	puts("");
	puts("Start making random data !");

	while(i++<total_data){
		printf("%d\n", rand());
	}

	return 0;
}
