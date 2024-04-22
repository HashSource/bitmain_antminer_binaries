
/* WARNING: Unknown calling convention */

void CheckChainTempTooLowFlag(void)

{
  bool bVar1;
  _Bool isSomeBoardNotTooLow;
  int i;
  
  bVar1 = false;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (chain_temp_toolow[i] == 0)) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    for (i = 0; i < 0x10; i = i + 1) {
      if (dev->chain_exist[i] == 1) {
        chain_temp_toolow[i] = 0;
      }
    }
  }
  return;
}

