
void checkSearchFailedFlagInfo(void)

{
  FILE *pFVar1;
  int iVar2;
  
  pFVar1 = fopen("/tmp/searcherror","rb");
  if (pFVar1 != (FILE *)0x0) {
    fread(search_failed_info,1,0x40,pFVar1);
    fclose(pFVar1);
    search_failed_info[63] = 0;
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: Find /tmp/searcherror: %s  The last log is below:\n","main.c",0x358e,
                search_failed_info);
      }
      fclose(pFVar1);
    }
    system("cat /tmp/err1.log >> /tmp/search");
    system("cat /tmp/err2.log >> /tmp/freq");
    system("cat /tmp/err3.log >> /tmp/lasttemp");
    searchStatus = 2;
    do {
      processTEST();
      sleep(1);
    } while( true );
  }
  iVar2 = readRebootTestNum();
  if (iVar2 == 0xd05) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d: \n Hashrate too Low : < 98%% ideal rate, BIMMINER TEST Result: FAILED! The last log is below:\n"
                ,"main.c",0x359f);
      }
      fclose(pFVar1);
    }
    system("cat /tmp/err1.log >> /tmp/search");
    system("cat /tmp/err2.log >> /tmp/freq");
    system("cat /tmp/err3.log >> /tmp/lasttemp");
    search_failed_info._0_4_ = DAT_00132880;
    saveSearchFailedFlagInfo();
    searchStatus = 2;
    do {
      processTEST();
      sleep(1);
    } while( true );
  }
  return;
}

