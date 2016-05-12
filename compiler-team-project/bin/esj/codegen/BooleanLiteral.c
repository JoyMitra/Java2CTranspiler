#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct BooleanLiteral BooleanLiteral;
	int main(int argc, char *argv[]){
		assertTrue(true);
		assertTrue((!false));


		collect();
		return 0;
	}
