#include "BitArray.h"

#include <cassert>

BitArray::Bit::Bit (int i, char *data)
  : i(i), data(data) {}

BitArray::Bit::operator bool () const
{
  return ((*data) & (1 << i));
}

BitArray::Bit BitArray::Bit::operator = (bool val)
{
  if (val) {
    *data |= 1 << i;
  }
  else {
    *data &= ~(char)(1 << i);
  }
  return *this;
}

BitArray::BitArray (int num_bits) : len_ (num_bits) {
  this->array = new char [num_bits]();
}

BitArray::~BitArray ()
{
  delete [] this->array;
}

BitArray::Bit BitArray::operator [] (int i)
{
  assert (i/8 < len_);
  
  int byte_idx = i / 8;
  int bit_idx = i % 8;
  Bit bit (bit_idx, &array[byte_idx]);
  return bit;
}

int BitArray::len () const
{
  return len_;
}
