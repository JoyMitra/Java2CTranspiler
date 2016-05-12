#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct While While;
	int main(int argc, char *argv[]){
		int i;
		i = 0;
			while(i < 10){
				i++;

			}
		assertTrue(i == 10);


		collect();
		return 0;
	}
