#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct CopyArrayElemToField CopyArrayElemToField;
typedef struct ArrCl ArrCl;
typedef struct ArrCl1 ArrCl1;
typedef struct ArrCl2 ArrCl2;
	typedef struct ArrCl{
		ArrCl1* b;
		int* a;

	}ArrCl;
	typedef struct ArrCl1{
		ArrCl2* c;

	}ArrCl1;
	typedef struct ArrCl2{
		int z;

	}ArrCl2;
	int main(int argc, char *argv[]){
		ArrCl* o;
		o = ((ArrCl*)gc_malloc(sizeof(ArrCl),&(o)));
			if(o != NULL){
				o->a = ((int*)gc_malloc((1)*sizeof(int),&(o)));
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
				o->b = ((ArrCl1*)gc_malloc(sizeof(ArrCl1),&(o)));
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
					if(o->b != NULL){
						o->b->c = ((ArrCl2*)gc_malloc(sizeof(ArrCl2),&(o)));
				 
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
			if(o != NULL){
					if(o->a!=NULL && 0 < 1){
						o->a[0] = 5;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
					if(o->a!=NULL && 0 < 1){
						o->a[0] = o->a[0] * 10;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
					if(o->b != NULL){
							if(o->b->c != NULL){
									if(o->a!=NULL && 0 < 1){
										o->b->c->z = o->a[0];
								 
									}
									else{
										printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
										exit(-1);
									}
						 
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
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
					if(o->b != NULL){
							if(o->b->c != NULL){
								o->b->c->z++;
						 
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
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(o != NULL){
					if(o->a!=NULL && 0 < 1){
							if(o->b != NULL){
									if(o->b->c != NULL){
										o->a[0] = (~(o->b->c->z));
								 
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
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}


		o= NULL;

		collect();
		return 0;
	}
