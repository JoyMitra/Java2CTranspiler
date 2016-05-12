#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntEqual IntEqual;
bool equal (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 == 3 == false);
		assertTrue(3 == 2 == false);
		assertTrue(2 == 2 == true);
		assertTrue(equal(2,3) == false);
		assertTrue(equal(3,2) == false);
		assertTrue(equal(2,2) == true);


		collect();
		return 0;
	}
	bool equal (int i, int j){
			bool joy;
			joy=i == j;
			collect();
			return joy;

	}
