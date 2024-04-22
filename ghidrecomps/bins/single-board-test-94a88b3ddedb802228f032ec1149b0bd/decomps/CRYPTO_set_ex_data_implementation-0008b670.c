
int CRYPTO_set_ex_data_implementation(CRYPTO_EX_DATA_IMPL *i)

{
  bool bVar1;
  
  CRYPTO_lock(9,2,DAT_0008b6a0,0xde);
  bVar1 = *(int *)(DAT_0008b6a4 + 4) == 0;
  if (bVar1) {
    *(CRYPTO_EX_DATA_IMPL **)(DAT_0008b6a4 + 4) = i;
  }
  CRYPTO_lock(10,2,DAT_0008b6a0,0xe3);
  return (uint)bVar1;
}

