#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForwardClassTest ForwardClassTest;
typedef struct Foo2 Foo2;
typedef struct Bar Bar;
	typedef struct Foo2{
		Bar* b;

	}Foo2;
	typedef struct Bar{
		int x;

	}Bar;
	int main(int argc, char *argv[]){
		Foo2* a;
		a = ((Foo2*)gc_malloc(sizeof(Foo2),&(a)));
			if(a != NULL){
				a->b = ((Bar*)gc_malloc(sizeof(Bar),&(a)));
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(a != NULL){
					if(a->b != NULL){
						a->b->x = 5;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}


		a= NULL;

		collect();
		return 0;
	}
