
/* WARNING: Unknown calling convention */

void ProcessFixFreqForChips(void)

{
  _Bool _Var1;
  int iVar2;
  int iVar3;
  int fixed_totalRate;
  int totalRate;
  int j;
  int i;
  
  iVar2 = GetTotalRate();
  iVar2 = ConvirtTotalRate(iVar2);
  iVar2 = (iVar2 * 0x65) / 100;
  iVar3 = GetTotalRate();
  if (iVar2 < iVar3) {
    do {
      for (i = 0; i < 0x10; i = i + 1) {
        if (dev->chain_exist[i] == 1) {
          for (j = 0; j < 0x6c; j = j + 1) {
            last_record_freq[i][j] = (uint)last_freq[i][j * 2 + 3];
          }
        }
      }
      _Var1 = DownOneChipFreqOneStep();
    } while ((_Var1) && (iVar3 = GetTotalRate(), iVar2 < iVar3));
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        for (j = 0; j < 0x6c; j = j + 1) {
          last_freq[i][j * 2 + 3] = (uchar)last_record_freq[i][j];
        }
      }
    }
  }
  return;
}

