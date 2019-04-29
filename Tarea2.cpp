#include <stdio.h> 
#include <time.h>
#include <math.h>

int array[100000];
int a=100000;

void punto1(int array[]){
	int b;
	int random;
	srand(time(NULL));
	for (b=0;b<100000;b++){
		random=rand()%100;
		array[b]=random;
	}
}


