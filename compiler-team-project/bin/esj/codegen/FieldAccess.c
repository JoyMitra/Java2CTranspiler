#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct FieldAccessFoo FieldAccessFoo;
typedef struct FieldAccessBar FieldAccessBar;
typedef struct FieldAccess FieldAccess;
	typedef struct FieldAccessFoo{
		int i;

	}FieldAccessFoo;
	typedef struct FieldAccessBar{
		int i;
		FieldAccessFoo* f;

	}FieldAccessBar;
	int main(int argc, char *argv[]){
		int i;
		FieldAccessFoo* f;
		FieldAccessBar* b;
		f = ((FieldAccessFoo*)gc_malloc(sizeof(FieldAccessFoo),&(f)));
			if(f != NULL){
				f->i = 0;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(f != NULL){
				i = f->i;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(f != NULL){
				assertTrue(f->i == 0);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
		assertTrue(i == 0);
		b = ((FieldAccessBar*)gc_malloc(sizeof(FieldAccessBar),&(f)));
			if(b != NULL){
				b->i = 1;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
				i = b->i;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
				assertTrue(b->i == 1);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
		assertTrue(i == 1);
			if(b != NULL){
				b->f = f;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
					if(b->f != NULL){
						b->f->i = 2;
				 
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
			if(b != NULL){
					if(b->f != NULL){
						i = b->f->i;
				 
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
			if(b != NULL){
					if(b->f != NULL){
						assertTrue(b->f->i == 2);
				 
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
		assertTrue(i == 2);
			if(b != NULL){
					if(b->f != NULL){
						b->f->i = 3;
				 
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
			if(f != NULL){
					if(b != NULL){
							if(b->f != NULL){
								f->i = b->f->i;
						 
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
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
					if(b->f != NULL){
						assertTrue(b->f->i == 3);
				 
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
			if(f != NULL){
				assertTrue(f->i == 3);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
					if(b->f != NULL){
						b->f->i = 4;
				 
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
			if(b != NULL){
				f = b->f;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(f != NULL){
				assertTrue(f->i == 4);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(f != NULL){
				f->i = 5;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
				b->f = f;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(b != NULL){
					if(b->f != NULL){
						assertTrue(b->f->i == 5);
				 
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
			if(b != NULL){
					if(b->f != NULL){
						b->f->i++;
				 
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
			if(b != NULL){
					if(b->f != NULL){
						assertTrue(b->f->i == 6);
				 
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


		f= NULL;
		b= NULL;

		collect();
		return 0;
	}
