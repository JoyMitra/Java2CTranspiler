#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForCondOnly ForCondOnly;
void condOnly ();
	int main(int argc, char *argv[]){


		collect();
		return 0;
	}
	void condOnly (){
		int i;
		i = 0;
			for(;i < 10;){
			}


	}
