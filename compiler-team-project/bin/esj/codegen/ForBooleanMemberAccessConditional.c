#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForBooleanMemberAccessConditional ForBooleanMemberAccessConditional;
typedef struct FBMAC FBMAC;
	typedef struct FBMAC{
		bool b;

	}FBMAC;
	int main(int argc, char *argv[]){
		FBMAC* o;
		bool b;
		b = false;
		o = ((FBMAC*)gc_malloc(sizeof(FBMAC),&(o)));
			if(o != NULL){
				o->b = false;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			for(;o->b;){
					if(o != NULL){
						b = true;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}

			}
		assertTrue(b == false);


		o= NULL;

		collect();
		return 0;
	}
