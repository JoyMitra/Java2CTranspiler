#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct BinaryOps BinaryOps;
int add (int, int);
int subtract (int, int);
int multiply (int, int);
int divide (int, int);
int mod (int, int);
bool greaterThan (int, int);
bool greaterThanOrEqual (int, int);
bool equal (int, int);
bool lessThan (int, int);
bool lessThanOrEqual (int, int);
bool notEqual (int, int);
bool boolAnd (bool, bool);
bool boolOr (bool, bool);
int shiftLeft (int, int);
int shiftRight (int, int);
int unsignedShiftRight (int, int);
	int main(int argc, char *argv[]){
		assertTrue(add(2,3) == 5);
		assertTrue(add(2,(-3)) == (-1));
		assertTrue(add((-2),3) == 1);
		assertTrue(add((-2),(-3)) == (-5));
		assertTrue(subtract(2,3) == (-1));
		assertTrue(subtract(2,(-3)) == 5);
		assertTrue(subtract((-2),3) == (-5));
		assertTrue(subtract((-2),(-3)) == 1);
		assertTrue(multiply(2,3) == 6);
		assertTrue(multiply(2,(-3)) == (-6));
		assertTrue(multiply((-2),3) == (-6));
		assertTrue(multiply((-2),(-3)) == 6);
		assertTrue(divide(2,3) == 0);
		assertTrue(divide(2,(-3)) == 0);
		assertTrue(divide((-2),3) == 0);
		assertTrue(divide((-2),(-3)) == 0);
		assertTrue(divide(3,2) == 1);
		assertTrue(divide(3,(-2)) == (-1));
		assertTrue(divide((-3),2) == (-1));
		assertTrue(divide((-3),(-2)) == 1);
		assertTrue(mod(2,3) == 2);
		assertTrue(mod(2,(-3)) == 2);
		assertTrue(mod((-2),3) == (-2));
		assertTrue(mod((-2),(-3)) == (-2));
		assertTrue(mod(3,2) == 1);
		assertTrue(mod(3,(-2)) == 1);
		assertTrue(mod((-3),2) == (-1));
		assertTrue(mod((-3),(-2)) == (-1));
		assertTrue(true);
		assertTrue((!false));
		assertTrue(greaterThan(2,3) == false);
		assertTrue(greaterThan(3,2) == true);
		assertTrue(greaterThan(2,2) == false);
		assertTrue(greaterThanOrEqual(2,3) == false);
		assertTrue(greaterThanOrEqual(3,2) == true);
		assertTrue(greaterThanOrEqual(2,2) == true);
		assertTrue(equal(2,3) == false);
		assertTrue(equal(3,2) == false);
		assertTrue(equal(2,2) == true);
		assertTrue(lessThan(2,3) == true);
		assertTrue(lessThan(3,2) == false);
		assertTrue(lessThan(2,2) == false);
		assertTrue(lessThanOrEqual(2,3) == true);
		assertTrue(lessThanOrEqual(3,2) == false);
		assertTrue(lessThanOrEqual(2,2) == true);
		assertTrue(notEqual(2,3) == true);
		assertTrue(notEqual(3,2) == true);
		assertTrue(notEqual(2,2) == false);
		assertTrue(boolAnd(true,true) == true);
		assertTrue(boolAnd(true,false) == false);
		assertTrue(boolAnd(false,true) == false);
		assertTrue(boolAnd(false,false) == false);
		assertTrue(boolOr(true,true) == true);
		assertTrue(boolOr(true,false) == true);
		assertTrue(boolOr(false,true) == true);
		assertTrue(boolOr(false,false) == false);
		assertTrue(shiftLeft(2,1) == 4);
		assertTrue(shiftLeft((-2),1) == (-4));
		assertTrue(shiftRight(2,1) == 1);
		assertTrue(shiftRight((-2),1) == (-1));
		assertTrue(unsignedShiftRight(2,1) == 1);
		assertTrue(unsignedShiftRight((-2),1) == 2147483647);


		collect();
		return 0;
	}
	int add (int a, int b){
			int joy;
			joy=a + b;
			collect();
			return joy;

	}
	int subtract (int a, int b){
			int joy;
			joy=a - b;
			collect();
			return joy;

	}
	int multiply (int a, int b){
			int joy;
			joy=a * b;
			collect();
			return joy;

	}
	int divide (int a, int b){
			int joy;
			joy=a / b;
			collect();
			return joy;

	}
	int mod (int a, int b){
			int joy;
			joy=a % b;
			collect();
			return joy;

	}
	bool greaterThan (int a, int b){
			bool joy;
			joy=a > b;
			collect();
			return joy;

	}
	bool greaterThanOrEqual (int a, int b){
			bool joy;
			joy=a >= b;
			collect();
			return joy;

	}
	bool equal (int a, int b){
			bool joy;
			joy=a == b;
			collect();
			return joy;

	}
	bool lessThan (int a, int b){
			bool joy;
			joy=a < b;
			collect();
			return joy;

	}
	bool lessThanOrEqual (int a, int b){
			bool joy;
			joy=a <= b;
			collect();
			return joy;

	}
	bool notEqual (int a, int b){
			bool joy;
			joy=a != b;
			collect();
			return joy;

	}
	bool boolAnd (bool a, bool b){
			bool joy;
			joy=a && b;
			collect();
			return joy;

	}
	bool boolOr (bool a, bool b){
			bool joy;
			joy=a || b;
			collect();
			return joy;

	}
	int shiftLeft (int i, int j){
			int joy;
			joy=i << j;
			collect();
			return joy;

	}
	int shiftRight (int i, int j){
			int joy;
			joy=i >> j;
			collect();
			return joy;

	}
	int unsignedShiftRight (int i, int j){
			int joy;
			joy=((unsigned int)i) >> j;
			collect();
			return joy;

	}
