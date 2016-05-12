#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ConditionalTrue ConditionalTrue;
	int main(int argc, char *argv[]){
		int i;
		i = 1;
		i = i > 0?2:3;
		assertTrue(i == 2);


		collect();
		return 0;
	}
