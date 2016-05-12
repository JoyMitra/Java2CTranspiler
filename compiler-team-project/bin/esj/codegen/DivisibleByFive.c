#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct DivisibleByFive DivisibleByFive;
	int main(int argc, char *argv[]){
		bool* result;
		int* numbers;
		int i;
		result = ((bool*)gc_malloc((5)*sizeof(bool),&(result)));
		numbers = ((int*)gc_malloc((5)*sizeof(int),&(numbers)));
		numbers[0] = 12;
		numbers[1] = 32;
		numbers[2] = 45;
		numbers[3] = 654;
		numbers[4] = 23;
			for(i = 0;i < 5;i++){
					if(numbers[i] % 5 == 0){
							if(numbers!=NULL && i < 5){
									if(result!=NULL && i < 5){
										result[i] = true;
								 
									}
									else{
										printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
										exit(-1);
									}
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
					}

			}


		result= NULL;
		numbers= NULL;

		collect();
		return 0;
	}
