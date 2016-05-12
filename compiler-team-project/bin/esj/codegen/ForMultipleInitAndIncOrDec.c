#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct ForMultipleInitAndIncOrDec ForMultipleInitAndIncOrDec;
void multipleInitAndIncOrDec ();
	int main(int argc, char *argv[]){
		multipleInitAndIncOrDec();


		collect();
		return 0;
	}
	void multipleInitAndIncOrDec (){
		int i;
		int j;
		int k;
			for(i = 0,j = 0,k = 0;i < 10;i++,j++,k++){
			}
		assertTrue(i == 10);
		assertTrue(j == 10);
		assertTrue(k == 10);


	}
