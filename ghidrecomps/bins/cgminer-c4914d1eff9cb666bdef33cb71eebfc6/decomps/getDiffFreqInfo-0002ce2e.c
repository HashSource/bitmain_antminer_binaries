
void getDiffFreqInfo(char *infoStr)

{
  bool bVar1;
  _Bool _Var2;
  FILE *pFVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *infoStr_local;
  FILE *pFile_1;
  uint32_t *buf;
  FILE *pFile;
  uint32_t base_freq;
  uint32_t freq_tmp;
  uint32_t vol_tmp;
  _Bool is_chain_number_print;
  int retlen;
  int chip;
  int chain;
  
  retlen = 0;
  _Var2 = is_economic_mode();
  iVar5 = g_sweep_config_hpf.sweep_max_freq;
  if (_Var2) {
    iVar5 = g_sweep_config_eco.sweep_max_freq;
  }
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: base freq= %d\n","driver-btm-soc.c",0x1ec5,"getDiffFreqInfo",iVar5);
    }
    fclose(pFVar3);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      iVar6 = chain * 0x102 + 0x14e2002;
      bVar1 = false;
      for (chip = 0; chip < 0x3c; chip = chip + 1) {
        if (chip % 10 == 0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar3 = fopen(log_file,"a+");
            if (pFVar3 != (FILE *)0x0) {
              fprintf(pFVar3,"%s:%d:%s: chain[%d] chip[%d] freq:%d\n","driver-btm-soc.c",0x1ed5,
                      "getDiffFreqInfo",chain,chip,*(undefined4 *)(chip * 4 + iVar6));
            }
            fclose(pFVar3);
          }
          if (iVar5 != *(int *)(chip * 4 + iVar6)) {
            if (!bVar1) {
              iVar4 = sprintf(infoStr + retlen,"Chain[%d]: ",chain);
              retlen = retlen + iVar4;
              bVar1 = true;
            }
            iVar4 = sprintf(infoStr + retlen,"vol[%d]:%d  ",chip / 10,
                            *(undefined4 *)(chip * 4 + iVar6));
            retlen = retlen + iVar4;
          }
        }
      }
    }
  }
  return;
}

