#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IfFalseSingleElseMultiple IfFalseSingleElseMultiple;
	int main(int argc, char *argv[]){
		int a;
		a = 0;
			if(false){
				a = 1;
		 
			}
			else{
				a = 2;
				a = 3;

			}
		assertTrue(a == 3);


		collect();
		return 0;
	}
