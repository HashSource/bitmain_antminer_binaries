
void print_freq_table(int *param_1)

{
  FILE *pFVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r1_00;
  int local_1c;
  int local_18;
  int local_14;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: print_freq_table...\n","board_frq_tuning.c",0x4ba);
    }
    fclose(pFVar1);
  }
  for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
    if ((*(int *)(cgpu + (local_14 + 0x9c638) * 4) != 0) &&
       ((iVar2 = is_S9_Hydro(), iVar2 == 0 ||
        (iVar2 = get_board_index_S9_Hydro(local_14,0), iVar2 == local_14)))) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain[%d]:\n",local_14);
        }
        fclose(pFVar1);
      }
      for (local_18 = 0; local_18 < *param_1; local_18 = local_18 + 1) {
        iVar2 = is_S9_Hydro();
        if (iVar2 == 0) {
          local_1c = local_18;
        }
        else if (local_14 % 3 == 0) {
          local_1c = local_14 / 3;
        }
        else if (local_14 % 3 == 1) {
          local_1c = (local_14 + -1) / 3 + 0x54;
        }
        else if (local_14 % 3 == 2) {
          local_1c = (local_14 + -2) / 3 + 0xa8;
        }
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            iVar2 = atoi(*(char **)(freq_pll_1385 + param_1[local_1c + local_14 * 0x100 + 2] * 0x10)
                        );
            fprintf(pFVar1,"Freq%02d=%03d  ",local_18,iVar2);
          }
          fclose(pFVar1);
        }
        __aeabi_idivmod(local_18 + 1,param_1[1] * 3);
        if (extraout_r1 == 0) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fputc(10,pFVar1);
            }
            fclose(pFVar1);
          }
        }
        else {
          __aeabi_idivmod(local_18 + 1,param_1[1]);
          if ((extraout_r1_00 == 0) && (3 < log_level)) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fwrite(&DAT_0012dad0,1,3,pFVar1);
            }
            fclose(pFVar1);
          }
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
    }
  }
  return;
}

