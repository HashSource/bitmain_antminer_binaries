
undefined4 old_hmac_decode(EVP_PKEY *param_1,void **param_2,int param_3)

{
  ASN1_OCTET_STRING *str;
  int iVar1;
  
  str = ASN1_OCTET_STRING_new();
  if ((str != (ASN1_OCTET_STRING *)0x0) &&
     (iVar1 = ASN1_OCTET_STRING_set(str,*param_2,param_3), iVar1 != 0)) {
    EVP_PKEY_assign(param_1,0x357,str);
    return 1;
  }
  return 0;
}

