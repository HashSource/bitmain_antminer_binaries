
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

lhash_st_ERR_STATE * ERR_get_err_state_table(void)

{
  int iVar1;
  lhash_st_ERR_STATE *plVar2;
  int iVar3;
  
  iVar1 = DAT_000ad4f4;
  iVar3 = *(int *)(DAT_000ad4f4 + 0x2f4);
  if (iVar3 == 0) {
    CRYPTO_lock(9,1,DAT_000ad4f8,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad4fc;
    }
    CRYPTO_lock(10,1,DAT_000ad4f8,0x12a);
    iVar3 = *(int *)(iVar1 + 0x2f4);
  }
  plVar2 = (lhash_st_ERR_STATE *)(**(code **)(iVar3 + 0x14))(0);
  return plVar2;
}

