
#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct {
    unsigned char *data;
    int num_blocks;
} bitmap_t;

struct volumeControlBlock {
char fName[16];
uint32_t signature; // check if initialize is needed

uint32_t blockSize; // Size of each block in bytes
uint32_t totalBlocks; // Total number of blocks in FS
uint32_t totalBlocksByte; // convert number of blocks to bytes in the volume
uint32_t freeBlockCount; // Number of currently unused blocks in FS


uint32_t rDBlockNum; // Block number for the root directory
uint32_t totalFiles; // Total number of files in the FS
uint64_t totalFileSize; // Total size of all files in FS

bitmap_t bitmap;

}volumeControlBlock;

void init_vcb(volumeControlBlock *vcb, int blockSize, int totalBlocks) {
    strncpy(vcb->signature, "MyFILES", 16); // check sig
    vcb->blockSize = blockSize;
    vcb->totalBlocks = totalBlocks;
    init_bitmap(&vcb->bitmap, totalBlocks);
}

void init_bitmap(bitmap_t *bitmap, int numBlocks) {

    int numBytes = numBlocks / 8;
    if (numBlocks % 8 != 0) {
        numBytes++;
    }
    bitmap->data = malloc(numBytes);
    bitmap->num_blocks = numBlocks;
}