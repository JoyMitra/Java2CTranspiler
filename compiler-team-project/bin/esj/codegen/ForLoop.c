#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForLoop ForLoop;
	int main(int argc, char *argv[]){
		int i;
		int j;
		int x;
			for(x = 0,i = 0,j = 0;i < 5;i++,j++){
				x = x + i + j;

			}


		collect();
		return 0;
	}
