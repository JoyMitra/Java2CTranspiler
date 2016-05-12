#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntGreaterThan IntGreaterThan;
bool greaterThan (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 > 3 == false);
		assertTrue(3 > 2 == true);
		assertTrue(2 > 2 == false);
		assertTrue(greaterThan(2,3) == false);
		assertTrue(greaterThan(3,2) == true);
		assertTrue(greaterThan(2,2) == false);


		collect();
		return 0;
	}
	bool greaterThan (int i, int j){
			bool joy;
			joy=i > j;
			collect();
			return joy;

	}
