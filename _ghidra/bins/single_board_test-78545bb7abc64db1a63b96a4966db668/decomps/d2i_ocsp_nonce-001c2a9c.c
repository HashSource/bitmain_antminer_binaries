
ASN1_OCTET_STRING * d2i_ocsp_nonce(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  ASN1_OCTET_STRING *str;
  
  if (param_1 == (undefined4 *)0x0) {
    str = ASN1_OCTET_STRING_new();
    if ((str != (ASN1_OCTET_STRING *)0x0) &&
       (iVar1 = ASN1_OCTET_STRING_set(str,(void *)*param_2,param_3), iVar1 != 0)) {
      *param_2 = param_3 + *param_2;
      return str;
    }
  }
  else {
    str = (ASN1_OCTET_STRING *)*param_1;
    if (str == (ASN1_STRING *)0x0) {
      str = ASN1_OCTET_STRING_new();
      if (str != (ASN1_OCTET_STRING *)0x0) {
        iVar1 = ASN1_OCTET_STRING_set(str,(void *)*param_2,param_3);
        goto joined_r0x001c2ad6;
      }
    }
    else {
      iVar1 = ASN1_OCTET_STRING_set(str,(void *)*param_2,param_3);
joined_r0x001c2ad6:
      if (iVar1 != 0) {
        *param_2 = param_3 + *param_2;
        *param_1 = str;
        return str;
      }
    }
    if ((ASN1_OCTET_STRING *)*param_1 == str) goto LAB_001c2ae4;
  }
  ASN1_OCTET_STRING_free(str);
LAB_001c2ae4:
  ERR_put_error(0x27,0x66,0x41,"crypto/ocsp/v3_ocsp.c",0xce);
  return (ASN1_OCTET_STRING *)0x0;
}

