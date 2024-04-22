
ASN1_STRING * s2i_ASN1_IA5STRING(undefined4 param_1,undefined4 param_2,char *param_3)

{
  ASN1_STRING *str;
  size_t len;
  int iVar1;
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(0x22,100,0x6b,DAT_0010ced0,0x66);
  }
  else {
    str = ASN1_STRING_type_new(0x16);
    if (str != (ASN1_STRING *)0x0) {
      len = strlen(param_3);
      iVar1 = ASN1_STRING_set(str,param_3,len);
      if (iVar1 != 0) {
        return str;
      }
      ASN1_STRING_free(str);
    }
    ERR_put_error(0x22,100,0x41,DAT_0010ced0,0x75);
  }
  return (ASN1_STRING *)0x0;
}

