
undefined4 cms_set1_ias(ASN1_VALUE **param_1,X509 *param_2)

{
  X509_NAME **xn;
  X509_NAME *pXVar1;
  int iVar2;
  ASN1_INTEGER *str;
  
  xn = (X509_NAME **)ASN1_item_new(DAT_0010fea4);
  if (xn != (X509_NAME **)0x0) {
    pXVar1 = X509_get_issuer_name(param_2);
    iVar2 = X509_NAME_set(xn,pXVar1);
    if (iVar2 != 0) {
      pXVar1 = xn[1];
      str = X509_get_serialNumber(param_2);
      iVar2 = ASN1_STRING_copy((ASN1_STRING *)pXVar1,str);
      if (iVar2 != 0) {
        if (*param_1 != (ASN1_VALUE *)0x0) {
          ASN1_item_free(*param_1,DAT_0010fea4);
        }
        *param_1 = (ASN1_VALUE *)xn;
        return 1;
      }
    }
    ASN1_item_free((ASN1_VALUE *)xn,DAT_0010fea4);
  }
  ERR_put_error(0x2e,0xb0,0x41,DAT_0010fea8,0x277);
  return 0;
}

