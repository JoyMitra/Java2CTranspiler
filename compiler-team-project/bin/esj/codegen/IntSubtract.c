#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntSubtract IntSubtract;
int subtract (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 - 3 == (-1));
		assertTrue(2 - (-3) == 5);
		assertTrue((-2) - 3 == (-5));
		assertTrue((-2) - (-3) == 1);
		assertTrue(subtract(2,3) == (-1));
		assertTrue(subtract(2,(-3)) == 5);
		assertTrue(subtract((-2),3) == (-5));
		assertTrue(subtract((-2),(-3)) == 1);


		collect();
		return 0;
	}
	int subtract (int i, int j){
			int joy;
			joy=i - j;
			collect();
			return joy;

	}
