#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct A A;
typedef struct B B;
typedef struct SymbolTableTest SymbolTableTest;
	typedef struct A{
		int x;

	}A;
	typedef struct B{
		int x;

	}B;
	int main(int argc, char *argv[]){
		A* a;
		B* b;
		int z;
		a = ((A*)gc_malloc(sizeof(A),&(a)));
		b = ((B*)gc_malloc(sizeof(B),&(b)));
			if(a != NULL){
					if(b != NULL){
						z = a->x + b->x;
				 
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
		b= NULL;

		collect();
		return 0;
	}
