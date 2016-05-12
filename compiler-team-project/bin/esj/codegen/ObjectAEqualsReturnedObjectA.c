#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Object64 Object64;
typedef struct ObjectAEqualsReturnedObjectA ObjectAEqualsReturnedObjectA;
	typedef struct Object64{
	}Object64;
Object64* returnObject (Object64*);
	int main(int argc, char *argv[]){
		Object64* o;
		o = ((Object64*)gc_malloc(sizeof(Object64),&(o)));
		assertTrue(o == returnObject(o));


		o= NULL;

		collect();
		return 0;
	}
	Object64* returnObject (Object64* o){
			Object64* joy;
			joy=o;
			collect();
			return joy;

	}
