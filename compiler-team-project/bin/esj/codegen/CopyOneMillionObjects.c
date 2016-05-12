#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct A1 A1;
typedef struct CopyOneMillionObjects CopyOneMillionObjects;
typedef struct B1 B1;
	typedef struct A1{
		int valueA;

	}A1;
	typedef struct B1{
		int valueB;

	}B1;
	int main(int argc, char *argv[]){
		A1** a;
		B1** b;
		A1* objA;
		B1* objB;
		int i;
		a = ((A1**)gc_malloc((1000000)*sizeof(A1*),&(a)));
		b = ((B1**)gc_malloc((1000000)*sizeof(B1*),&(b)));
			for(i = 0;i < 1000000;i++){
				objA = ((A1*)gc_malloc(sizeof(A1),&(objA)));
					if(objA != NULL){
						objA->valueA = i;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
					if(a!=NULL && i < 1000000){
						a[i] = objA;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
			for(i = 0;i < 1000000;i++){
				objB = ((B1*)gc_malloc(sizeof(B1),&(objB)));
					if(b!=NULL && i < 1000000){
						b[i] = objB;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
			for(i = 0;i < 1000000;i++){
					if(b!=NULL && i < 1000000){
							if(b[i] != NULL){
									if(a!=NULL && i < 1000000){
											if(a[i] != NULL){
												b[i]->valueB = a[i]->valueA;
										 
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
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


		a= NULL;
		b= NULL;
		objA= NULL;
		objB= NULL;

		collect();
		return 0;
	}
