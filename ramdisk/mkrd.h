/*
	mkrd.h : Create a simple ram disk for AOS.
	(C)2012-2013 Marisa Kirisame, UnSX Team.
	Part of AliceOS, the Alice Operating System.
	Released under the MIT License.
*/
#include <stdint.h>
/*
Layout of an AOS simple ramdisk
********
*HEADER*
********
|ENTRY|
|ENTRY|
|ENTRY|
|ENTRY|
|ENTRY|
|ENTRY|
| ... |
|ENTRY|
+-----+
xxxxxxxxx
xRAWDATAx
xxxxxxxxx
.TRAILER.
.........
Every ramdisk starts with a header, which contains:
 - a magic number, 0xFEEDCAFE (don't feed the ramdisk cafe, even if it asks)
 - the number of entries in the disk
Exactly right after that (no padding) the entries, one after another, all
packed up. Each entry contains:
 - name of file (256 characters)
 - starting offset in ramdisk where file starts
 - size of file in bytes
After all this, there's a BIG chunk of raw data
As a safeguard, at the end of the whole thing there's a trailer composed of:
 - a magic number, 0xADEADBED (beds can die too)
 - the null-terminated string "The Doll Maker of Bucuresti" (don't ask)
*/
/* magic and signatures */
#define AOSRD_HDMAGIC 0xFEEDCAFE
#define AOSRD_TRMAGIC 0xADEADBED
#define AOSRD_TRSIG "The Doll Maker of Bucuresti"
/* header */
#define RDHEAD_SIZ 8
typedef struct
{
	uint32_t magic;
	uint32_t numents;
} rd_header_t;
/* entry */
#define RDENT_SIZ 264
typedef struct
{
	char name[256];
	uint32_t start;
	uint32_t size;
} rd_entry_t;
