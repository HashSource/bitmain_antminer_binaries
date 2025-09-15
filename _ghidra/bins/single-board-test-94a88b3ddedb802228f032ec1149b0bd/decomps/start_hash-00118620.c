
int start_hash(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 != 0) {
    memset(param_1 + 4,0,0x20);
    memset(param_1 + 0xc,0,0x20);
    iVar1 = 1;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = 0;
  }
  return iVar1;
}

