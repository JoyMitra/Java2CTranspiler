#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IfTrueSingleElseSingle IfTrueSingleElseSingle;
	int main(int argc, char *argv[]){
		int a;
		a = 0;
			if(true){
				a = 1;
		 
			}
			else{
				a = 2;

			}
		assertTrue(a == 1);


		collect();
		return 0;
	}
