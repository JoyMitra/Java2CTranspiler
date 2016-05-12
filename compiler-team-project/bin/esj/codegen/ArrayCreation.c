#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ArrayCreation ArrayCreation;
typedef struct AC AC;
	typedef struct AC{
	}AC;
	int main(int argc, char *argv[]){
		AC** acs;
		acs = ((AC**)gc_malloc((2)*sizeof(AC*),&(acs)));
		acs[0] = NULL;
		acs[1] = ((AC*)gc_malloc(sizeof(AC),&(acs)));


		acs= NULL;

		collect();
		return 0;
	}
