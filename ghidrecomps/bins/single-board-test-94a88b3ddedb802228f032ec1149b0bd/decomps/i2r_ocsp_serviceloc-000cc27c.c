
undefined4 i2r_ocsp_serviceloc(undefined4 param_1,X509_NAME **param_2,BIO *param_3,int param_4)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  
  iVar1 = BIO_printf(param_3,DAT_000cc310,param_4,DAT_000cc30c);
  if ((0 < iVar1) && (iVar1 = X509_NAME_print_ex(param_3,*param_2,0,0x82031f), 0 < iVar1)) {
    iVar1 = 0;
    while( true ) {
      iVar3 = sk_num((_STACK *)param_2[1]);
      if (iVar3 <= iVar1) {
        return 1;
      }
      ppAVar2 = (ASN1_OBJECT **)sk_value((_STACK *)param_2[1],iVar1);
      iVar3 = BIO_printf(param_3,DAT_000cc314,param_4 << 1,DAT_000cc30c);
      if (iVar3 < 1) break;
      iVar3 = i2a_ASN1_OBJECT(param_3,*ppAVar2);
      if (iVar3 < 1) {
        return 0;
      }
      iVar3 = BIO_puts(param_3,DAT_000cc318);
      if (iVar3 < 1) {
        return 0;
      }
      iVar3 = GENERAL_NAME_print(param_3,(GENERAL_NAME *)ppAVar2[1]);
      iVar1 = iVar1 + 1;
      if (iVar3 < 1) {
        return 0;
      }
    }
  }
  return 0;
}

