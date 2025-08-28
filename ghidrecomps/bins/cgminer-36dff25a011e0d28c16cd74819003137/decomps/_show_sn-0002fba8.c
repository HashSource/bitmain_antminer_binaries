
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _show_sn(void)

{
  FILE *pFVar1;
  size_t __size;
  size_t sVar2;
  FILE *pFVar3;
  char buf [100];
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  int len;
  FILE *fp;
  
  pFVar1 = fopen("/nvdata/sn","r");
  if (pFVar1 == (FILE *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: no SN got, please write SN to /nvdata/sn\n","driver-btm-soc.c",
                0x1c45,"_show_sn");
      }
      fclose(pFVar1);
    }
  }
  else {
    fseek(pFVar1,0,2);
    __size = ftell(pFVar1);
    fseek(pFVar1,0,0);
    if (99 < (int)__size) {
      __size = 100;
    }
    sVar2 = fread(buf,__size,1,pFVar1);
    if (sVar2 == 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: read /nvdata/sn wrong\n","driver-btm-soc.c",0x1c58,"_show_sn");
        }
        fclose(pFVar3);
      }
    }
    else {
      if (buf[__size - 1] == '\n') {
        buf[__size - 1] = '\0';
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: %s\n","driver-btm-soc.c",0x1c54,"_show_sn",buf);
        }
        fclose(pFVar3);
      }
    }
    fclose(pFVar1);
  }
  return;
}

