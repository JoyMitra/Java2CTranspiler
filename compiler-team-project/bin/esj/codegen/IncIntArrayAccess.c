#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IncIntArrayAccess IncIntArrayAccess;
	int main(int argc, char *argv[]){
		int* I;
		I = ((int*)gc_malloc((1)*sizeof(int),&(I)));
			if(I!=NULL && 0 < 1){
				I[0] = 1;
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}
			if(I!=NULL && 0 < 1){
				I[0]++;
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}


		I= NULL;

		collect();
		return 0;
	}
