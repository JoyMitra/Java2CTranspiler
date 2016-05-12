#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntNotEqual IntNotEqual;
bool notEqual (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 != 3 == true);
		assertTrue(3 != 2 == true);
		assertTrue(2 != 2 == false);
		assertTrue(notEqual(2,3) == true);
		assertTrue(notEqual(3,2) == true);
		assertTrue(notEqual(2,2) == false);


		collect();
		return 0;
	}
	bool notEqual (int i, int j){
			bool joy;
			joy=i != j;
			collect();
			return joy;

	}
