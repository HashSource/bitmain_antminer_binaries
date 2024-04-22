
void ProcessFixFreqForChips(int param_1)

{
  int iVar1;
  
  iVar1 = GetTotalRate();
  while (param_1 <= iVar1) {
    DownOneChipFreqOneStep();
    iVar1 = GetTotalRate();
  }
  return;
}

