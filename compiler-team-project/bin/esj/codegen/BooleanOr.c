#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct BooleanOr BooleanOr;
bool or (bool, bool);
	int main(int argc, char *argv[]){
		assertTrue((true || true) == true);
		assertTrue((true || false) == true);
		assertTrue((false || true) == true);
		assertTrue((false || false) == false);
		assertTrue(or(true,true) == true);
		assertTrue(or(true,false) == true);
		assertTrue(or(false,true) == true);
		assertTrue(or(false,false) == false);


		collect();
		return 0;
	}
	bool or (bool b, bool c){
			bool joy;
			joy=b || c;
			collect();
			return joy;

	}
