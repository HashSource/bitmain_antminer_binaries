
undefined4 uint32_new(int *param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(4,"crypto/asn1/x_int64.c",0x7e);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 1;
  }
  ERR_put_error(0xd,0x8b,0x41,"crypto/asn1/x_int64.c",0x7f);
  return 0;
}

