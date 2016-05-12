#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Power Power;
int power (int, int);
	int main(int argc, char *argv[]){
		power(3,2);


		collect();
		return 0;
	}
	int power (int m, int n){
		int result;
		int i;
		assertTrue(n >= 1);
		result = 1;
		i = 0;
			while(i < n){
				result = result * m;
				i = i + 1;

			}
			int joy;
			joy=result;
			collect();
			return joy;

	}
