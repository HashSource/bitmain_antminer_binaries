
ASN1_IA5STRING * s2i_ASN1_IA5STRING(undefined4 param_1,undefined4 param_2,char *param_3)

{
  ASN1_IA5STRING *str;
  size_t len;
  int iVar1;
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(0x22,100,0x6b,"crypto/x509v3/v3_ia5.c",0x31);
    str = (ASN1_IA5STRING *)0x0;
  }
  else {
    str = ASN1_IA5STRING_new();
    if (str == (ASN1_IA5STRING *)0x0) {
      ERR_put_error(0x22,100,0x41,"crypto/x509v3/v3_ia5.c",0x3f);
    }
    else {
      len = strlen(param_3);
      iVar1 = ASN1_STRING_set(str,param_3,len);
      if (iVar1 == 0) {
        ASN1_IA5STRING_free(str);
        str = (ASN1_IA5STRING *)0x0;
      }
    }
  }
  return str;
}

