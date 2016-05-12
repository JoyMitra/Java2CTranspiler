#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Res Res;
typedef struct BinSearch BinSearch;
	typedef struct Res{
		bool found;

	}Res;
	int main(int argc, char *argv[]){
		int* nos;
		int n;
		int limit;
		int low;
		int mid;
		nos = ((int*)gc_malloc((12)*sizeof(int),&(nos)));
		nos[0] = 1;
		nos[1] = 2;
		nos[2] = 3;
		nos[3] = 4;
		nos[4] = 4;
		nos[5] = 3;
		nos[6] = 2;
		nos[7] = 2;
		nos[8] = 4;
		nos[9] = 2;
		nos[10] = 4;
		nos[11] = 5;
		n = 5;
		limit = 12;
		low = 0;
			while(low < limit){
					if(2!=0){
						mid = (low + limit) / 2;
				 
					}
					else{
						printf("Error:Divide by zero near line %d\n",__LINE__);
						exit(-1);
					}
					if(nos[mid] == n){
							if(nos!=NULL && mid < 12){
									if(((Res*)gc_malloc(sizeof(Res),&(nos))) != NULL){
										((Res*)gc_malloc(sizeof(Res),&(nos)))->found = true;
								 
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
						low = limit + 1;
				 
					}
					else{
							if(n > nos[mid]){
									if(nos!=NULL && mid < 12){
										low = mid + 1;
								 
									}
									else{
										printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
										exit(-1);
									}
						 
							}
							else{
								limit = mid - 1;

							}

					}

			}


		nos= NULL;

		collect();
		return 0;
	}
