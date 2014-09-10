#include "AMDx86-64CORE.hpp"
    
	//Expand upon this later.
	
	enum ModRMDecType
	{
	  DEC_BYTE, DEC_WORD, DEC_DWORD, DEC_QWORD, DEC_MM, DEC_XMM, DEC_YMM, DEC_SEG, DEC_CR, DEC_DR, MEM
	};
	
	struct ModRMDecInfo
	{
	  ModRMDecType srctype, dsttype; 
	};
	
	struct AMDcpu
	{
	  Register_List reglist;
	  //Leave return type void for now. Determine format for decoded op information later.
	  void DecodeOp();
	  
	  ModRM DecodeModRM(uBYTE modrm, ModRMDecInfo decinfo)
	  {
	    ModRM res;
	    //Add actual decoding here.
	    return res;
	  }
	};
	
	AMDcpu cpu;
