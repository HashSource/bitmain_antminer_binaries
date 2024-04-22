
ASN1_STRING * d2i_ocsp_nonce(ASN1_STRING **param_1,void **param_2,int param_3)

{
  int iVar1;
  ASN1_OCTET_STRING *str;
  
  if ((param_1 == (ASN1_STRING **)0x0) || (str = *param_1, str == (ASN1_STRING *)0x0)) {
    str = ASN1_OCTET_STRING_new();
  }
  iVar1 = ASN1_OCTET_STRING_set(str,*param_2,param_3);
  if (iVar1 == 0) {
    if ((str != (ASN1_STRING *)0x0) && ((param_1 == (ASN1_STRING **)0x0 || (*param_1 != str)))) {
      ASN1_STRING_free(str);
    }
    str = (ASN1_STRING *)0x0;
    ERR_put_error(0x27,0x66,0x41,DAT_000cc3ac,0xfd);
  }
  else {
    *param_2 = (void *)((int)*param_2 + param_3);
    if (param_1 != (ASN1_STRING **)0x0) {
      *param_1 = str;
    }
  }
  return str;
}

