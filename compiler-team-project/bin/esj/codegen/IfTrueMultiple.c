#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IfTrueMultiple IfTrueMultiple;
	int main(int argc, char *argv[]){
		int a;
		a = 0;
			if(true){
				a = 1;
				a = 2;
		 
			}
			else{
			}
		assertTrue(a == 2);


		collect();
		return 0;
	}
