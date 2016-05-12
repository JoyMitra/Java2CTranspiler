#include<stdlib.h>
#include<stdio.h>
#include "my_alloc.h"


 void* memPtr = NULL; 
RefList referenceList = {
 0,
 NULL
};
RefList freeList = {
 0,
 NULL
};

 
void* allocate(size_t size)
{
	
	if(referenceList.head==NULL)
	{
		if(memPtr==NULL)
			memPtr = (void*) memory();
		return memPtr;
	}
	else if(((referenceList.head)->value->endAddr) == allocate_rev)
	{
		collect();
		if(freeList.head!=NULL)
		{
			Reference* freeNode = freeList.head;
			while(freeNode)
			{
				Object* obj = freeNode->value;
				long diff = (obj->endAddr)-(obj->startAddrs);
				if(size>0 && size<=diff)
				{
					freeList.head = freeNode->next;
					freeList.size--;
					return ((void*) (obj->startAddrs));
				}
				freeNode = freeNode->next;
			}
			printf("Error:Not enough memory. please increase heap size");
			return NULL;
		}
		printf("Error:Not enough memory. please increase heap size or free existing memory");
		return NULL;
	}
	else
	{
		return ((referenceList.head)->value->endAddr);
	}
	return NULL;
}

void* memory(){
	void* p = (void*) malloc(MAXSIZE);
	return p;
}

void* gc_malloc(size_t size,void** addr){
	Object* ptr = (Object*)allocate(sizeof(Object));
	ptr->mark = currentMark;
	ptr->startAddrs = ptr+sizeof(Object*);
	ptr->endAddr = (ptr->startAddrs) + size;
	ptr->varAddr = addr;
	ref_add(ptr);
	return (void*) (ptr->startAddrs);
}

void ref_add(Object* obj){
	Reference* ref = (Reference*)allocate_rev(sizeof(Reference));
	ref->next = NULL;
	ref->value = obj;
	if(referenceList.head==NULL){
		referenceList.head = ref;
		referenceList.size++;
	}
	else{
		ref->next = (referenceList.head);
		referenceList.head = ref;
		referenceList.size++;
	}
	
}
 
void* allocate_rev(size_t size){
	void* ptr = memPtr;
	return (void*)((ptr+(MAXSIZE))-(size)-(size*(referenceList.size)));
} 

void mark()
{
	currentMark++;
	Reference* ref = referenceList.head;
	while(ref)
	{
		Object* obj = ref->value;
		if(logging)
			printf("Marking block between %p and %p\n", obj->startAddrs, obj->endAddr);
		if(((*(obj->varAddr))!=NULL) && (obj->mark!=currentMark))
		{
			obj->mark = currentMark;
			if(logging)
				printf("Successfully Marked block between %p and %p\n", obj->startAddrs, obj->endAddr);
		}
		
		
		ref = ref->next;
		
	}
}
void sweep(){
	/*Reference* ref = referenceList.head;
	Object* obj = ref->value;
	if(obj->mark!=currentMark){
		referenceList.head = ref->next;
		referenceList.size--;
		if(logging)
			printf("freeing head block between %p and %p\n",obj->startAddrs, obj->endAddr);
		if(freeList.head==NULL){
			ref->next = NULL;
			freeList.head = ref;
			freeList.size++;
		}
		else{
			ref->next = freeList.head;
			freeList.head = ref;
			freeList.size++;
		}
		if(logging)
		{
			printf("Added to free list...\n");
			printf("%ld bytes freed",((obj->endAddr)-(obj->startAddrs)));
		}
	}*/
	
	int refListSize = 0;
	int refListSizePostDelete = -1;
	while(refListSize!=refListSizePostDelete)
	{
		refListSize = referenceList.size;
		referenceList.head = deleteRef(referenceList.head);
		refListSizePostDelete = referenceList.size;
	}
		
}

Reference* deleteRef(Reference* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	if((head->value->mark)!=currentMark)
	{
		Reference* tmpRef;
		tmpRef = head->next;
		//add to free list
		if(freeList.head==NULL){
			head->next = NULL;
			freeList.head = head;
			freeList.size++;
		}
		else{
			head->next = freeList.head;
			freeList.head = head;
			freeList.size++;
		}
		referenceList.size--;
		return tmpRef;
	}
	head->next = deleteRef(head->next);
	return head;
}




void collect()
{
	mark();
	sweep();
}

void printFreeList()
{
	printf(".............displaying free list................\n");
	if(freeList.head!=NULL)
	{
		printf("freeList size=%d\n",freeList.size);
		Reference* ref = freeList.head;
		while(ref){
			Object* obj = ref->value;
			printf("mark=%d\n",obj->mark);
			printf("start address=%p\n",obj->startAddrs);
			printf("end address=%p\n",obj->endAddr);
			int diff = (obj->endAddr) - (obj->startAddrs);
			printf("diff=%d\n",diff);
			if((*(obj->varAddr))==NULL)
				printf("obj is free\n");
			else
				printf("obj is not free\n");
			ref = ref->next;
		}
		/*while(ref!=NULL)
		{
			Object* obj = ref->value;
			printf("mark=%d\n",obj->mark);
			printf("start address=%p\n",obj->startAddrs);
			printf("end address=%p\n",obj->endAddr);
			int diff = (obj->endAddr) - (obj->startAddrs);
			printf("diff=%d\n",diff);
			if((*(obj->varAddr))==NULL)
				printf("obj is free\n");
			else
				printf("obj is not free\n");
			ref = ref->next;
		}*/
	}
}

void printRefList()
{
	if(referenceList.head!=NULL)
	{
		printf("refList size=%d\n",referenceList.size);
		Reference* ref = referenceList.head;
		while(ref!=NULL)
		{
			Object* obj = ref->value;
			printf("mark=%d\n",obj->mark);
			printf("start address=%p\n",obj->startAddrs);
			printf("end address=%p\n",obj->endAddr);
			int diff = (obj->endAddr) - (obj->startAddrs);
			printf("diff=%d\n",diff);
			if((*(obj->varAddr))==NULL)
				printf("obj is free\n");
			else
				printf("obj is not free\n");
			ref = ref->next;
		}
	}
} 

