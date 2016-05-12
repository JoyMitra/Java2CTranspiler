#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntAdd IntAdd;
int add (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 + 3 == 5);
		assertTrue(2 + (-3) == (-1));
		assertTrue((-2) + 3 == 1);
		assertTrue((-2) + (-3) == (-5));
		assertTrue(add(2,3) == 5);
		assertTrue(add(2,(-3)) == (-1));
		assertTrue(add((-2),3) == 1);
		assertTrue(add((-2),(-3)) == (-5));


		collect();
		return 0;
	}
	int add (int i, int j){
			int joy;
			joy=i + j;
			collect();
			return joy;

	}
