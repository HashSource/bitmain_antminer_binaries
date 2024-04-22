
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STRING_DATA * ERR_get_string_table(void)

{
  int iVar1;
  lhash_st_ERR_STRING_DATA *plVar2;
  code **ppcVar3;
  
  iVar1 = DAT_000ad4a4;
  ppcVar3 = *(code ***)(DAT_000ad4a4 + 0x2f4);
  if (ppcVar3 == (code **)0x0) {
    CRYPTO_lock(9,1,DAT_000ad4a8,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad4ac;
    }
    CRYPTO_lock(10,1,DAT_000ad4a8,0x12a);
    ppcVar3 = *(code ***)(iVar1 + 0x2f4);
  }
  plVar2 = (lhash_st_ERR_STRING_DATA *)(**ppcVar3)(0);
  return plVar2;
}

