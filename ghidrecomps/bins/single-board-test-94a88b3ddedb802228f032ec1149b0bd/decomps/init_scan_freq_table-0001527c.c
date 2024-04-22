
void init_scan_freq_table(int param_1,int param_2)

{
  FILE *pFVar1;
  int iVar2;
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          iVar2 = atoi(*(char **)(freq_pll_1385 + *(int *)(param_1 + (local_c + 0x15012) * 4) * 0x10
                                 ));
          fprintf(pFVar1,"%s:%d: chain[%d] original freq = %d, freq_index = %d\n",
                  "board_frq_tuning.c",0x413,local_c,iVar2,
                  *(undefined4 *)(param_1 + (local_c + 0x15012) * 4));
        }
        fclose(pFVar1);
      }
      *(int *)(param_1 + (local_c + 0x15012) * 4) =
           *(int *)(param_1 + (local_c + 0x15012) * 4) + param_2;
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          iVar2 = atoi(*(char **)(freq_pll_1385 + *(int *)(param_1 + (local_c + 0x15012) * 4) * 0x10
                                 ));
          fprintf(pFVar1,"%s:%d: chain[%d] set freq to %d, freq_index = %d\n","board_frq_tuning.c",
                  0x415,local_c,iVar2,*(undefined4 *)(param_1 + (local_c + 0x15012) * 4));
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

