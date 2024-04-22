
void DownOneChipFreqOneStep(void)

{
  int iVar1;
  FILE *pFVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_1c = -1;
  local_c = 0;
  do {
    if (0xf < local_c) {
      if (local_1c < 0) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d: Fatal Error: DownOneChipFreqOneStep has Wrong chain index=%d\n",
                    "main.c",0x1ba2,local_1c);
          }
          fclose(pFVar2);
        }
        do {
          sleep(1);
        } while( true );
      }
      local_14 = 0;
      local_18 = -1;
      for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
        if ((local_14 == 0) ||
           (local_14 < *(int *)(last_success_freq + (local_c + local_1c * 0x100) * 4))) {
          local_18 = local_c;
          local_14 = *(int *)(last_success_freq + (local_c + local_1c * 0x100) * 4);
        }
      }
      if (local_18 < 0) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,
                    "%s:%d: Fatal Error: DownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n"
                    ,"main.c",0x1bb2,local_1c,local_18);
          }
          fclose(pFVar2);
        }
        do {
          sleep(1);
        } while( true );
      }
      if (local_14 < 5) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,
                    "%s:%d: Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n"
                    ,"main.c",0x1bb9,local_1c);
          }
          fclose(pFVar2);
        }
        do {
          sleep(1);
        } while( true );
      }
      *(int *)(last_success_freq + (local_18 + local_1c * 0x100) * 4) =
           *(int *)(last_success_freq + (local_18 + local_1c * 0x100) * 4) + -1;
      *(char *)(local_1c * 0x80 + local_18 + 0x1a3fbbe) =
           (char)*(undefined4 *)(last_success_freq + (local_18 + local_1c * 0x100) * 4);
      return;
    }
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) {
      if (local_10 != 0) {
        iVar1 = GetBoardRate(local_c);
        if (iVar1 <= local_10) goto LAB_0002bbec;
      }
      local_10 = GetBoardRate(local_c);
      local_1c = local_c;
    }
LAB_0002bbec:
    local_c = local_c + 1;
  } while( true );
}

