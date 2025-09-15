
/* WARNING: Unknown calling convention */

int read_test_ID(void)

{
  FILE *pFVar1;
  int testid;
  char testnumStr [32];
  FILE *pFile;
  FILE *fd;
  
  pFVar1 = fopen("/tmp/testID","rb");
  if (pFVar1 == (FILE *)0x0) {
    testid = 0;
  }
  else {
    memset(testnumStr,0,0x20);
    fread(testnumStr,1,0x20,pFVar1);
    fclose(pFVar1);
    if ((testnumStr[0] == '0') && (testnumStr[1] == 'x')) {
      sscanf(testnumStr,"%x",&testid);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: receive test id :0x%x!\n","driver-btm-soc.c",0xe16,
                  "read_test_ID",testid);
        }
        fclose(pFVar1);
      }
    }
    else {
      testid = atoi(testnumStr);
    }
  }
  return testid;
}

