#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ArrayAccessVariable ArrayAccessVariable;
	int main(int argc, char *argv[]){
		int i;
		int* a;
		int* b;
		i = 0;
		a = ((int*)gc_malloc((3)*sizeof(int),&(a)));
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		b = ((int*)gc_malloc((3)*sizeof(int),&(b)));
			if(b!=NULL && i < 3){
					if(a!=NULL && i < 3){
							if(a!=NULL && a[i] < 3){
								b[i] = a[a[i]];
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}
			if(a!=NULL && i < 3){
					if(b!=NULL && a[i] * i < 3){
							if(b!=NULL && a[i] < 3){
									if(a!=NULL && b[a[i]] < 3){
										b[a[i] * i] = a[b[a[i]]];
								 
									}
									else{
										printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
										exit(-1);
									}
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}


		a= NULL;
		b= NULL;

		collect();
		return 0;
	}
