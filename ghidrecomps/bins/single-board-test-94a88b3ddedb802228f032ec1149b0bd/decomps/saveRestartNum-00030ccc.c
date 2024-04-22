
void saveRestartNum(undefined4 param_1)

{
  char acStack_2c [32];
  FILE *local_c;
  
  local_c = fopen("/etc/config/restartTest","wb");
  if (local_c != (FILE *)0x0) {
    memset(acStack_2c,0,0x20);
    sprintf(acStack_2c,"%d",param_1);
    fwrite(acStack_2c,1,0x20,local_c);
    fclose(local_c);
  }
  system("sync");
  return;
}

