#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct BooleanNot BooleanNot;
bool not (bool);
	int main(int argc, char *argv[]){
		assertTrue((!false) == true);
		assertTrue((!true) == false);
		assertTrue(not(false) == true);
		assertTrue(not(true) == false);


		collect();
		return 0;
	}
	bool not (bool b){
			bool joy;
			joy=(!b);
			collect();
			return joy;

	}
