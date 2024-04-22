
void PostMsgToTestPlatform(undefined4 param_1)

{
  int iVar1;
  char acStack_420 [1024];
  void *local_20;
  FILE *local_1c;
  FILE *local_18;
  FILE *local_14;
  FILE *local_10;
  int local_c;
  
  for (local_c = 0; local_20 = (void *)0x0, local_c < 3; local_c = local_c + 1) {
    sprintf(acStack_420,"http://%s/mms/%s",*(undefined4 *)(&testServerIP + local_c * 4),param_1);
    if (3 < log_level) {
      local_10 = fopen(log_file,"a+");
      if (local_10 != (FILE *)0x0) {
        fprintf(local_10,"%s:%d: post: %s\n","http.c",0x19f,acStack_420);
      }
      fclose(local_10);
    }
    iVar1 = http_get(acStack_420,&local_20);
    if (0 < iVar1) {
      if (3 < log_level) {
        local_14 = fopen(log_file,"a+");
        if (local_14 != (FILE *)0x0) {
          fprintf(local_14,"%s:%d: post result: ","http.c",0x1a3);
        }
        fclose(local_14);
      }
      if (3 < log_level) {
        local_18 = fopen(log_file,"a+");
        if (local_18 != (FILE *)0x0) {
          fprintf(local_18,"%s:%d: %s","http.c",0x1a4,local_20);
        }
        fclose(local_18);
      }
      if (3 < log_level) {
        local_1c = fopen(log_file,"a+");
        if (local_1c != (FILE *)0x0) {
          fprintf(local_1c,"%s:%d: \n","http.c",0x1a5);
        }
        fclose(local_1c);
      }
    }
    if (local_20 != (void *)0x0) {
      free(local_20);
    }
  }
  return;
}

