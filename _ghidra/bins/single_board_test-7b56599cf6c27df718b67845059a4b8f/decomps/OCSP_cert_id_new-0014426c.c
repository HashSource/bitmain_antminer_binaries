
OCSP_CERTID *
OCSP_cert_id_new(EVP_MD *dgst,X509_NAME *issuerName,ASN1_BIT_STRING *issuerKey,
                ASN1_INTEGER *serialNumber)

{
  OCSP_CERTID *a;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_OCTET_STRING *pAVar3;
  uint local_64;
  uchar auStack_60 [64];
  
  a = OCSP_CERTID_new();
  if (a != (OCSP_CERTID *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)a->hashAlgorithm);
    iVar1 = EVP_MD_type(dgst);
    if (iVar1 == 0) {
      ERR_put_error(0x27,0x65,0x78,"crypto/ocsp/ocsp_lib.c",0x3a);
    }
    else {
      pAVar2 = OBJ_nid2obj(iVar1);
      a->hashAlgorithm = (X509_ALGOR *)pAVar2;
      if (pAVar2 != (ASN1_OBJECT *)0x0) {
        pAVar3 = (ASN1_OCTET_STRING *)ASN1_TYPE_new();
        a->issuerNameHash = pAVar3;
        if (pAVar3 != (ASN1_OCTET_STRING *)0x0) {
          pAVar3->length = 5;
          iVar1 = X509_NAME_digest(issuerName,dgst,auStack_60,&local_64);
          if (iVar1 == 0) {
            ERR_put_error(0x27,0x65,0x66,"crypto/ocsp/ocsp_lib.c",0x55);
          }
          else {
            iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)&a->issuerKeyHash,auStack_60,local_64);
            if (iVar1 != 0) {
              iVar1 = EVP_Digest(issuerKey->data,issuerKey->length,auStack_60,&local_64,dgst,
                                 (ENGINE *)0x0);
              if (((iVar1 != 0) &&
                  (iVar1 = ASN1_OCTET_STRING_set
                                     ((ASN1_STRING *)&a[1].issuerKeyHash,auStack_60,local_64),
                  iVar1 != 0)) &&
                 ((serialNumber == (ASN1_INTEGER *)0x0 ||
                  (iVar1 = ASN1_STRING_copy((ASN1_STRING *)&a[2].issuerKeyHash,serialNumber),
                  iVar1 != 0)))) {
                return a;
              }
            }
          }
        }
      }
    }
  }
  OCSP_CERTID_free(a);
  return (OCSP_CERTID *)0x0;
}

