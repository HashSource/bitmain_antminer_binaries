
void saveChainTestPattenResult(undefined4 param_1,undefined4 param_2)

{
  FILE *__s;
  char acStack_130 [32];
  char acStack_110 [260];
  
  sprintf(acStack_110,"/etc/config/%d.test",param_1);
  __s = fopen(acStack_110,"wb");
  if (__s != (FILE *)0x0) {
    memset(acStack_130,0,0x20);
    sprintf(acStack_130,"%d",param_2);
    fwrite(acStack_130,1,0x20,__s);
    fclose(__s);
  }
  system("sync");
  return;
}

