#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ReturnNullFromIntArrayMethod ReturnNullFromIntArrayMethod;
int* returnIntArray ();
	int main(int argc, char *argv[]){
		int* i;
		i = returnIntArray();


		i= NULL;

		collect();
		return 0;
	}
	int* returnIntArray (){
		 collect();
		 return NULL;


	}
