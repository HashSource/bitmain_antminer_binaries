
void DownFreqAccordingToHashrate(void)

{
  int iVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_14;
  
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    if (*(int *)(cgpu + (local_14 + 0x9c638) * 4) == 1) {
      iVar1 = getBoardLimitedHashrateByVoltage(local_14);
      iVar2 = GetBoardRate(local_14);
      if (iVar1 <= iVar2) {
        if (3 < log_level) {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            uVar5 = *(undefined4 *)(chain_vol_value + local_14 * 4);
            uVar4 = GetBoardRate(local_14);
            fprintf(pFVar3,"%s:%d: chain[%d] voltage value=%d hashrate=%d >= %d need down freq!\n",
                    "main.c",0x35d2,local_14,uVar5,uVar4,iVar1);
          }
          fclose(pFVar3);
        }
        ProcessFixBoardFreqForChips(local_14,iVar1);
        if (3 < log_level) {
          pFVar3 = fopen(log_file,"a+");
          if (pFVar3 != (FILE *)0x0) {
            uVar5 = *(undefined4 *)(chain_vol_value + local_14 * 4);
            uVar4 = GetBoardRate(local_14);
            fprintf(pFVar3,"%s:%d: chain[%d] voltage value=%d fixed hashrate=%d\n","main.c",0x35d6,
                    local_14,uVar5,uVar4);
          }
          fclose(pFVar3);
        }
      }
    }
  }
  return;
}

