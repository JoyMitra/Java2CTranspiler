#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntPlus IntPlus;
int plus (int);
	int main(int argc, char *argv[]){
		assertTrue((2) == 2);
		assertTrue(((-2)) == (-2));
		assertTrue(plus(2) == 2);
		assertTrue(plus((-2)) == (-2));


		collect();
		return 0;
	}
	int plus (int i){
			int joy;
			joy=(i);
			collect();
			return joy;

	}
