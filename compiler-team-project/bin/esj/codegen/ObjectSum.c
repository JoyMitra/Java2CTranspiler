#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct XY XY;
typedef struct ObjectSum ObjectSum;
typedef struct XX XX;
typedef struct XZ XZ;
	typedef struct XY{
		int a;

	}XY;
	typedef struct XX{
		int b;

	}XX;
	typedef struct XZ{
		int c;

	}XZ;
int sum (XY*, XX*, XZ*);
	int main(int argc, char *argv[]){
		int res;
		XY* xy;
		XX* xx;
		XZ* xz;
		xy = ((XY*)gc_malloc(sizeof(XY),&(xy)));
		xx = ((XX*)gc_malloc(sizeof(XX),&(xx)));
		xz = ((XZ*)gc_malloc(sizeof(XZ),&(xz)));
		res = sum(xy,xx,xz);


		xy= NULL;
		xx= NULL;
		xz= NULL;

		collect();
		return 0;
	}
	int sum (XY* xy, XX* xx, XZ* xz){
			if(xy != NULL){
				xy->a = 5;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(xx != NULL){
					if(xy != NULL){
						xx->b = xy->a * 2;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(xz != NULL){
					if(xx != NULL){
							if(2!=0){
								xz->c = xx->b / 2;
						 
							}
							else{
								printf("Error:Divide by zero near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			int joy;
			joy=(xy->a + xx->b + xz->c);
			collect();
			return joy;

	}
