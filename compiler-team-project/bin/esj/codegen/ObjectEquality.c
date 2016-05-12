#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Object100 Object100;
typedef struct ObjectEquality ObjectEquality;
typedef struct Object200 Object200;
typedef struct Object300 Object300;
typedef struct EqRes EqRes;
	typedef struct Object100{
	}Object100;
	typedef struct Object200{
	}Object200;
	typedef struct Object300{
	}Object300;
	typedef struct EqRes{
		bool res;

	}EqRes;
	int main(int argc, char *argv[]){
		Object100* o1;
		Object200* o2;
		Object300* o3;
		EqRes* e;
		o1 = ((Object100*)gc_malloc(sizeof(Object100),&(o1)));
		o2 = ((Object200*)gc_malloc(sizeof(Object200),&(o2)));
		o3 = ((Object300*)gc_malloc(sizeof(Object300),&(o3)));
		e = ((EqRes*)gc_malloc(sizeof(EqRes),&(e)));
			if(o1 == ((Object100*)gc_malloc(sizeof(Object100),&("NULL")))){
					if(e != NULL){
						e->res = true;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
			}
			if(o2 == ((Object200*)gc_malloc(sizeof(Object200),&("NULL")))){
					if(e != NULL){
						e->res = true;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
			}
			if(o3 != ((Object300*)gc_malloc(sizeof(Object300),&("NULL")))){
					if(e != NULL){
						e->res = false;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
			}


		o1= NULL;
		o2= NULL;
		o3= NULL;
		e= NULL;

		collect();
		return 0;
	}
