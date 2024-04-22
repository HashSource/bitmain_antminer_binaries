
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CRYPTO_EX_DATA_IMPL * CRYPTO_get_ex_data_implementation(void)

{
  int iVar1;
  
  iVar1 = DAT_0008b664;
  if (*(CRYPTO_EX_DATA_IMPL **)(DAT_0008b664 + 4) != (CRYPTO_EX_DATA_IMPL *)0x0) {
    return *(CRYPTO_EX_DATA_IMPL **)(DAT_0008b664 + 4);
  }
  CRYPTO_lock(9,2,DAT_0008b668,0xc9);
  if (*(int *)(iVar1 + 4) == 0) {
    *(undefined4 *)(iVar1 + 4) = DAT_0008b66c;
  }
  CRYPTO_lock(10,2,DAT_0008b668,0xcc);
  return *(CRYPTO_EX_DATA_IMPL **)(iVar1 + 4);
}

