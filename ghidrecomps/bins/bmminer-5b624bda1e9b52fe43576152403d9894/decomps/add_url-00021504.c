
/* WARNING: Unknown calling convention */

pool * add_url(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_00021530;
  iVar2 = *DAT_00021534;
  iVar3 = *(int *)(DAT_00021530 + 0x490) + 1;
  *(int *)(DAT_00021530 + 0x490) = iVar3;
  if (iVar2 < iVar3) {
    add_pool();
    iVar3 = *(int *)(iVar1 + 0x490);
  }
  return *(pool **)(*DAT_00021538 + (iVar3 + -1) * 4);
}

