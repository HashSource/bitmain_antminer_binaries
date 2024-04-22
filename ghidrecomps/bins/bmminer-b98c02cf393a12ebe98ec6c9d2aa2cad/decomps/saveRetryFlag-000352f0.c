
void saveRetryFlag(undefined4 param_1)

{
  FILE *__s;
  char acStack_30 [36];
  
  __s = fopen("/etc/config/retryFlag","wb");
  if (__s != (FILE *)0x0) {
    memset(acStack_30,0,0x20);
    sprintf(acStack_30,"%d",param_1);
    fwrite(acStack_30,1,0x20,__s);
    fclose(__s);
  }
  system("sync");
  return;
}

