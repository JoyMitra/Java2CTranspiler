#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntMultiply IntMultiply;
int multiply (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 * 3 == 6);
		assertTrue(2 * (-3) == (-6));
		assertTrue((-2) * 3 == (-6));
		assertTrue((-2) * (-3) == 6);
		assertTrue(multiply(2,3) == 6);
		assertTrue(multiply(2,(-3)) == (-6));
		assertTrue(multiply((-2),3) == (-6));
		assertTrue(multiply((-2),(-3)) == 6);


		collect();
		return 0;
	}
	int multiply (int i, int j){
			int joy;
			joy=i * j;
			collect();
			return joy;

	}
