#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct NewBasic NewBasic;
	int main(int argc, char *argv[]){
		int* i;
		int* j;
		bool* b;
		bool* c;
		i = ((int*)gc_malloc((4)*sizeof(int),&(i)));
		j = ((int*)gc_malloc((3)*sizeof(int),&(j)));
		j[0] = 1;
		j[1] = 2;
		j[2] = 3;
		b = ((bool*)gc_malloc((4)*sizeof(bool),&(b)));
		c = ((bool*)gc_malloc((2)*sizeof(bool),&(c)));
		c[0] = true;
		c[1] = false;


		i= NULL;
		j= NULL;
		b= NULL;
		c= NULL;

		collect();
		return 0;
	}
