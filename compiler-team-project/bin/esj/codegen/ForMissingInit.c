#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForMissingInit ForMissingInit;
void missingInit ();
	int main(int argc, char *argv[]){
		missingInit();


		collect();
		return 0;
	}
	void missingInit (){
		int i;
		i = 0;
			for(;i < 10;i++){
			}
		assertTrue(i == 10);


	}
