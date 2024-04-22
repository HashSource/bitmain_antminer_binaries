
int cms_keyid_cert_cmp(ASN1_STRING *param_1,X509 *param_2)

{
  int iVar1;
  
  X509_check_purpose(param_2,-1,-1);
  if (param_2->skid != (ASN1_STRING *)0x0) {
    iVar1 = ASN1_OCTET_STRING_cmp(param_1,param_2->skid);
    return iVar1;
  }
  return -1;
}

