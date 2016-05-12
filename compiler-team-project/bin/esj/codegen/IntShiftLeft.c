#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntShiftLeft IntShiftLeft;
int shiftLeft (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 << 1 == 4);
		assertTrue((-2) << 1 == (-4));
		assertTrue(shiftLeft(2,1) == 4);
		assertTrue(shiftLeft((-2),1) == (-4));


		collect();
		return 0;
	}
	int shiftLeft (int i, int j){
			int joy;
			joy=i << j;
			collect();
			return joy;

	}
