
OCSP_CERTID *
OCSP_cert_id_new(EVP_MD *dgst,X509_NAME *issuerName,ASN1_BIT_STRING *issuerKey,
                ASN1_INTEGER *serialNumber)

{
  OCSP_CERTID *a;
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  ASN1_STRING *pAVar4;
  X509_ALGOR *pXVar5;
  uint local_64;
  uchar auStack_60 [68];
  
  a = OCSP_CERTID_new();
  if (a == (OCSP_CERTID *)0x0) {
    return (OCSP_CERTID *)0x0;
  }
  pXVar5 = a->hashAlgorithm;
  if (pXVar5->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(pXVar5->algorithm);
  }
  iVar1 = EVP_MD_type(dgst);
  if (iVar1 == 0) {
    ERR_put_error(0x27,0x65,0x78,DAT_0010f2d0,0x75);
  }
  else {
    pAVar2 = OBJ_nid2obj(iVar1);
    pXVar5->algorithm = pAVar2;
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      pAVar3 = ASN1_TYPE_new();
      pXVar5->parameter = pAVar3;
      if (pAVar3 != (ASN1_TYPE *)0x0) {
        pAVar3->type = 5;
        iVar1 = X509_NAME_digest(issuerName,dgst,auStack_60,&local_64);
        if (iVar1 == 0) {
          ERR_put_error(0x27,0x65,0x66,DAT_0010f2d0,0x91);
          OCSP_CERTID_free(a);
          return (OCSP_CERTID *)0x0;
        }
        iVar1 = ASN1_OCTET_STRING_set(a->issuerNameHash,auStack_60,local_64);
        if (((iVar1 != 0) &&
            (iVar1 = EVP_Digest(issuerKey->data,issuerKey->length,auStack_60,&local_64,dgst,
                                (ENGINE *)0x0), iVar1 != 0)) &&
           (iVar1 = ASN1_OCTET_STRING_set(a->issuerKeyHash,auStack_60,local_64), iVar1 != 0)) {
          if (serialNumber == (ASN1_INTEGER *)0x0) {
            return a;
          }
          ASN1_INTEGER_free(a->serialNumber);
          pAVar4 = ASN1_INTEGER_dup(serialNumber);
          a->serialNumber = pAVar4;
          if (pAVar4 != (ASN1_STRING *)0x0) {
            return a;
          }
        }
      }
    }
  }
  OCSP_CERTID_free(a);
  return (OCSP_CERTID *)0x0;
}

