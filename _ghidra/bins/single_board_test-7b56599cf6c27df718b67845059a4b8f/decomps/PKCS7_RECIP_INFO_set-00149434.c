
int PKCS7_RECIP_INFO_set(PKCS7_RECIP_INFO *p7i,X509 *x509)

{
  int iVar1;
  X509_NAME *name;
  ASN1_INTEGER *a;
  ASN1_STRING *pAVar2;
  PKCS7_ISSUER_AND_SERIAL *pPVar3;
  code *pcVar4;
  
  iVar1 = ASN1_INTEGER_set(p7i->version,0);
  if (iVar1 != 0) {
    pPVar3 = p7i->issuer_and_serial;
    name = X509_get_issuer_name(x509);
    iVar1 = X509_NAME_set(&pPVar3->issuer,name);
    if (iVar1 != 0) {
      ASN1_INTEGER_free(p7i->issuer_and_serial->serial);
      pPVar3 = p7i->issuer_and_serial;
      a = X509_get_serialNumber(x509);
      pAVar2 = ASN1_INTEGER_dup(a);
      pPVar3->serial = pAVar2;
      if (pAVar2 != (ASN1_STRING *)0x0) {
        iVar1 = X509_get0_pubkey(x509);
        if (((iVar1 == 0) || (*(int *)(iVar1 + 0xc) == 0)) ||
           (pcVar4 = *(code **)(*(int *)(iVar1 + 0xc) + 0x5c), pcVar4 == (code *)0x0)) {
          iVar1 = 0x1e1;
        }
        else {
          iVar1 = (*pcVar4)(iVar1,2,0,p7i);
          if (iVar1 != -2) {
            if (0 < iVar1) {
              X509_up_ref(x509);
              p7i->cert = x509;
              return 1;
            }
            ERR_put_error(0x21,0x82,0x95,"crypto/pkcs7/pk7_lib.c",0x1ed);
            return 0;
          }
          iVar1 = 0x1e8;
        }
        ERR_put_error(0x21,0x82,0x96,"crypto/pkcs7/pk7_lib.c",iVar1);
      }
    }
  }
  return 0;
}

