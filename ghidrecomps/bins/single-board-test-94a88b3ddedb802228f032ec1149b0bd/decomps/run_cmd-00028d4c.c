
undefined4 run_cmd(char *param_1)

{
  char *pcVar1;
  char acStack_110 [256];
  FILE *local_10;
  FILE *local_c;
  
  memset(acStack_110,0,0x100);
  local_c = popen(param_1,"r");
  if (local_c != (FILE *)0x0) {
    while (pcVar1 = fgets(acStack_110,0x100,local_c), pcVar1 != (char *)0x0) {
      if (3 < log_level) {
        local_10 = fopen(log_file,"a+");
        if (local_10 != (FILE *)0x0) {
          fprintf(local_10,"%s:%d: ret=%s\n","main.c",0xbda,acStack_110);
        }
        fclose(local_10);
      }
      memset(acStack_110,0,0x100);
      usleep(1000);
    }
    pclose(local_c);
  }
  return 0;
}

