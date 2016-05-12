#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IfTrueSingle IfTrueSingle;
	int main(int argc, char *argv[]){
		int a;
		a = 0;
			if(true){
				a = 1;
		 
			}
			else{
			}
		assertTrue(a == 1);


		collect();
		return 0;
	}
