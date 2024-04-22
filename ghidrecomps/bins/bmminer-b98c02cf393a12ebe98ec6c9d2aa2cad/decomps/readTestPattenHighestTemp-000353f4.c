
void readTestPattenHighestTemp(void)

{
  FILE *__stream;
  char acStack_28 [32];
  
  __stream = fopen("/etc/config/pcbtemp","rb");
  if (__stream != (FILE *)0x0) {
    memset(acStack_28,0,0x20);
    fread(acStack_28,1,0x20,__stream);
    fclose(__stream);
    strtol(acStack_28,(char **)0x0,10);
    return;
  }
  return;
}

