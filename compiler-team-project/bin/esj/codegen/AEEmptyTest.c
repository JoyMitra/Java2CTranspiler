#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct AEEmptyTest AEEmptyTest;
	int main(int argc, char *argv[]){
		int x;
		int y;
		bool b;
		x = 1;
		y = 2;
		b = x + y > 2;
			while(b){
				b = false;

			}
		b = x > y;


		collect();
		return 0;
	}
