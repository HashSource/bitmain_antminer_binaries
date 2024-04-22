
void ERR_release_err_state_table(lhash_st_ERR_STATE **hash)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_000ad544;
  iVar2 = *(int *)(DAT_000ad544 + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad548,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad54c;
    }
    CRYPTO_lock(10,1,DAT_000ad548,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  (**(code **)(iVar2 + 0x18))(hash);
  return;
}

