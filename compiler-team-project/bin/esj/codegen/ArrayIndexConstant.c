#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ArrayIndexConstant ArrayIndexConstant;
	int main(int argc, char *argv[]){
		int* i_array;
		i_array = ((int*)gc_malloc((3)*sizeof(int),&(i_array)));
		i_array[0] = 1;
		i_array[1] = 2;
		i_array[2] = 3;
			if(i_array!=NULL && 0 < 3){
				i_array[0] = 1;
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}


		i_array= NULL;

		collect();
		return 0;
	}
