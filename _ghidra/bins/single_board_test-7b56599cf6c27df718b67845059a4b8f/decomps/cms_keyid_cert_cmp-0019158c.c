
int cms_keyid_cert_cmp(ASN1_STRING *param_1,undefined4 param_2)

{
  ASN1_STRING *b;
  int iVar1;
  
  b = (ASN1_STRING *)X509_get0_subject_key_id(param_2);
  if (b != (ASN1_STRING *)0x0) {
    iVar1 = ASN1_OCTET_STRING_cmp(param_1,b);
    return iVar1;
  }
  return -1;
}

