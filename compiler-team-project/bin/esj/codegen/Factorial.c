#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Factorial Factorial;
int factorial (int);
	int main(int argc, char *argv[]){
		factorial(4);


		collect();
		return 0;
	}
	int factorial (int n){
		int result;
		int i;
		assertTrue(n >= 1);
		result = 1;
		i = 2;
			while(i <= n){
				result = result * i;
				i = i + 1;

			}
		println(result);
			int joy;
			joy=result;
			collect();
			return joy;

	}
