#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct DoWhileWithBooleanArrayAccessCondition DoWhileWithBooleanArrayAccessCondition;
	int main(int argc, char *argv[]){
		bool* B;
		int i;
		B = ((bool*)gc_malloc((2)*sizeof(bool),&(B)));
		B[0] = true;
		B[1] = false;
		i = 1;
			do{
			}while(B[i]);


		B= NULL;

		collect();
		return 0;
	}
