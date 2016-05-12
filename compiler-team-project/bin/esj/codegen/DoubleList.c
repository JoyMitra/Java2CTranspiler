#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct DoubleList DoubleList;
	int main(int argc, char *argv[]){
		int* a;
		int i;
		a = ((int*)gc_malloc((6)*sizeof(int),&(a)));
		a[0] = 12;
		a[1] = 4;
		a[2] = 4;
		a[3] = 4;
		a[4] = 233;
		a[5] = 32;
			for(i = 0;i < 6;i++){
					if(a!=NULL && i < 6){
						a[i] = a[i] * 2;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


		a= NULL;

		collect();
		return 0;
	}
