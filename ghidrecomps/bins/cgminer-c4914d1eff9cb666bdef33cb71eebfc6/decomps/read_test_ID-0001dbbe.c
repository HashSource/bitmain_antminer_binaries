
int read_test_ID(uint32_t *testID,uint32_t *data)

{
  FILE *pFVar1;
  int iVar2;
  uint32_t *data_local;
  uint32_t *testID_local;
  char testnumStr [32];
  FILE *pFile;
  FILE *fd;
  
  pFVar1 = fopen("/tmp/testID","rb");
  if (pFVar1 == (FILE *)0x0) {
    iVar2 = 0;
  }
  else {
    memset(testnumStr,0,0x20);
    fread(testnumStr,1,0x20,pFVar1);
    fclose(pFVar1);
    if ((testnumStr[0] == '0') && (testnumStr[1] == 'x')) {
      sscanf(testnumStr,"%x %x",testID,data);
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: receive test id :0x%x, data : 0x%x!\n","driver-btm-soc.c",0x883,
                  "read_test_ID",*testID,*data);
        }
        fclose(pFVar1);
      }
      iVar2 = 0;
    }
    else {
      iVar2 = atoi(testnumStr);
    }
  }
  return iVar2;
}

