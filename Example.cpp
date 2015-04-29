#include "BitArray.h"

#include <iostream>

using namespace std;

int main ()
{
  BitArray odds (20);

  for (int i = 0; i < 20; ++i)
    odds [i] = (i % 2 == 1);    // Setting

  for (int i = 0; i < 20; ++i)
    if (odds [i])               // getting
      cout << i << " is odd." << endl;
    else
      cout << i << " is even." << endl;

  return 0;
}
