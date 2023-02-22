#include "YOURCODEHERE.h"

/**********************************************************************
    Function    : lg2pow2
    Description : this help funciton for you to calculate the bit number
                  this function is not allowed to modify
    Input       : pow2 - for example, pow2 is 16
    Output      : retval - in this example, retval is 4
***********************************************************************/

//This is function to take the log base 2 of a power of 2
unsigned int lg2pow2(uint64_t pow2)
{

  //declare unsigned int retval variable
  unsigned int retval = 0;

  //loop until pow2 is 1
  while (pow2 != 1 && retval < 64)
  {
    pow2 = pow2 >> 1;
    ++retval;
  }
  return retval;
}


//setSizesOffsetsAndMaskFields is a function to set the fields in the cache struct
void setSizesOffsetsAndMaskFields(cache *acache, unsigned int size, unsigned int assoc, unsigned int blocksize)
{

  //declaring localVAbits variable to store the size of a pointer in bits (64 bits) and check if it is 64 bits or not (if not, exit) 
  unsigned int localVAbits = 8 * sizeof(uint64_t *);
  if (localVAbits != 64)
  {
    fprintf(stderr, "Running non-portable code on unsupported platform, terminating. Please use designated machines.\n");
    exit(-1);
  }

  // YOUR CODE GOES HERE
  // Set the following fields in acache:
  // acache->numsets;
  // acache->numways = assoc;
  // acache->blocksize = blocksize;
  // acache->numsets = size / (assoc * blocksize);
  // acache->numBitsForBlockOffset = lg2pow2(blocksize);
  // acache->numBitsForIndex = lg2pow2(acache->numsets);
  // acache->VAImask = (1 << acache->numBitsForBlockOffset) - 1;
  // acache->VATmask = (1 << (acache->numBitsForBlockOffset + acache->numBitsForIndex)) - 1;

   // YOUR CODE GOES HERE

   //declaring numOfBlocks variable to store the number of blocks in the cache
  unsigned int numOfBlocks = size/blocksize;

  //declaring indexSize variable to store the number of bits needed to represent the index of the cache 
  unsigned int indexSize = lg2pow2(numOfBlocks/assoc);

  //setting the fields in acache to the appropriate values 
  acache->numways = assoc;
  acache->blocksize = blocksize;
  acache->numsets = numOfBlocks/assoc;
  acache->numBitsForBlockOffset = lg2pow2(blocksize);
  acache->numBitsForIndex = acache->numBitsForBlockOffset + indexSize;

  //declaring VAImask variable to store the mask for the index of the cache 
  unsigned int n = 0;
  acache->VAImask = 0;
  //loop to set the mask for the index of the cache 
  n = acache->numsets;
  while(n>>=1) ++acache->VAImask;
  //setting the mask for the index of the cache 
  acache->VAImask = (1<<acache->VAImask)-1;
  acache->VATmask = ~(0);

}

//getindex is a function to get the index of the cache 
unsigned long long getindex(cache* acache, unsigned long long address){

  //loop to shift the address to the right by the number of bits needed to represent the block offset 
  for (int i = 0; i < acache->numBitsForBlockOffset; i++){
    address = address >> 1;
  }
  //returning the index of the cache
  return address & acache->VAImask;
}

//gettag is a function to get the tag of the cache 
unsigned long long gettag(cache* acache, unsigned long long address){

  //loop to shift the address to the right by the number of bits needed to represent the block offset and the index 
  for (int i = 0; i < acache->numBitsForIndex; i++){

    //shifting the address to the right by 1 bit
    address = address >> 1;
  }
 //returning the tag of the cache 
  return address & acache->VATmask;

}

//writeback is a function to write back the data from the cache to the next level of the cache 
void writeback(cache* acache, unsigned int index, unsigned int oldestway){
  // YOUR CODE GOES HERE
  // Write back the data from the cache to the next level of the cache
  // use performaccess function to write back the data
  // use acache->nextcache to get the next level of the cache

  //declaring address variable to store the address of the data in the cache 
  unsigned long long address = 0;

  //declaring tag variable to store the tag of the data in the cache
  unsigned long long tag = 0;

  //declaring word_size variable to store the size of a word in the cache
  const int word_size = 8;

  //getting the tag of the data in the cache 
  tag = acache->sets[index].blocks[oldestway].tag;

  //getting the address of the data in the cache
  address = (tag << acache->numBitsForIndex) + (index << acache->numBitsForBlockOffset);

  //loop to write back the data from the cache to the next level of the cache 
  for(int i = 0; i < (acache->blocksize/word_size); i++){

    //calling the performaccess function to write back the data from the cache to the next level of the cache 
    performaccess(acache->nextcache, (word_size*i+address), 8, 1, acache->sets[index].blocks[oldestway].datawords[i], i);
  }
}


//fill is a function to fill the cache with the data from the next level of the cache 

void fill(cache * acache, unsigned int index, unsigned int oldestway, unsigned long long address){
   //YOUR CODE GOES HERE

   //declaring base_address variable to store the base address of the data in the cache and setting it to the address of the data in the cache 
  unsigned long long base_address = (address/acache->blocksize)*acache->blocksize;
  // Write the data from the next level of the cache to the cache and store it in the datawords array
  //declaring value variable to store the value of the data in the cache and setting it to 0
  unsigned long long value = 0;

  //declaring word_size variable to store the size of a word in the cache and setting it to 8 
  const int word_size = 8;

  //loop to write the data from the next level of the cache to the cache and store it in the datawords array 
  for(int i = 0; i < (acache->blocksize/word_size); i++){
    value = performaccess(acache->nextcache, (word_size*i+base_address), 8, 0, 0, i);
    acache->sets[index].blocks[oldestway].datawords[i]= value;
  }
}