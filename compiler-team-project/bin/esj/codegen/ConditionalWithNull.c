#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct CWN CWN;
typedef struct ConditionalWithNull ConditionalWithNull;
	typedef struct CWN{
	}CWN;
	int main(int argc, char *argv[]){
		CWN* o;
		o = ((CWN*)gc_malloc(sizeof(CWN),&(o)));
		o = true?NULL:o;


		o= NULL;

		collect();
		return 0;
	}
