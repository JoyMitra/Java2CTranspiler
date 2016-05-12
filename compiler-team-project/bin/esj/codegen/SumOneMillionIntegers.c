#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct SumOneMillionIntegers SumOneMillionIntegers;
typedef struct Sum Sum;
	typedef struct Sum{
		int result;

	}Sum;
	int main(int argc, char *argv[]){
		int* aMillionNos;
		int sum;
		int i;
		int limit;
		int j;
		limit = 1000000;
		aMillionNos = ((int*)gc_malloc((limit)*sizeof(int),&(aMillionNos)));
		i = 0;
		j = 0;
			for(i = 0;i < limit;i++){
				j = j + 3;
					if(aMillionNos!=NULL && i < limit){
						aMillionNos[i] = j;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
		i = 0;
		sum = 0;
			for(i = 0;i < limit;i++){
					if(aMillionNos!=NULL && i < limit){
						sum = sum + aMillionNos[i];
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
			if(((Sum*)gc_malloc(sizeof(Sum),&("NULL"))) != NULL){
				((Sum*)gc_malloc(sizeof(Sum),&("NULL")))->result = sum;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}


		aMillionNos= NULL;

		collect();
		return 0;
	}
