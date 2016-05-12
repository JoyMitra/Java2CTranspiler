#define MAXSIZE 512*1024*1024
#define logging 0

unsigned char currentMark;
typedef struct sReference Reference;
typedef struct sRefList RefList;
typedef struct sObject Object;

void* memory();
void* allocate(size_t size);
void* allocate_rev(size_t size);
void* gc_malloc(size_t size,void** var);
void ref_add(Object* ptr);
void mark();
void sweep();
Reference* deleteRef(Reference* head);
void collect();
void printFreeList();
void printRefList();




struct sReference {
 Reference* next;
 Object* value;		//pointer to the first part of a block 
};

struct sRefList {
 int size;
 Reference* head;
};

struct sObject {
 unsigned char mark;
 void* startAddrs;
 void* endAddr;
 void** varAddr;
};