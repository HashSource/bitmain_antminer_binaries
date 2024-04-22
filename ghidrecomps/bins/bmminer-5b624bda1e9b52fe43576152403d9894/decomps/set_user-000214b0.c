
/* WARNING: Unknown calling convention */

char * set_user(char *arg)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000214f4;
  if (*(int *)(DAT_000214f4 + 0x48c) != 0) {
    return DAT_000214f8;
  }
  iVar2 = *DAT_000214fc;
  iVar3 = *(int *)(DAT_000214f4 + 0x484) + 1;
  *(int *)(DAT_000214f4 + 0x484) = iVar3;
  if (iVar2 < iVar3) {
    add_pool();
    iVar3 = *(int *)(iVar1 + 0x484);
  }
  opt_set_charp(arg,(char **)(*(int *)(*DAT_00021500 + (iVar3 + -1) * 4) + 0xac));
  return (char *)0x0;
}

