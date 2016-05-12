#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntComplement IntComplement;
int complement (int);
	int main(int argc, char *argv[]){
		assertTrue((~(-5)) == 4);
		assertTrue((~4) == (-5));
		assertTrue(complement((-5)) == 4);
		assertTrue(complement(4) == (-5));


		collect();
		return 0;
	}
	int complement (int i){
			int joy;
			joy=(~i);
			collect();
			return joy;

	}
