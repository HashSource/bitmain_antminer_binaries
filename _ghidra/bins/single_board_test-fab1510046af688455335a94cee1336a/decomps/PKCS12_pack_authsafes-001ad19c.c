
int PKCS12_pack_authsafes(PKCS12 *p12,stack_st_PKCS7 *safes)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = ASN1_item_pack(safes,(ASN1_ITEM *)PKCS12_AUTHSAFES_it,&(p12->authsafes->d).data);
  if (pAVar1 != (ASN1_STRING *)0x0) {
    pAVar1 = (ASN1_STRING *)0x1;
  }
  return (int)pAVar1;
}

