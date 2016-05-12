#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntShiftRight IntShiftRight;
int shiftRight (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 >> 1 == 1);
		assertTrue((-2) >> 1 == (-1));
		assertTrue(shiftRight(2,1) == 1);
		assertTrue(shiftRight((-2),1) == (-1));


		collect();
		return 0;
	}
	int shiftRight (int i, int j){
			int joy;
			joy=i >> j;
			collect();
			return joy;

	}
