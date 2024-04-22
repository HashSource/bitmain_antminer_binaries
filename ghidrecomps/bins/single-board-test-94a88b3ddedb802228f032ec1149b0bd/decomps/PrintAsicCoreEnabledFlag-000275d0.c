
void PrintAsicCoreEnabledFlag(int param_1)

{
  char cVar1;
  FILE *pFVar2;
  int local_10;
  int local_c;
  
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: Chain[%d] Bad Core info:\n","main.c",0x8e4,param_1);
    }
    fclose(pFVar2);
  }
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 0x72; local_10 = local_10 + 1) {
      if (((*(int *)(asic_core_enabled_flag + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4)
            < 1) && (cVar1 = isDisabledChipCore(param_1,local_c,local_10), cVar1 != '\x01')) &&
         (3 < log_level)) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: ASIC[%d] Core[%d] is bad!\n","main.c",0x8ec,local_c,local_10);
        }
        fclose(pFVar2);
      }
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d: \n","main.c",0x8f0);
    }
    fclose(pFVar2);
  }
  return;
}

