#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntLessThan IntLessThan;
bool lessThan (int, int);
	int main(int argc, char *argv[]){
		assertTrue(2 < 3 == true);
		assertTrue(3 < 2 == false);
		assertTrue(2 < 2 == false);
		assertTrue(lessThan(2,3) == true);
		assertTrue(lessThan(3,2) == false);
		assertTrue(lessThan(2,2) == false);


		collect();
		return 0;
	}
	bool lessThan (int i, int j){
			bool joy;
			joy=i < j;
			collect();
			return joy;

	}
