#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct IntDivide IntDivide;
int divide (int, int);
	int main(int argc, char *argv[]){
			if(3!=0){
				assertTrue(2 / 3 == 0);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if((-3)!=0){
				assertTrue(2 / (-3) == 0);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if(3!=0){
				assertTrue((-2) / 3 == 0);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if((-3)!=0){
				assertTrue((-2) / (-3) == 0);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if(2!=0){
				assertTrue(3 / 2 == 1);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if((-2)!=0){
				assertTrue(3 / (-2) == (-1));
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if(2!=0){
				assertTrue((-3) / 2 == (-1));
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			if((-2)!=0){
				assertTrue((-3) / (-2) == 1);
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
		assertTrue(divide(2,3) == 0);
		assertTrue(divide(2,(-3)) == 0);
		assertTrue(divide((-2),3) == 0);
		assertTrue(divide((-2),(-3)) == 0);
		assertTrue(divide(3,2) == 1);
		assertTrue(divide(3,(-2)) == (-1));
		assertTrue(divide((-3),2) == (-1));
		assertTrue(divide((-3),(-2)) == 1);


		collect();
		return 0;
	}
	int divide (int i, int j){
			int joy;
			joy=i / j;
			collect();
			return joy;

	}
