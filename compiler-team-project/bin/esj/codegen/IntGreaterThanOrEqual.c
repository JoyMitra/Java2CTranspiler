#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntGreaterThanOrEqual IntGreaterThanOrEqual;
bool greaterThanOrEqual (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 >= 3 == false);
		assertTrue(3 >= 2 == true);
		assertTrue(2 >= 2 == true);
		assertTrue(greaterThanOrEqual(2,3) == false);
		assertTrue(greaterThanOrEqual(3,2) == true);
		assertTrue(greaterThanOrEqual(2,2) == true);


		collect();
		return 0;
	}
	bool greaterThanOrEqual (int i, int j){
			bool joy;
			joy=i >= j;
			collect();
			return joy;

	}
