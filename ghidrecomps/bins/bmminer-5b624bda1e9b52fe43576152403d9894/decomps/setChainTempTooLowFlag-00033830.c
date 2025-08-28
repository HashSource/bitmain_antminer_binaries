
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void setChainTempTooLowFlag(void)

{
  all_parameters *paVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char logstr [256];
  
  iVar4 = 0;
  piVar5 = chain_temp_toolow;
  do {
    paVar1 = dev;
    *piVar5 = 0;
    if ((paVar1->chain_exist[iVar4] == 1) &&
       (iVar3 = (int)paVar1->chain_asic_maxtemp[iVar4][1], 0 < iVar3)) {
      iVar2 = lowest_testOK_temp[iVar4];
      if (iVar2 < 1) {
        if (iVar3 < 0x50) {
          sprintf(logstr,"Detect Chain[%d] temp too low, will ignore: temp=%d\n",iVar4);
          writeLogFile(logstr);
          *piVar5 = 1;
        }
      }
      else if (iVar3 < iVar2) {
        sprintf(logstr,"Detect Chain[%d] temp too low, will ignore: temp=%d < %d\n",iVar4,iVar3,
                iVar2);
        writeLogFile(logstr);
        *piVar5 = 1;
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar4 != 0x10);
  CheckChainTempTooLowFlag();
  return;
}

