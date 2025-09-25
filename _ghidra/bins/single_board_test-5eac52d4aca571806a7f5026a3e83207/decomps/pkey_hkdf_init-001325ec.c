
bool pkey_hkdf_init(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x41c,"crypto/kdf/hkdf.c",0x33);
  if (iVar1 == 0) {
    ERR_put_error(0x34,0x6c,0x41,"crypto/kdf/hkdf.c",0x34);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return iVar1 != 0;
}

