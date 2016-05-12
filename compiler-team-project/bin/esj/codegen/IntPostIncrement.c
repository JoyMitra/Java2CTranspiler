#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntPostIncrement IntPostIncrement;
	int main(int argc, char *argv[]){
		int i;
		i = 2;
		i++;
		assertTrue(i == 3);


		collect();
		return 0;
	}
