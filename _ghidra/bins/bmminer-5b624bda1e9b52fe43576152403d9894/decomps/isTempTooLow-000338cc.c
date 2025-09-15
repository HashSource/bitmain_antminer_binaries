
/* WARNING: Unknown calling convention */

_Bool isTempTooLow(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  all_parameters *paVar4;
  int iVar5;
  char logstr [256];
  
  iVar1 = 0;
  iVar2 = 0;
  paVar4 = dev;
  do {
    if (((*(int *)((int)dev->chain_exist + iVar1) == 1) &&
        (*(int *)((int)chain_temp_toolow + iVar1) == 0)) &&
       (iVar5 = (int)paVar4->chain_asic_temp[0][1][1], 0 < iVar5)) {
      iVar3 = *(int *)((int)lowest_testOK_temp + iVar1);
      if (iVar3 < 1) {
        if (iVar5 < 0x50) {
          sprintf(logstr,"Detect temp too low: Chain[%d] curtemp=%d\n",iVar2,iVar5);
          writeLogFile(logstr);
          return true;
        }
      }
      else if (iVar5 < iVar3) {
        sprintf(logstr,"Detect temp too low: Chain[%d] lowest_testOK_temp=%d curtemp=%d\n",iVar2,
                iVar3,iVar5);
        writeLogFile(logstr);
        return true;
      }
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
    paVar4 = (all_parameters *)(paVar4->chain_exist + 0xe);
  } while (iVar1 != 0x40);
  return false;
}

