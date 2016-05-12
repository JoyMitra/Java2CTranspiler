#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>

#include "staticlib.h"
#include "my_alloc.h"
typedef struct Data Data;
typedef struct LinkedNode LinkedNode;
typedef struct LinkedList LinkedList;
typedef struct Queue Queue;
	typedef struct Data{
		int i;

	}Data;
	typedef struct LinkedNode{
		Data* data;
		LinkedNode* next;

	}LinkedNode;
	typedef struct LinkedList{
		LinkedNode* head;
		LinkedNode* last;
		int size;

	}LinkedList;
LinkedList* llNewLinkedList ();
bool llIsEmpty (LinkedList*);
void llAddLast (LinkedList*, Data*);
Data* llRemoveFirst (LinkedList*);
	int main(int argc, char *argv[]){
		LinkedList* ll;
		Data* d;
		int i;
		ll = llNewLinkedList();
			for(i = 0;i < 10;i++){
				d = ((Data*)gc_malloc(sizeof(Data),&(d)));
					if(d != NULL){
						d->i = i + 1;
				 
					}
					else{
						printf("Error:Null Pointer reference near line %d\n",__LINE__);
						exit(-1);
					}
				llAddLast(ll,d);

			}
			while((!llIsEmpty(ll))){
				d = llRemoveFirst(ll);

			}


		ll= NULL;
		d= NULL;

		collect();
		return 0;
	}
	LinkedList* llNewLinkedList (){
		LinkedList* result;
		result = ((LinkedList*)gc_malloc(sizeof(LinkedList),&(result)));
			if(result != NULL){
				result->head = ((LinkedNode*)gc_malloc(sizeof(LinkedNode),&(result)));
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(result != NULL){
				result->last = result->head;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			LinkedList* joy;
			joy=result;
			result= NULL;

			collect();
			return joy;

	}
	bool llIsEmpty (LinkedList* ll){
		assertTrue(ll != NULL);
			bool joy;
			joy=ll->size == 0;
			collect();
			return joy;

	}
	void llAddLast (LinkedList* ll, Data* data){
			if(ll != NULL){
				assertTrue(ll != NULL && data != NULL);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(ll != NULL){
					if(ll->last != NULL){
						ll->last->next = ((LinkedNode*)gc_malloc(sizeof(LinkedNode),&(ll)));
				 
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
			if(ll != NULL){
					if(ll->last != NULL){
						ll->last = ll->last->next;
				 
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
			if(ll != NULL){
					if(ll->last != NULL){
						ll->last->data = data;
				 
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
			if(ll != NULL){
				ll->size++;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}


	}
	Data* llRemoveFirst (LinkedList* ll){
		Data* result;
			if(ll != NULL){
				assertTrue(ll->size > 0);
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			if(ll != NULL){
					if(ll->head != NULL){
							if(ll->head->next != NULL){
								result = ll->head->next->data;
						 
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
			if(ll != NULL){
					if(ll->head != NULL){
						ll->head = ll->head->next;
				 
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
			if(ll != NULL){
				ll->size--;
		 
			}
			else{
				printf("Error:Null Pointer reference near line %d\n",__LINE__);
				exit(-1);
			}
			Data* joy;
			joy=result;
			result= NULL;

			collect();
			return joy;

	}
