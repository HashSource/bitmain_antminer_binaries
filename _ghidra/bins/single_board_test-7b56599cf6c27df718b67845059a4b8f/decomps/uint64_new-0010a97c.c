
undefined4 uint64_new(int *param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(8,"crypto/asn1/x_int64.c",0x1f);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 1;
  }
  ERR_put_error(0xd,0x8d,0x41,"crypto/asn1/x_int64.c",0x20);
  return 0;
}

