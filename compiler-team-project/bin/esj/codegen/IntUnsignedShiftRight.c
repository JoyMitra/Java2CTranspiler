#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntUnsignedShiftRight IntUnsignedShiftRight;
int unsignedShiftRight (int, int);
	int main(int argc, char *argv[]){
		assertTrue(((unsigned int)2) >> 1 == 1);
		assertTrue(((unsigned int)(-2)) >> 1 == 2147483647);
		assertTrue(unsignedShiftRight(2,1) == 1);
		assertTrue(unsignedShiftRight((-2),1) == 2147483647);


		collect();
		return 0;
	}
	int unsignedShiftRight (int i, int j){
			int joy;
			joy=((unsigned int)i) >> j;
			collect();
			return joy;

	}
