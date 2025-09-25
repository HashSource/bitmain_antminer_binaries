
bool cms_set1_keyid(undefined4 *param_1,undefined4 param_2)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)X509_get0_subject_key_id(param_2);
  if (pAVar1 != (ASN1_STRING *)0x0) {
    pAVar1 = ASN1_STRING_dup(pAVar1);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2e,0xb1,0x41,"crypto/cms/cms_lib.c",0x246);
    }
    else {
      ASN1_OCTET_STRING_free((ASN1_STRING *)*param_1);
      *param_1 = pAVar1;
    }
    return pAVar1 != (ASN1_STRING *)0x0;
  }
  ERR_put_error(0x2e,0xb1,0xa0,"crypto/cms/cms_lib.c",0x241);
  return false;
}

