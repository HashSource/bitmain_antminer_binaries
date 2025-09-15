
char check_bmminer(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  char acStack_494 [1024];
  char acStack_94 [128];
  FILE *local_14;
  FILE *local_10;
  char local_9;
  
  local_9 = '\0';
  memset(acStack_94,0,0x80);
  iVar1 = is7007_Board();
  if (iVar1 == 0) {
    sprintf(acStack_94,"ps -ef|grep %s",param_1);
  }
  else {
    sprintf(acStack_94,"ps |grep %s",param_1);
  }
  local_10 = popen(acStack_94,"r");
  if (local_10 != (FILE *)0x0) {
    memset(acStack_494,0,0x400);
    while (pcVar2 = fgets(acStack_494,0x400,local_10), pcVar2 != (char *)0x0) {
      pcVar2 = strstr(acStack_494,"/usr/bin/bmminer");
      if (pcVar2 != (char *)0x0) {
        local_9 = '\x01';
      }
    }
    if ((local_9 != '\x01') && (3 < log_level)) {
      local_14 = fopen(log_file,"a+");
      if (local_14 != (FILE *)0x0) {
        fprintf(local_14,"%s:%d: bmminer not found=%s\n","main.c",0x366e,acStack_494);
      }
      fclose(local_14);
    }
    pclose(local_10);
  }
  return local_9;
}

