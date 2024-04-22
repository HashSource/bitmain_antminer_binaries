
/* WARNING: Unknown calling convention */

char * set_pass(char *arg)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000216d0;
  if (*(int *)(DAT_000216d0 + 0x48c) != 0) {
    return DAT_000216d4;
  }
  iVar2 = *DAT_000216d8;
  iVar3 = *(int *)(DAT_000216d0 + 0x488) + 1;
  *(int *)(DAT_000216d0 + 0x488) = iVar3;
  if (iVar2 < iVar3) {
    add_pool();
    iVar3 = *(int *)(iVar1 + 0x488);
  }
  opt_set_charp(arg,(char **)(*(int *)(*DAT_000216dc + (iVar3 + -1) * 4) + 0xb0));
  return (char *)0x0;
}

