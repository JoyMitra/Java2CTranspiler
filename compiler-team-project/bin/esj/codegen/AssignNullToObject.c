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


		o= NULL;

		collect();
		return 0;
	}
