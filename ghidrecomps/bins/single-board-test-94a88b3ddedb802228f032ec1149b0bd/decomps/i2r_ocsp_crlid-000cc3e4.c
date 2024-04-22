
bool i2r_ocsp_crlid(undefined4 param_1,ASN1_STRING **param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((*param_2 == (ASN1_STRING *)0x0) ||
      (((iVar1 = BIO_printf(param_3,DAT_000cc484,param_4,DAT_000cc488), 0 < iVar1 &&
        (iVar1 = ASN1_STRING_print(param_3,*param_2), iVar1 != 0)) &&
       (iVar1 = BIO_write(param_3,DAT_000cc48c,1), 0 < iVar1)))) &&
     ((param_2[1] == (ASN1_STRING *)0x0 ||
      (((iVar1 = BIO_printf(param_3,DAT_000cc490,param_4,DAT_000cc488), 0 < iVar1 &&
        (iVar1 = i2a_ASN1_INTEGER(param_3,param_2[1]), 0 < iVar1)) &&
       (iVar1 = BIO_write(param_3,DAT_000cc48c,1), 0 < iVar1)))))) {
    if (param_2[2] == (ASN1_STRING *)0x0) {
      return true;
    }
    iVar1 = BIO_printf(param_3,DAT_000cc494,param_4,DAT_000cc488);
    if ((0 < iVar1) && (iVar1 = ASN1_GENERALIZEDTIME_print(param_3,param_2[2]), iVar1 != 0)) {
      iVar1 = BIO_write(param_3,DAT_000cc48c,1);
      return 0 < iVar1;
    }
  }
  return false;
}

