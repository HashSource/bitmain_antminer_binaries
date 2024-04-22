
bool i2r_ocsp_nonce(undefined4 param_1,ASN1_STRING *param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = BIO_printf(param_3,DAT_000cc34c,param_4,DAT_000cc350,param_4);
  if (iVar1 < 1) {
    return false;
  }
  iVar1 = i2a_ASN1_STRING(param_3,param_2,4);
  return 0 < iVar1;
}

