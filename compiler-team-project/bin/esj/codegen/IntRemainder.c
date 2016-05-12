#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntRemainder IntRemainder;
int remainder (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 % 3 == 2);
		assertTrue(2 % (-3) == 2);
		assertTrue((-2) % 3 == (-2));
		assertTrue((-2) % (-3) == (-2));
		assertTrue(3 % 2 == 1);
		assertTrue(3 % (-2) == 1);
		assertTrue((-3) % 2 == (-1));
		assertTrue((-3) % (-2) == (-1));
		assertTrue(remainder(2,3) == 2);
		assertTrue(remainder(2,(-3)) == 2);
		assertTrue(remainder((-2),3) == (-2));
		assertTrue(remainder((-2),(-3)) == (-2));
		assertTrue(remainder(3,2) == 1);
		assertTrue(remainder(3,(-2)) == 1);
		assertTrue(remainder((-3),2) == (-1));
		assertTrue(remainder((-3),(-2)) == (-1));


		collect();
		return 0;
	}
	int remainder (int i, int j){
			int joy;
			joy=i % j;
			collect();
			return joy;

	}
