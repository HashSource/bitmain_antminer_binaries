
void ProcessFixBoardFreqForChips(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = GetBoardRate(param_1);
  while (param_2 <= iVar1) {
    BoardDownOneChipFreqOneStep(param_1);
    iVar1 = GetBoardRate(param_1);
  }
  return;
}

