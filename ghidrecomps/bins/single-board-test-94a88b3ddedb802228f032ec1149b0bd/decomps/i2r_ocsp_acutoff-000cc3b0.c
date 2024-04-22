
int i2r_ocsp_acutoff(undefined4 param_1,ASN1_GENERALIZEDTIME *param_2,BIO *param_3,
                    undefined4 param_4)

{
  int iVar1;
  
  iVar1 = BIO_printf(param_3,DAT_000cc3dc,param_4,DAT_000cc3e0,param_4);
  if (0 < iVar1) {
    iVar1 = ASN1_GENERALIZEDTIME_print(param_3,param_2);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}

