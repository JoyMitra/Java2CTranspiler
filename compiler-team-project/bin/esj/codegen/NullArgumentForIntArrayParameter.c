#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct NullArgumentForIntArrayParameter NullArgumentForIntArrayParameter;
void takeIntArray (int*);
	int main(int argc, char *argv[]){
		takeIntArray(NULL);


		collect();
		return 0;
	}
	void takeIntArray (int* I){


	}
