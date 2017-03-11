#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

/* Page to evict is chosen using the fifo algorithm.
 * Returns the page frame number (which is also the index in the coremap)
 * for the page that is to be evicted.
 */
int fifo_evict() { 
	int idx; 
	int min; //tracing minimum value
	int i;  //cannot be initialized in for loop condition
	for(i = 0; i < memsize; i ++){  
		if(i == 0){ 
			min = coremap[i].howLong;
			idx = i;
		}
		if(coremap[i].howLong < min){
			min = coremap[i].howLong;
			idx = i;
		}
	}
	return idx; //The index where the frame 'generated' in the oldest time
}
/* This function is called on each access to a page to update any information
 * needed by the fifo algorithm.
 * Input: The page table entry for the page that is being accessed.
 */
void fifo_ref(pgtbl_entry_t *p) {
	return;
}

/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void fifo_init() {
}
