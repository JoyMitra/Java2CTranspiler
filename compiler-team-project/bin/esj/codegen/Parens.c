#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Parens Parens;
	int main(int argc, char *argv[]){
		int i;
		int j;
		int* a;
		i = (2);
		i = 2;
		j = (i);
		i = (i + 0);
		assertTrue(i == 2);
		i = (i * (i + 0));
		assertTrue(i == 4);
			if((2)!=0){
				i = (((i) / (2)) - (0));
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
		assertTrue(i == 2);
		a = ((int*)gc_malloc((4)*sizeof(int),&(a)));


		a= NULL;

		collect();
		return 0;
	}
