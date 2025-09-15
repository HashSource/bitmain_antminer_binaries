
int my_system(char *cmd)

{
  FILE *pFVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  char *cmd_local;
  char buf [1024];
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  FILE *pFile_3;
  int res;
  FILE *fp;
  
  if (cmd == (char *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: cmd is NULL!\n","log.c",0x3b,"my_system");
      }
      fclose(pFVar1);
    }
    uVar4 = 0xffffffff;
  }
  else {
    pFVar1 = popen(cmd,"r");
    if (pFVar1 == (FILE *)0x0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          piVar2 = __errno_location();
          pcVar3 = strerror(*piVar2);
          fprintf(pFVar1,"%s:%d:%s: popen error: %s/n","log.c",0x40,"my_system",pcVar3);
        }
        fclose(pFVar1);
      }
      uVar4 = 0xffffffff;
    }
    else {
      do {
        pcVar3 = fgets(buf,0x400,pFVar1);
      } while (pcVar3 != (char *)0x0);
      uVar4 = pclose(pFVar1);
      if (uVar4 == 0xffffffff) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: close popen file pointer fp error!\n","log.c",0x4b,"my_system"
                   );
          }
          fclose(pFVar1);
        }
      }
      else if (uVar4 != 0) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: pclose res is :%d\n","log.c",0x54,"my_system",
                    (uint)((uVar4 & 0x7f) == 0));
          }
          fclose(pFVar1);
        }
        uVar4 = uVar4 >> 8 & 0xff;
      }
    }
  }
  return uVar4;
}

