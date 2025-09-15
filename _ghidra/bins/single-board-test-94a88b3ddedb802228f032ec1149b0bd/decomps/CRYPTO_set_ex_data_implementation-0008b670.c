
int CRYPTO_set_ex_data_implementation(CRYPTO_EX_DATA_IMPL *i)

{
  bool bVar1;
  CRYPTO_EX_DATA_IMPL *pCVar2;
  
  CRYPTO_lock(9,2,"ex_data.c",0xde);
  bVar1 = impl == (CRYPTO_EX_DATA_IMPL *)0x0;
  pCVar2 = i;
  if (!bVar1) {
    pCVar2 = impl;
  }
  impl = pCVar2;
  CRYPTO_lock(10,2,"ex_data.c",0xe3);
  return (uint)bVar1;
}

