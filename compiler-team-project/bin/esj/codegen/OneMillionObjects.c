#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct OneMillionObjects OneMillionObjects;
typedef struct Obj1 Obj1;
	typedef struct Obj1{
		bool f;

	}Obj1;
	int main(int argc, char *argv[]){
		Obj1** a;
		Obj1* o;
		int i;
		a = ((Obj1**)gc_malloc((1000000)*sizeof(Obj1*),&(a)));
		i = 0;
			while(i < 1000000){
				o = ((Obj1*)gc_malloc(sizeof(Obj1),&(o)));
					if(a!=NULL && i < 1000000){
						a[i] = o;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
				i++;

			}
			for(i = 0;i < 1000000;i++){
					if(a!=NULL && i < 1000000){
							if(a[i] != NULL){
								a[i]->f = true;
						 
							}
							else{
								printf("Error:Null Pointer reference near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


		a= NULL;
		o= NULL;

		collect();
		return 0;
	}
