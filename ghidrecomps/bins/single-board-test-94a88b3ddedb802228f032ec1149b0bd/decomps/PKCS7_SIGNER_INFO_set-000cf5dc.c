
int PKCS7_SIGNER_INFO_set(PKCS7_SIGNER_INFO *p7i,X509 *x509,EVP_PKEY *pkey,EVP_MD *dgst)

{
  int iVar1;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar2;
  ASN1_OBJECT *aobj;
  X509_ALGOR *alg;
  code *pcVar3;
  PKCS7_ISSUER_AND_SERIAL *pPVar4;
  
  iVar1 = ASN1_INTEGER_set(p7i->version,1);
  if (iVar1 != 0) {
    pPVar4 = p7i->issuer_and_serial;
    name = X509_get_issuer_name(x509);
    iVar1 = X509_NAME_set(&pPVar4->issuer,name);
    if (iVar1 != 0) {
      ASN1_STRING_free(p7i->issuer_and_serial->serial);
      pPVar4 = p7i->issuer_and_serial;
      a = X509_get_serialNumber(x509);
      pAVar2 = ASN1_STRING_dup(a);
      pPVar4->serial = pAVar2;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        CRYPTO_add_lock(&pkey->references,1,10,DAT_000cf6a4,0x179);
        alg = p7i->digest_alg;
        p7i->pkey = pkey;
        iVar1 = EVP_MD_type(dgst);
        aobj = OBJ_nid2obj(iVar1);
        X509_ALGOR_set0(alg,aobj,5,(void *)0x0);
        if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
           (pcVar3 = *(code **)(pkey->ameth + 0x58), pcVar3 != (code *)0x0)) {
          iVar1 = (*pcVar3)(pkey,1,0,p7i);
          if (0 < iVar1) {
            return 1;
          }
          if (iVar1 != -2) {
            ERR_put_error(0x21,0x81,0x93,DAT_000cf6a4,0x187);
            return 0;
          }
        }
        ERR_put_error(0x21,0x81,0x94,DAT_000cf6a4,0x18c);
        return 0;
      }
    }
  }
  return 0;
}

