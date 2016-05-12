#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForBooleanArrayAccessConditional ForBooleanArrayAccessConditional;
	int main(int argc, char *argv[]){
		bool* B;
		bool b;
		b = false;
		B = ((bool*)gc_malloc((1)*sizeof(bool),&(B)));
			if(B!=NULL && 0 < 1){
				B[0] = false;
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}
			for(;B[0];){
					if(B!=NULL && 0 < 1){
						b = true;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
		assertTrue(b == false);


		B= NULL;

		collect();
		return 0;
	}
