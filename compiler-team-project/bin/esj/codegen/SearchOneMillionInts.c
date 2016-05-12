#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ListM ListM;
typedef struct SearchOneMillionInts SearchOneMillionInts;
	typedef struct ListM{
		int* l;
		int search;
		bool found;

	}ListM;
bool searchfor2 (int*);
void populate (int*);
	int main(int argc, char *argv[]){
		ListM* lm;
		lm = ((ListM*)gc_malloc(sizeof(ListM),&(lm)));
			if(lm != NULL){
				lm->l = ((int*)gc_malloc((1000000)*sizeof(int),&(lm)));
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(lm != NULL){
				populate(lm->l);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(searchfor2(lm->l)){
					if(lm != NULL){
						lm->found = true;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
					if(lm != NULL){
						lm->found = false;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}

			}


		lm= NULL;

		collect();
		return 0;
	}
	bool searchfor2 (int* list){
		int i;
		ListM* lm;
		i = 0;
		lm = ((ListM*)gc_malloc(sizeof(ListM),&(lm)));
			if(lm != NULL){
				lm->search = 2;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			while(i < 1000000){
					if(list[i] == lm->search){
							bool joy;
							joy=true;
							lm= NULL;

							collect();
							return joy; 
					}
					else{
					}
					if(list!=NULL){
							if(lm != NULL){
								i++;
						 
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
			bool joy;
			joy=false;
			lm= NULL;

			collect();
			return joy;

	}
	void populate (int* list){
		int i;
			for(i = 0;i < 1000000;i++){
					if(list!=NULL){
						list[i] = i;
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}

			}


	}
