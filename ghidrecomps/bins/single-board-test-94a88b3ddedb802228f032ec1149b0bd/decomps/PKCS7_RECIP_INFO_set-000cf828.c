
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i,X509 *x509)

{
  int iVar1;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar2;
  EVP_PKEY *pkey;
  PKCS7_ISSUER_AND_SERIAL *pPVar3;
  code *pcVar4;
  
  iVar1 = ASN1_INTEGER_set(p7i->version,0);
  if (iVar1 == 0) {
    return 0;
  }
  pPVar3 = p7i->issuer_and_serial;
  name = X509_get_issuer_name(x509);
  iVar1 = X509_NAME_set(&pPVar3->issuer,name);
  if (iVar1 == 0) {
    return 0;
  }
  ASN1_STRING_free(p7i->issuer_and_serial->serial);
  pPVar3 = p7i->issuer_and_serial;
  a = X509_get_serialNumber(x509);
  pAVar2 = ASN1_STRING_dup(a);
  pPVar3->serial = pAVar2;
  if (pAVar2 == (ASN1_STRING *)0x0) {
    return 0;
  }
  pkey = X509_get_pubkey(x509);
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x21,0x82,0x96,DAT_000cf8fc,0x217);
    return 0;
  }
  if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (pcVar4 = *(code **)(pkey->ameth + 0x58), pcVar4 == (code *)0x0)) {
    iVar1 = 0x217;
  }
  else {
    iVar1 = (*pcVar4)(pkey,2,0,p7i);
    if (iVar1 != -2) {
      if (0 < iVar1) {
        EVP_PKEY_free(pkey);
        CRYPTO_add_lock(&x509->references,1,3,DAT_000cf8fc,0x229);
        p7i->cert = x509;
        return 1;
      }
      ERR_put_error(0x21,0x82,0x95,DAT_000cf8fc,0x223);
      goto LAB_000cf8ca;
    }
    iVar1 = 0x21e;
  }
  ERR_put_error(0x21,0x82,0x96,DAT_000cf8fc,iVar1);
LAB_000cf8ca:
  EVP_PKEY_free(pkey);
  return 0;
}

