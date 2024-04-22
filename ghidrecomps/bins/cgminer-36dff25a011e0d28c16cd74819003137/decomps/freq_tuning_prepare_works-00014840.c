
/* WARNING: Unknown calling convention */

int freq_tuning_prepare_works(void)

{
  int iVar1;
  FILE *fp;
  FILE *pFile;
  FILE *pFile_1;
  int ret;
  int core;
  int asic;
  int work_count_for_asic;
  
  ret = 0;
  fp = (FILE *)fopen(g_BHB91602_proj.test_pattern,"r");
  if (fp == (FILE *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"%s:%d:%s: Fail to open test pattern file %s.\n","freq_tuning.c",0x263
                ,"freq_tuning_prepare_works",g_BHB91602_proj.test_pattern);
      }
      fclose((FILE *)pFile);
    }
    ret = -1;
  }
  else {
    for (asic = 0; asic < 0x30; asic = asic + 1) {
      work_count_for_asic = 0;
      for (core = 0; core < 0x2a0; core = core + 1) {
        iVar1 = freq_tuning_get_work_for_one_core(&fp,asic,core,1);
        work_count_for_asic = work_count_for_asic + iVar1;
      }
      if (work_count_for_asic < 0x2a0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_1 = (FILE *)fopen(log_file,"a+");
          if (pFile_1 != (FILE *)0x0) {
            fprintf((FILE *)pFile_1,
                    "%s:%d:%s: No enough work for freq tuning. ASIC %d, work %d, required work %d\n"
                    ,"freq_tuning.c",0x273,"freq_tuning_prepare_works",asic,work_count_for_asic,
                    0x2a0);
          }
          fclose((FILE *)pFile_1);
        }
        ret = -1;
        break;
      }
    }
    fclose((FILE *)fp);
  }
  return ret;
}

