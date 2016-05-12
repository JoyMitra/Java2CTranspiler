#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct NewIDFoo NewIDFoo;
typedef struct NewID NewID;
	typedef struct NewIDFoo{
	}NewIDFoo;
	int main(int argc, char *argv[]){
		NewIDFoo* f;
		NewIDFoo** g;
		NewIDFoo** h;
		f = ((NewIDFoo*)gc_malloc(sizeof(NewIDFoo),&(f)));
		g = ((NewIDFoo**)gc_malloc((4)*sizeof(NewIDFoo*),&(g)));
			if(g!=NULL && 0 < 4){
				h = ((NewIDFoo**)gc_malloc((2)*sizeof(NewIDFoo*),&(h)));
				h[0] = f;
				h[1] = g[0];
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}


		f= NULL;
		g= NULL;
		h= NULL;

		collect();
		return 0;
	}
