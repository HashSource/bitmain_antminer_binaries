
/* WARNING: Unknown calling convention */

int scanfreq_get_works(void)

{
  _Bool _Var1;
  SCAN_FREQ_WORK *pSVar2;
  int iVar3;
  FILE *fp;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_4;
  FILE *pFile_1;
  FILE *pFile;
  int AsicNum;
  int CoreNum;
  int asic_work_num;
  int j;
  int i;
  
  asic_work_num = 0;
  CoreNum = scanfreq_info.CoreNum;
  AsicNum = scanfreq_info.AsicNum;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"%s:%d:%s: read all patterns from one file\n","freq_scan.c",0x13e,
              "scanfreq_get_works");
    }
    fclose((FILE *)pFile);
  }
  fp = (FILE *)0x0;
  _Var1 = is_T11();
  if (_Var1) {
    fp = (FILE *)fopen("/dev/83601_8pattern.txt","r");
  }
  else {
    _Var1 = is_T11a();
    if (_Var1) {
      fp = (FILE *)fopen("/dev/83602_8pattern.txt","r");
    }
    else {
      _Var1 = is_T11b();
      if (!_Var1) {
        print_crt_time_to_file(log_file,1);
        pFile_1 = (FILE *)fopen(log_file,"a+");
        if (pFile_1 != (FILE *)0x0) {
          fprintf((FILE *)pFile_1,
                  "Assert fail!! %s:%d: unkown type, prepare test pattern file yourself",
                  "freq_scan.c",0x14f);
        }
        fclose((FILE *)pFile_1);
                    /* WARNING: Subroutine does not return */
        __assert_fail("0","freq_scan.c",0x14f,"scanfreq_get_works");
      }
      fp = (FILE *)fopen("/dev/83603_8pattern.txt","r");
    }
  }
  if (fp == (FILE *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFile_2 = (FILE *)fopen(log_file,"a+");
      if (pFile_2 != (FILE *)0x0) {
        fprintf((FILE *)pFile_2,"%s:%d:%s: !!!!!!!!!!!!!! Open pattern file error\n","freq_scan.c",
                0x153,"scanfreq_get_works");
      }
      fclose((FILE *)pFile_2);
    }
    iVar3 = -1;
  }
  else {
    for (i = 0; i < AsicNum; i = i + 1) {
      asic_work_num = 0;
      pSVar2 = (SCAN_FREQ_WORK *)malloc(scanfreq_info.AsicWorkCount * 0x74);
      scanfreq_info.works[i] = pSVar2;
      if (scanfreq_info.works[i] == (SCAN_FREQ_WORK *)0x0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_3 = (FILE *)fopen(log_file,"a+");
          if (pFile_3 != (FILE *)0x0) {
            fprintf((FILE *)pFile_3,"%s:%d:%s: malloc struct work err\n","freq_scan.c",0x15d,
                    "scanfreq_get_works");
          }
          fclose((FILE *)pFile_3);
        }
        return -1;
      }
      for (j = 0; j < CoreNum; j = j + 1) {
        iVar3 = __aeabi_idiv(scanfreq_info.AsicWorkCount,CoreNum);
        iVar3 = scan_freq_get_work_of_core_one_file(i,j,&fp,iVar3);
        asic_work_num = asic_work_num + iVar3;
      }
      if (asic_work_num < scanfreq_info.AsicWorkCount) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile_4 = (FILE *)fopen(log_file,"a+");
          if (pFile_4 != (FILE *)0x0) {
            fprintf((FILE *)pFile_4,"%s:%d:%s: Error: Asic %d get %d work, required work=%d\n",
                    "freq_scan.c",0x168,"scanfreq_get_works",i,asic_work_num,
                    scanfreq_info.AsicWorkCount);
          }
          fclose((FILE *)pFile_4);
        }
        fclose((FILE *)fp);
        return -1;
      }
    }
    fclose((FILE *)fp);
    iVar3 = 0;
  }
  return iVar3;
}

