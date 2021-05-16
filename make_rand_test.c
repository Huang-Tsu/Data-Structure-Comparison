#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(1);
	unsigned int new_rand_max = RAND_MAX + 1;
	double result;
	int total;
	int i=0;

	scanf("%d", &total);

	while(i++<total){
		result = (double)rand()/(new_rand_max);
		printf("%d\n", (int)(result*new_rand_max));
	}

	return 0;
}
