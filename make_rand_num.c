#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(1);
	int total;
	int i=0;

	scanf("%d", &total);

	while(i++<total){
		printf("%d\n", rand());
	}

	return 0;
}
