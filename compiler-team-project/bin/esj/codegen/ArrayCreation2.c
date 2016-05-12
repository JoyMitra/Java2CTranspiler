#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ArrayCreation2 ArrayCreation2;
	int main(int argc, char *argv[]){
		int* a;
		int b;
		int i;
		a = ((int*)gc_malloc((5)*sizeof(int),&(a)));
		b = 0;
			for(i = 0;i < 5;i++){
					if(a!=NULL && i < 5){
						a[i] = i;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
					if(a!=NULL && i < 5){
						b = b + a[i];
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
		assertTrue(b == 10);
			for(i = 0;i < 5;i++){
					if(a!=NULL && i < 5){
						a[i]++;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}
		i = 0;
			for(i = 0;i < 5;i++){
					if(a!=NULL && i < 5){
						assertTrue(a[i] == (i + 1));
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


		a= NULL;

		collect();
		return 0;
	}
