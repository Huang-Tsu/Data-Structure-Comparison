#include <stdio.h>
#include <stdlib.h>

int main(){
	int pre, now;
	int catch_cnt = 0;

	scanf("%d", &pre);
	while(scanf("%d", &now) != EOF){
		if(pre == now){
			printf("Catch %d!\n", now);
			catch_cnt++;
		}
		pre = now;
	}
	printf("Total same data:%d\n", catch_cnt);
	
	return 0;
}
