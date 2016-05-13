#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Empty Empty;
typedef struct ManyTypes ManyTypes;
typedef struct SyntaxTorture SyntaxTorture;
	typedef struct Empty{
	}Empty;
	typedef struct ManyTypes{
		int i;
		bool b;
		Empty* e;
		int* i_array;
		bool* b_array;
		Empty** e_array;

	}ManyTypes;
int returnInt ();
bool returnBoolean (bool);
Empty* returnEmpty (int, Empty*);
int* returnIntArray ();
bool* returnBooleanArray (bool*);
Empty** returnObjectArray (int*, Empty**);
void returnVoid ();
int aa;
bool bb;
Empty* cc;
int* dd;
bool* ee;
Empty** ff;
int g;
	int main(int argc, char *argv[]){
		int i;
		int* i_array;
		int j;
		bool b;
		bool* b_array;
		ManyTypes* m;
		ManyTypes** m_array;
		i = 0;
		j = i;
		b = true;
			if((i <= 0)){
					while((~9) <= i && i == (-1)){
						i = i + i;

					}
				b = false;
					while(true && b){
						i++;

					}
				i--;
					for(i = 0;(!(i != 0));i--,i++,i--){
						i = ((unsigned int)i) >> ((-1));
						returnInt();
						returnVoid();

					}
		 
			}
			else{
			}
			do{
				i++;

			}while((7) << (~((-5))) == j);
		m = ((ManyTypes*)gc_malloc(sizeof(ManyTypes),&(m)));
			if(m != NULL){
				m->b = false;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
		i = 4;
		m_array = ((ManyTypes**)gc_malloc((i)*sizeof(ManyTypes*),&(m_array)));
			if(m_array!=NULL && 0 < i){
				m_array[0] = m;
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}
		i_array = ((int*)gc_malloc((4)*sizeof(int),&(i_array)));
		i_array[0] = 0;
		i_array[1] = i;
		i_array[2] = j;
		i_array[3] = 7;
		j = 0;
			if(m != NULL){
				m->i = 0;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(m != NULL){
					if(i_array!=NULL && m->i < 4){
							if(m_array!=NULL && i_array[m->i] < i){
									if(m_array!=NULL && j < i){
										m_array[i_array[m->i]] = m_array[j];
								 
									}
									else{
										printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
										exit(-1);
									}
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			for(i = 2,i = j;j < ((i) << 4) && j == i;j++,i--){
			}
		b = false;
		m = b?NULL:((m));
		b_array = ((bool*)gc_malloc((1)*sizeof(bool),&(b_array)));
		b_array[0] = true;
			if(m != NULL){
				m->b_array = b_array;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(m != NULL){
				b_array = returnBooleanArray(m->b_array);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
		m = NULL;
		b_array = ((bool*)gc_malloc((1)*sizeof(bool),&(b_array)));
		b_array[0] = true;
			if(i_array!=NULL && returnInt() < 4){
					if(returnIntArray()!=NULL){
							if(i_array!=NULL && returnIntArray()[2] < 4){
								i_array[returnInt()] = i_array[returnIntArray()[2]];
						 
							}
							else{
								printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
								exit(-1);
							}
				 
					}
					else{
						printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
						exit(-1);
					}
		 
			}
			else{
				printf("Error:Index Out Of Bounds near line %d\n",__LINE__);
				exit(-1);
			}


		i_array= NULL;
		b_array= NULL;
		m= NULL;
		m_array= NULL;

		collect();
		return 0;
	}
	int returnInt (){
		int i;
		i = 0;
			int joy;
			joy=i;
			collect();
			return joy;

	}
	bool returnBoolean (bool b){
		bool c;
		int i;
		c = true;
		i = 0;
			bool joy;
			joy=(!(!(((!c)) && (false || true) || (i > 2 && i >= (-1)) || 3 == i && ((4) != i) || 3 < 5 && (~1) <= (-((~2))))));
			collect();
			return joy;

	}
	Empty* returnEmpty (int i, Empty* e){
		int j;
		Empty* f;
		f = ((Empty*)gc_malloc(sizeof(Empty),&(f)));
			Empty* joy;
			joy=f;
			f= NULL;

			collect();
			return joy;

	}
	int* returnIntArray (){
		int* i;
			if((5 % 6 << 7)!=0){
				i = ((int*)gc_malloc(((((unsigned int)1 + ((2 - 3) * 4) / (5 % 6 << 7) >> (8)) >> 9) + 3)*sizeof(int),&(i)));
		 
			}
			else{
				printf("Error:Divide by zero near line %d\n",__LINE__);
				exit(-1);
			}
			int* joy;
			joy=i;
			i= NULL;

			collect();
			return joy;

	}
	bool* returnBooleanArray (bool* b){
		bool* c;
		c = ((bool*)gc_malloc((3)*sizeof(bool),&(c)));
		c[0] = true;
		c[1] = false;
		c[2] = false;
			bool* joy;
			joy=(c);
			c= NULL;

			collect();
			return joy;

	}
	Empty** returnObjectArray (int* i, Empty** e){
			Empty** joy;
			joy=e;
			collect();
			return joy;

	}
	void returnVoid (){


	}
