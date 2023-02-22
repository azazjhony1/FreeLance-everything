#include "YOURCODEHERE.h"

/**********************************************************************
    Function    : lg2pow2
    Description : this help funciton for you to calculate the bit number
                  this function is not allowed to modify
    Input       : pow2 - for example, pow2 is 16
    Output      : retval - in this example, retval is 4
***********************************************************************/
unsigned int lg2pow2(uint64_t pow2)
{
  unsigned int retval = 0;
  while (pow2 != 1 && retval < 64)
  {
    pow2 = pow2 >> 1;
    ++retval;
  }
  return retval;
}

void setSizesOffsetsAndMaskFields(cache *acache, unsigned int size, unsigned int assoc, unsigned int blocksize)
{
  unsigned int localVAbits = 8 * sizeof(uint64_t *);
  if (localVAbits != 64)
  {
    fprintf(stderr, "Running non-portable code on unsupported platform, terminating. Please use designated machines.\n");
    exit(-1);
  }

  // YOUR CODE GOES HERE
  // Set the following fields in acache:
  // acache->numsets
  // acache->numways = assoc;
  // acache->blocksize = blocksize;
  // acache->numsets = size / (assoc * blocksize);
  // acache->numBitsForBlockOffset = lg2pow2(blocksize);
  // acache->numBitsForIndex = lg2pow2(acache->numsets);
  // acache->VAImask = (1 << acache->numBitsForBlockOffset) - 1;
  // acache->VATmask = (1 << (acache->numBitsForBlockOffset + acache->numBitsForIndex)) - 1;

  unsigned int numOfBlocks = size / blocksize;
  unsigned int indexSize = lg2pow2(numOfBlocks / assoc);

  acache->numways = assoc;
  acache->blocksize = blocksize;
  acache->numsets = numOfBlocks / assoc;
  acache->numBitsForBlockOffset = lg2pow2(blocksize);
  acache->numBitsForIndex = acache->numBitsForBlockOffset + indexSize;

  unsigned int n = 0;
  acache->VAImask = 0;
  n = acache->numsets;
  while (n >>= 1)
    ++acache->VAImask;
  acache->VAImask = (1 << acache->VAImask) - 1;
  acache->VATmask = ~(0);
}

unsigned long long getindex(cache *acache, unsigned long long address)
{
  int i;
  for (i = 0; i < acache->numBitsForBlockOffset; i++)
  {
    address = address >> 1;
  }

  return address & acache->VAImask;
}

unsigned long long gettag(cache *acache, unsigned long long address)
{
  int i;
  for (i = 0; i < acache->numBitsForIndex; i++)
  {
    address = address >> 1;
  }

  return address & acache->VATmask;
}

void writeback(cache *acache, unsigned int index, unsigned int oldestway)
{
  unsigned long long address = 0;
  unsigned long long tag = 0;
  const int word_size = 8;
  tag = acache->sets[index].blocks[oldestway].tag;
  address = (tag << acache->numBitsForIndex) + (index << acache->numBitsForBlockOffset);

  int i;
  for (i = 0; i < (acache->blocksize / word_size); i++)
  {
    performaccess(acache->nextcache, (word_size * i + address), 8, 1, acache->sets[index].blocks[oldestway].datawords[i], i);
  }
}

void fill(cache *acache, unsigned int index, unsigned int oldestway, unsigned long long address)
{

  // YOUR CODE GOES HERE
  unsigned long long base_address = (address / acache->blocksize) * acache->blocksize;
  unsigned long long value = 0;
  const int word_size = 8;
  int i;
  for (i = 0; i < (acache->blocksize / word_size); i++)
  {
    value = performaccess(acache->nextcache, (word_size * i + base_address), 8, 0, 0, i);
    acache->sets[index].blocks[oldestway].datawords[i] = value;
  }
}
