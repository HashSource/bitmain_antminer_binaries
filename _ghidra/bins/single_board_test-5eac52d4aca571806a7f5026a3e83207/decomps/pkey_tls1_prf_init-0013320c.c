
bool pkey_tls1_prf_init(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x410,"crypto/kdf/tls1_prf.c",0x28);
  if (iVar1 == 0) {
    ERR_put_error(0x34,0x6e,0x41,"crypto/kdf/tls1_prf.c",0x29);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return iVar1 != 0;
}

