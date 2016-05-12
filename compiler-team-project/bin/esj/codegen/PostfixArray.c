#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct PostfixArray PostfixArray;
	int main(int argc, char *argv[]){
		int* a;
		int i;
		a = ((int*)gc_malloc((5)*sizeof(int),&(a)));
			for(i = 0;i < 5;i++){
					if(a!=NULL && i < 5){
						a[i] = i;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
		i = 0;
			if(a!=NULL && i < 5){
					if(a!=NULL && a[i] < 5){
						a[a[i]]++;
				 
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
		i++;
			if(a!=NULL && i < 5){
					if(a!=NULL && a[i] < 5){
							if(a!=NULL && a[a[i]] < 5){
								a[a[a[i]]]++;
						 
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

		collect();
		return 0;
	}
