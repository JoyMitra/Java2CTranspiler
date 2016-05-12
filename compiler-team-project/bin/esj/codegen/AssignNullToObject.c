#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct AssignNullToObject AssignNullToObject;
typedef struct ANTO ANTO;
	typedef struct ANTO{
		int i;

	}ANTO;
	int main(int argc, char *argv[]){
		ANTO* o;
		o = NULL;
			if(o != NULL){
				o->i = 0;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}


		o= NULL;

		collect();
		return 0;
	}
