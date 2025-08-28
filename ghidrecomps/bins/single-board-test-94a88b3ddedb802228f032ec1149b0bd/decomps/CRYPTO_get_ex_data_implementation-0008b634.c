
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CRYPTO_EX_DATA_IMPL * CRYPTO_get_ex_data_implementation(void)

{
  if ((CRYPTO_EX_DATA_IMPL *)impl != (CRYPTO_EX_DATA_IMPL *)0x0) {
    return (CRYPTO_EX_DATA_IMPL *)impl;
  }
  CRYPTO_lock(9,2,"ex_data.c",0xc9);
  if ((CRYPTO_EX_DATA_IMPL *)impl == (CRYPTO_EX_DATA_IMPL *)0x0) {
    impl = impl_default;
  }
  CRYPTO_lock(10,2,"ex_data.c",0xcc);
  return (CRYPTO_EX_DATA_IMPL *)impl;
}

