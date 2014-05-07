#include <fstream>
#include "/PS4EMX/AMDx86-64CORE/AMDx86-64.hpp"
using namespace std;
struct get
{
  short &addrm;
  const char* OPMOD[] = operand[];
  uBYTE OpcodeSz; 
  long Downsize;
  long CPU_CYCLES = 10000 / Downsize;
  int Cur_Cyc = Downsize / CPU_CYCLES + 17000;
} GET;
class FetchOpcode
{
public:
FetchOpcode(short inSz, short AdrM);
void Addressing();

} FO;
FO::FetchOpcode(GET.OpcodeSz, GET.addrm)
{
for(short i = 0; i < GET.Cur_Cyc; i++)
{
  
}
}
