#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Foo Foo;
typedef struct TypesID TypesID;
	typedef struct Foo{
	}Foo;
	int main(int argc, char *argv[]){
		Foo* f;
		Foo** g;


		f= NULL;
		g= NULL;

		collect();
		return 0;
	}
