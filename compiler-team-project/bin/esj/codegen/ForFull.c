#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForFull ForFull;
void full ();
	int main(int argc, char *argv[]){
		full();


		collect();
		return 0;
	}
	void full (){
		int i;
			for(i = 0;i < 10;i++){
			}
		assertTrue(i == 10);


	}
