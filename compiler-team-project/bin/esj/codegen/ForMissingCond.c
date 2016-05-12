#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForMissingCond ForMissingCond;
void missingCond ();
	int main(int argc, char *argv[]){


		collect();
		return 0;
	}
	void missingCond (){
		int i;
			for(i = 0;;i++){
			}


	}
