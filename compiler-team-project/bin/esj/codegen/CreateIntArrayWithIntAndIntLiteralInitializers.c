#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct CreateIntArrayWithIntAndIntLiteralInitializers CreateIntArrayWithIntAndIntLiteralInitializers;
	int main(int argc, char *argv[]){
		int* I;
		int i;
		i = 0;
		I = ((int*)gc_malloc((2)*sizeof(int),&(I)));
		I[0] = i;
		I[1] = 1;


		I= NULL;

		collect();
		return 0;
	}
