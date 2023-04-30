#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>


typedef struct entry {
char fName[256]; // for files to be identified in FS, max length: 255 characters

uint64_t fSize; // size of file
uint64_t location; // location of file on the disk


time_t cTime; // creation time, will be formatted using localtime()
time_t mTime; // modified time, will be formatted using localtime()

} entry;