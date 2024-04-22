
int readTestID(void)

{
  int iVar1;
  char acStack_2c [32];
  FILE *local_c;
  
  local_c = fopen("/etc/config/testID","rb");
  if (local_c == (FILE *)0x0) {
    iVar1 = 0;
  }
  else {
    memset(acStack_2c,0,0x20);
    fread(acStack_2c,1,0x20,local_c);
    fclose(local_c);
    iVar1 = atoi(acStack_2c);
  }
  return iVar1;
}

