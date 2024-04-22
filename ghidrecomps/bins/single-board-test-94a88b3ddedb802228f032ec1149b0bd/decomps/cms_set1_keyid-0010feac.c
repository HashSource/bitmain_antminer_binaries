
undefined4 cms_set1_keyid(ASN1_STRING **param_1,X509 *param_2)

{
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  
  X509_check_purpose(param_2,-1,-1);
  if (param_2->skid == (ASN1_STRING *)0x0) {
    ERR_put_error(0x2e,0xb1,0xa0,DAT_0010ff0c,0x280);
    uVar2 = 0;
  }
  else {
    pAVar1 = ASN1_STRING_dup(param_2->skid);
    if (pAVar1 == (ASN1_STRING *)0x0) {
      ERR_put_error(0x2e,0xb1,0x41,DAT_0010ff0c,0x285);
      uVar2 = 0;
    }
    else {
      if (*param_1 != (ASN1_OCTET_STRING *)0x0) {
        ASN1_OCTET_STRING_free(*param_1);
      }
      uVar2 = 1;
      *param_1 = pAVar1;
    }
  }
  return uVar2;
}

