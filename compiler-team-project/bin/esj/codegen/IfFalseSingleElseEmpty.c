#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IfFalseSingleElseEmpty IfFalseSingleElseEmpty;
	int main(int argc, char *argv[]){
		int a;
		a = 0;
			if(false){
				a = 1;
		 
			}
			else{
			}
		assertTrue(a == 0);


		collect();
		return 0;
	}
