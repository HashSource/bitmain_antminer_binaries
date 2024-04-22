
void readChainTestPattenResult(undefined4 param_1)

{
  FILE *__stream;
  char acStack_128 [32];
  char acStack_108 [256];
  
  sprintf(acStack_108,"/etc/config/%d.test",param_1);
  __stream = fopen(acStack_108,"rb");
  if (__stream != (FILE *)0x0) {
    memset(acStack_128,0,0x20);
    fread(acStack_128,1,0x20,__stream);
    fclose(__stream);
    strtol(acStack_128,(char **)0x0,10);
    return;
  }
  return;
}

