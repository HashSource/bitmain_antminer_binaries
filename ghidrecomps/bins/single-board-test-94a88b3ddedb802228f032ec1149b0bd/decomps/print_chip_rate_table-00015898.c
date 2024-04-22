
void print_chip_rate_table(int *param_1)

{
  FILE *pFVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: print_chip_rate_table...\n","board_frq_tuning.c",0x497);
    }
    fclose(pFVar1);
  }
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
       ((iVar2 = is_S9_Hydro(), iVar2 == 0 ||
        (iVar2 = get_board_index_S9_Hydro(local_c,0), iVar2 == local_c)))) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"chain[%d]:\n",local_c);
        }
        fclose(pFVar1);
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fwrite("Frq Vol",1,7,pFVar1);
        }
        fclose(pFVar1);
      }
      for (local_14 = 0; local_14 < *param_1; local_14 = local_14 + 1) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"  Asic%02d",local_14 + 1);
          }
          fclose(pFVar1);
        }
      }
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fputc(10,pFVar1);
        }
        fclose(pFVar1);
      }
      local_10 = 0;
      while (param_1[local_c * 0x14 + local_10 + 0x15022] != 0) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            iVar2 = atoi(*(char **)(freq_pll_1385 +
                                   param_1[local_c * 0x14 + local_10 + 0x15022] * 0x10));
            fprintf(pFVar1,"%03d %03d",iVar2,param_1[local_c + 0x15002]);
          }
          fclose(pFVar1);
        }
        for (local_14 = 0; local_14 < *param_1; local_14 = local_14 + 1) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1," %7d",param_1[local_14 + (local_c * 0x14 + local_10) * 0x100 + 0x1002]
                     );
            }
            fclose(pFVar1);
          }
        }
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fputc(10,pFVar1);
          }
          fclose(pFVar1);
        }
        local_10 = local_10 + 1;
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

