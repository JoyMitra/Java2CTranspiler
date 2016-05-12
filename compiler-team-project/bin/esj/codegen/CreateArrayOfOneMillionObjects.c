#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct CreateArrayOfOneMillionObjects CreateArrayOfOneMillionObjects;
typedef struct Obj Obj;
	typedef struct Obj{
	}Obj;
	int main(int argc, char *argv[]){
		Obj** arr;
		int i;
		arr = ((Obj**)gc_malloc((1000000)*sizeof(Obj*),&(arr)));
			for(i = 0;i < 1000000;i++){
					if(arr!=NULL && i < 1000000){
						arr[i] = ((Obj*)gc_malloc(sizeof(Obj),&(arr)));
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


		arr= NULL;

		collect();
		return 0;
	}
