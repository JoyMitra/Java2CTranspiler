#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct NullEqualsNull NullEqualsNull;
typedef struct NEN NEN;
	typedef struct NEN{
	}NEN;
NEN* returnNull ();
	int main(int argc, char *argv[]){
		assertTrue(NULL == returnNull());
		assertTrue(returnNull() == NULL);
		assertTrue(NULL == NULL);
		assertTrue((!(NULL != returnNull())));
		assertTrue((!(returnNull() != NULL)));
		assertTrue((!(NULL != NULL)));
		assertTrue(NULL == returnNull());


		collect();
		return 0;
	}
	NEN* returnNull (){
		 collect();
		 return NULL;


	}
