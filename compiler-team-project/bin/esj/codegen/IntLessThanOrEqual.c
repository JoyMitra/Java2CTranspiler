#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntLessThanOrEqual IntLessThanOrEqual;
bool lessThanOrEqual (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 <= 3 == true);
		assertTrue(3 <= 2 == false);
		assertTrue(2 <= 2 == true);
		assertTrue(lessThanOrEqual(2,3) == true);
		assertTrue(lessThanOrEqual(3,2) == false);
		assertTrue(lessThanOrEqual(2,2) == true);


		collect();
		return 0;
	}
	bool lessThanOrEqual (int i, int j){
			bool joy;
			joy=i <= j;
			collect();
			return joy;

	}
