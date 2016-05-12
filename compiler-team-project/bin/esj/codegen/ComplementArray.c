#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ComplementArray ComplementArray;
	int main(int argc, char *argv[]){
		bool* arr;
		int i;
		int j;
		arr = ((bool*)gc_malloc((9)*sizeof(bool),&(arr)));
		arr[0] = true;
		arr[1] = true;
		arr[2] = false;
		arr[3] = true;
		arr[4] = false;
		arr[5] = true;
		arr[6] = false;
		arr[7] = false;
		arr[8] = true;
		i = 9;
			for(j = 0;j < i - 1;j++){
					if(arr!=NULL && j < 9){
							if(arr!=NULL && j + 1 < 9){
								arr[j] = (!(arr[j] && arr[j + 1]));
						 
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


		arr= NULL;

		collect();
		return 0;
	}
