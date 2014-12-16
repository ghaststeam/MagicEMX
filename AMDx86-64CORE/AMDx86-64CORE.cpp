#include "AMDx86-64CORE.hpp"
#include <string>
    
	//Expand upon this later.
	
	enum ModRMDecType
	{
	  DEC_GPR, DEC_MM, DEC_XMM, DEC_YMM, DEC_SEG, DEC_CR, DEC_DR, REGMEM, MEM, IMM
	};

	enum CPUMode
	{
		RM16, RM32, VM16, VM16E0, VM16E1, PM16, PM32, CM16, CM32, PM64
	};

	enum CPUSegs
	{
		ES, CS, SS, DS, FS, GS, INVALID, DEFAULTSEG = 8;
	};

	struct OperandInfo
	{
		int bits;
		bool hl; //High or low byte. Only applies with 8-bit register operands.
		ModRMDecType type;
		int reg;
		int memseg; //index into segs and segdescs arrays
		uQUAD memoff;
		uQUAD immval;
	};

	struct OpInfo
	{
		OperandInfo src1, src2, dst;
		uBYTE rex;
		int addrbits;
		std::string op;
	};

	struct AMDcpu
	{
	  Register_List reglist;

		CPUMode DecodeCPUMode()
		{
			if(reglist.EFER & 0x0000000000000400) //Checking EFER.LMA
			{
				//We're in long mode.
				if(reglist.segdescs[1].flags & 2) return PM64; //Checking CS.ar.L
				else
				{
					if(reglist.segdescs[1].flags & 4) return CM32; //Checking CS.ar.D
					else return CM16;
				}
			}
			else
			{
				if(reglist.CR[0] & 1) //Checking CR0.PE
				{
					//We're in protected mode.
					if(reglist.RFLAGS & 0x0000000000020000) //Checking RFLAGS.VM
					{
						if(reglist.CR[4] & 1) //Checking CR4.VME
						{
							//TODO: FIX THIS
							return VM16;
						}
						else return VM16;
					}
					else
					{
						if(reglist.segdescs[1].flags & 4) return PM32; //Checking CS.ar.D
						else return PM16;
					}
				}
				else
				{
					if(reglist.segdescs[1].flags & 4) return RM32; //Checking CS.ar.D
					else return RM16;
				}
			}
		}

		int DefaultOpSize()
		{
			if(reglist.EFER & 0x0000000000000400) //Checking EFER.LMA
			{
				//We're in long mode.
				if(reglist.segdescs[1].flags & 2) return 64; //Checking CS.ar.L
				else
				{
					if(reglist.segdescs[1].flags & 4) return 32; //Checking CS.ar.D
					else return 16;
				}
			}
			else
			{
				if(reglist.CR[0] & 1) //Checking CR0.PE
				{
					//We're in protected mode.
					if(reglist.RFLAGS & 0x0000000000020000) //Checking RFLAGS.VM
					{
						return 16
					}
					else
					{
						if(reglist.segdescs[1].flags & 4) return 32; //Checking CS.ar.D
						else return 16;
					}
				}
				else
				{
					if(reglist.segdescs[1].flags & 4) return 32; //Checking CS.ar.D
					else return 16;
				}
			}
		}

		void DecodeModRM16(OpInfo* info)
		{
			uBYTE modrm;

			reglist.RIP++;

			OperandInfo* regmem = (info->src1.type == REGMEM) ? &info->src1 : &info->dst;
			OperandInfo* reg = (info->src1.type == REGMEM) ? &info->dst : &info->src1;
			
			reg->reg = (modrm >> 3) & 7;
			if(reg->bits == 8)
			{
				reg->reg &= 3;
				if(modrm & 0x20) reg->hl = true;
				else reg->hl = false;
			}
			switch(modrm >> 6)
			{
				case 0:
				{
					switch(modrm & 7)
					{
						case 0:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[6].w;
							break;
						}
						case 1:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[7].w;
							break;
						}
						case 2:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[6].w;
							break;
						}
						case 3:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[7].w;
							break;
						}
						case 4:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[6].w;
							break;
						}
						case 5:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[7].w;
							break;
						}
						case 6:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = tmp;
							break;
						}
						case 7:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w;
							break;
						}
					}
					break;
				}
				case 1:
				{
					sBYTE tmp;
					reglist.RIP++;
					switch(modrm & 7)
					{
						case 0:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[6].w + tmp;
							break;
						}
						case 1:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[7].w + tmp;
							break;
						}
						case 2:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[6].w + tmp;
							break;
						}
						case 3:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[7].w + tmp;
							break;
						}
						case 4:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[6].w + tmp;
							break;
						}
						case 5:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[7].w + tmp;
							break;
						}
						case 6:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + tmp;
							break;
						}
						case 7:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + tmp;
							break;
						}
					}
					break;
				}
				case 2:
				{
					sWORD tmp;
					reglist.RIP+=2;
					switch(modrm & 7)
					{
						case 0:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[6].w + tmp;
							break;
						}
						case 1:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + reglist.R[7].w + tmp;
							break;
						}
						case 2:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[6].w + tmp;
							break;
						}
						case 3:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + reglist.R[7].w + tmp;
							break;
						}
						case 4:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[6].w + tmp;
							break;
						}
						case 5:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[7].w + tmp;
							break;
						}
						case 6:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = SS;
							regmem->memoff = reglist.R[5].w + tmp;
							break;
						}
						case 7:
						{
							if(regmem->memseg == DEFAULTSEG) regmem->memseg = DS;
							regmem->memoff = reglist.R[3].w + tmp;
							break;
						}
					}
					break;
				}
				case 3:
				{
					regmem->type = DEC_GPR;
					regmem->reg = modrm & 7;
					if(regmem->bits == 8)
					{
						regmem->reg &= 3;
						if(modrm & 4) regmem->hl = true;
						else regmem->hl = false;
					}
					break;
				}
			}
		}

		void DecodeModRm64(OpInfo* info) //TODO
		{
			uBYTE modrm;
			
			reglist.RIP++;

			OperandInfo* regmem = (info->src1.type == REGMEM) ? &info->src1 : &info->dst;
			OperandInfo* reg = (info->src1.type == REGMEM) ? &info->dst : &info->src1;

			
		}

		void DecodeModRM(OpInfo* info)
		{
			switch(DecodeCPUMode())
			{
				case RM16:
				case RM32: //?
				case PM16:
				case CM16:
				{
					DecodeModRM16(info);
					break;
				}
				default:
				{
					DecodeModRM64(info);
					break;
				}
			}
		}

	  OpInfo DecodeOp()
		{
			OpInfo res;
			uBYTE op1; //TODO: Assign the first opcode byte to op1.
			
			reglist.RIP++;

			res.src1.memseg = DEFAULTSEG;
			res.dst.memseg = DEFAULTSEG;

			switch(op1) //TODO: Reassign op1 at the end of each prefix.
			{
				case 0x40 ... 0x4f:
				{
					res.rex = op1 & 0x0f;
					reglist.RIP++;
					break;
				}
			}

			switch(op1)
			{
				case 0x00:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = 8;
					res.dst.type = REGMEM;
					res.dst.bits = 8;
					res.op = "ADD";
					DecodeModRM(&res);
					break;
				}
				case 0x01:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = DefaultOpSize();
					res.dst.type = REGMEM;
					res.dst.bits = DefaultOpSize();
					res.op = "ADD";
					DecodeModRM(&res);
					break;
				}
				case 0x02:
				{
					res.src1.type = REGMEM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "ADD";
					DecodeModRM(&res);
					break;
				}
				case 0x03:
				{
					res.src1.type = REGMEM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "ADD";
					DecodeModRM(&res);
					break;
				}
				case 0x04:
				{
					res.src1.type = IMM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "ADD";
					break;
				}
				case 0x05:
				{
					res.src1.type = IMM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "ADD";
					break;
				}
				case 0x06:
				{
					if(DecodeCPUMode() != PM64)
					{
						res.src1.reg = 0;
						res.op = "PUSH";
					}
					else res.op = "INVALID";
					break;
				}
				case 0x07:
				{
					if(DecodeCPUMode() != PM64)
					{
						res.src1.reg = 0;
						res.op = "POP";
					}
					else res.op = "INVALID";
					break;
				}
				case 0x08:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = 8;
					res.dst.type = REGMEM;
					res.dst.bits = 8;
					res.op = "OR";
					DecodeModRM(&res);
					break;
				}
				case 0x09:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = DefaultOpSize();
					res.dst.type = REGMEM;
					res.dst.bits = DefaultOpSize();
					res.op = "OR";
					DecodeModRM(&res);
					break;
				}
				case 0x0a:
				{
					res.src1.type = REGMEM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "OR";
					DecodeModRM(&res);
					break;
				}
				case 0x0b:
				{
					res.src1.type = REGMEM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "OR";
					DecodeModRM(&res);
					break;
				}
				case 0x0c:
				{
					res.src1.type = IMM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "OR";
					break;
				}
				case 0x0d:
				{
					res.src1.type = IMM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "OR";
					break;
				}
				case 0x0e:
				{
					if(DecodeCPUMode != PM64)
					{
						res.src1.reg = 1;
						res.op = "PUSH";
					}
					else res.op = "INVALID";
					break;
				}
				case 0x0f:
				{
					uBYTE op2; //TODO: Memory interface needs work.
					switch(op2)
					{
						case 0x02:
						{
							res.src1.type = REGMEM;
							res.src1.bits = 16;
							res.dst.type = DEC_GPR;
							res.dst.bits = DefaultOpSize();
							res.op = "LAR";
							break;
						}
						case 0x03:
						{
							res.src1.type = REGMEM;
							res.src1.bits = 16;
							res.dst.type = DEC_GPR;
							res.dst.bits = DefaultOpSize();
							res.op = "LSL";
							break;
						}
						case 0x06:
						{
							res.op = "CLTS";
							break;
						}
						case 0x08:
						{
							res.op = "INVD";
							break;
						}
						case 0x09:
						{
							res.op = "WBINVD";
							break;
						}
						case 0x0B:
						{
							res.op = "UD1";
							break;
						}
					}
					break;
				}
				case 0x10:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = 8;
					res.dst.type = REGMEM;
					res.dst.bits = 8;
					res.op = "ADC";
					DecodeModRM(&res);
					break;
				}
				case 0x11:
				{
					res.src1.type = DEC_GPR;
					res.src1.bits = DefaultOpSize();
					res.dst.type = REGMEM;
					res.dst.bits = DefaultOpSize();
					res.op = "ADC";
					DecodeModRM(&res);
					break;
				}
				case 0x12:
				{
					res.src1.type = REGMEM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "ADC";
					DecodeModRM(&res);
					break;
				}
				case 0x13:
				{
					res.src1.type = REGMEM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "ADC";
					DecodeModRM(&res);
					break;
				}
				case 0x14:
				{
					res.src1.type = IMM;
					res.src1.bits = 8;
					res.dst.type = DEC_GPR;
					res.dst.bits = 8;
					res.op = "ADC";
					break;
				}
				case 0x15:
				{
					res.src1.type = IMM;
					res.src1.bits = DefaultOpSize();
					res.dst.type = DEC_GPR;
					res.dst.bits = DefaultOpSize();
					res.op = "ADC";
					break;
				}
				case 0x16:
				{
					if(DecodeCPUMode != PM64)
					{
						res.src1.reg = 2;
						res.op = "PUSH";
					}
					else res.op = "INVALID";
					break;
				}
				case 0x17:
				{
					if(DecodeCPUMode != PM64)
					{
						res.src1.reg = 2;
						res.op = "POP";
					}
					else res.op = "INVALID";
					break;
				}
			}

			return res;
		}
	};
	
	AMDcpu cpu;
