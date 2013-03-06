/*
	kdmem.h : Dynamic memory allocation.
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#ifndef KDMEM_H
#define KDMEM_H
#include <sys/types.h>

/* reserved list size */
/* NOTE: 131072 allocations are possible per MiB */
#define KDMEM_RESV 0x100000 /* 1MiB */
#define KDMEM_ST 0xC0000000 /* virtual start address */
#define KDMEM_SIZ 0x4000000 /* 64MiB */

/* memory block structure */
typedef struct
{
	Uint32 start;
	Uint32 end;
} memblk_t;

/* reserve a memory area */
Uint32 kdalloc_global( Uint32 sz, Uint8 alg, Uint32 *phys ); /* generic */
Uint32 kdalloc( Uint32 sz ); /* vanilla */
Uint32 kdalloc_a( Uint32 sz ); /* page-aligned */
Uint32 kdalloc_p( Uint32 sz, Uint32 *phys ); /* return physical address */
Uint32 kdalloc_ap( Uint32 sz, Uint32 *phys ); /* page-aligned and return physical address */
/* reallocate (resize) a memory area */
Uint32 kdrealloc_global( Uint32 prev, Uint32 sz, Uint8 alg, Uint32 *phys ); /* generic */
Uint32 kdrealloc( Uint32 prev, Uint32 newsz ); /* vanilla */
Uint32 kdrealloc_a( Uint32 prev, Uint32 newsz ); /* page-aligned */
Uint32 kdrealloc_p( Uint32 prev, Uint32 newsz, Uint32 *phys ); /* return physical address */
Uint32 kdrealloc_ap( Uint32 prev, Uint32 newsz, Uint32 *phys ); /* page-aligned and return physical address */
/* free a memory area */
void kdfree( Uint32 a );
/* retrieve used blocks */
Uint32 kdmem_count( void );
/* retrieve total memory used */
Uint32 kdmem_amount( void );
/* initialize dynamic memory allocator */
void kdmem_init( Uint32 start, Uint32 size, Uint32 psize );

#endif