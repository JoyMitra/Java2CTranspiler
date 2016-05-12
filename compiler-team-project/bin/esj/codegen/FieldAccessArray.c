#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Z Z;
typedef struct FieldAccessArray FieldAccessArray;
typedef struct ZA ZA;
	typedef struct Z{
		ZA** za;

	}Z;
	typedef struct ZA{
		int i;

	}ZA;
	int main(int argc, char *argv[]){
		Z* z;
		ZA** zas;
		int j;
		z = ((Z*)gc_malloc(sizeof(Z),&(z)));
			if(z != NULL){
				z->za = ((ZA**)gc_malloc((4)*sizeof(ZA*),&(z)));
				z->za[0] = NULL;
				z->za[1] = ((ZA*)gc_malloc(sizeof(ZA),&(z)));
				z->za[2] = ((ZA*)gc_malloc(sizeof(ZA),&(z)));
				z->za[3] = NULL;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(z != NULL){
				zas = z->za;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			for(j = 0;j < 4;j++){
					if(zas[j] != NULL){
							if(zas!=NULL){
									if(zas[j] != NULL){
										zas[j]->i = j;
								 
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
							if(zas!=NULL){
								zas[j] = ((ZA*)gc_malloc(sizeof(ZA),&(zas)));
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}

					}

			}


		z= NULL;
		zas= NULL;

		collect();
		return 0;
	}
