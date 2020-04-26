#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int static_array(){
	static int arr[10000];
	int i;
	for(i = 0; i < 10000; i++) {
		arr[i] = rand()%10000+1;
	}
}

int stack_array() {
	int arr1[10000];
	int i;
	for(i = 0; i < 10000; i++) {
		arr1[i] = rand()%10000+1;
	}
}

int heap_array() {
	int* arr2 = (int*) malloc(sizeof(int) * 10000);
	int i;
	for(i = 0; i < 10000; i++) {
		arr2[i] = rand()%10000+1;
	}
}

main() {
	clock_t t;
	int k;
	t = clock();
	
	for(k = 0; k < 100000; k++){
			static_array();
	}
	
	t = clock()-t;
		
	printf("\n Time taken for 100,000 calls on static array is %f", ((float)t)/CLOCKS_PER_SEC);
	printf(" sec");
	
	t = clock();
	
	for(k = 0; k < 100000; k++){
			stack_array();
	}
	
	t = clock()-t;
	
	printf("\n Time taken for 100,000 calls on stack array is %f", ((float)t)/CLOCKS_PER_SEC);
	printf(" sec");
	
	t = clock();
	
	for(k = 0; k < 100000; k++){
			heap_array();
	}
	
	t = clock()-t;
	
	printf("\n Time taken for 100,000 calls on heap array is %f", ((float)t)/CLOCKS_PER_SEC);
	printf(" sec");	
}