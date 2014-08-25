#include "AMDx86-64.hpp"

struct AMDcpu
{
  Register_List reglist;
  //Leave return type void for now. Determine format for decoded op information later.
  void DecodeOp();
};

AMDcpu cpu;