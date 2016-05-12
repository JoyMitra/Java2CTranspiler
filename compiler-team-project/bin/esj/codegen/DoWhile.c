#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct DoWhile DoWhile;
	int main(int argc, char *argv[]){
		int i;
		i = 0;
			do{
				i++;

			}while(i < 10);
		assertTrue(i == 10);


		collect();
		return 0;
	}
