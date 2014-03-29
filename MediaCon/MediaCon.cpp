struct MediaCon
{
  void CPU_Init(short &counterbase);
  void HLT_PRL(int &threadbase, void*);
  void ChangeMode();
  void FetchOp();
}; MediaCon MC;
