
void BoardDownOneChipFreqOneStep(int param_1)

{
  FILE *pFVar1;
  int local_14;
  int local_10;
  int local_c;
  
  local_10 = 0;
  local_14 = -1;
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    if ((local_10 == 0) ||
       (local_10 < *(int *)(last_success_freq + (local_c + param_1 * 0x100) * 4))) {
      local_14 = local_c;
      local_10 = *(int *)(last_success_freq + (local_c + param_1 * 0x100) * 4);
    }
  }
  if (local_14 < 0) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d: Fatal Error: BoardDownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n"
                ,"main.c",0x1bf9,param_1,local_14);
      }
      fclose(pFVar1);
    }
    do {
      sleep(1);
    } while( true );
  }
  if (local_10 < 5) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d: Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n"
                ,"main.c",0x1c00,param_1);
      }
      fclose(pFVar1);
    }
    do {
      sleep(1);
    } while( true );
  }
  *(int *)(last_success_freq + (local_14 + param_1 * 0x100) * 4) =
       *(int *)(last_success_freq + (local_14 + param_1 * 0x100) * 4) + -1;
  *(char *)(param_1 * 0x80 + local_14 + 0x1a3fbbe) =
       (char)*(undefined4 *)(last_success_freq + (local_14 + param_1 * 0x100) * 4);
  return;
}

