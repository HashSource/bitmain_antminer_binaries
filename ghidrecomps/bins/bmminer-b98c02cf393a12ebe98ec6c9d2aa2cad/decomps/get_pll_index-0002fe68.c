
int get_pll_index(undefined4 param_1)

{
  undefined *__s1;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char acStack_1c [16];
  
  sprintf(acStack_1c,"%d",param_1);
  iVar3 = 0;
  __s1 = &DAT_00062030;
  puVar2 = DAT_0002feb4;
  while( true ) {
    iVar1 = memcmp(__s1,acStack_1c,4);
    if (iVar1 == 0) {
      return iVar3;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 0x72) break;
    __s1 = (undefined *)*puVar2;
    puVar2 = puVar2 + 4;
  }
  return -1;
}

