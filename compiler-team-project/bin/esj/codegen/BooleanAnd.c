#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct BooleanAnd BooleanAnd;
bool and (bool, bool);
	int main(int argc, char *argv[]){
		assertTrue((true && true) == true);
		assertTrue((true && false) == false);
		assertTrue((false && true) == false);
		assertTrue((false && false) == false);
		assertTrue(and(true,true) == true);
		assertTrue(and(true,false) == false);
		assertTrue(and(false,true) == false);
		assertTrue(and(false,false) == false);


		collect();
		return 0;
	}
	bool and (bool b, bool c){
			bool joy;
			joy=b && c;
			collect();
			return joy;

	}
