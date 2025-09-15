
int OCSP_id_issuer_cmp(OCSP_CERTID *a,OCSP_CERTID *b)

{
  int iVar1;
  
  iVar1 = OBJ_cmp(a->hashAlgorithm->algorithm,b->hashAlgorithm->algorithm);
  if ((iVar1 == 0) &&
     (iVar1 = ASN1_OCTET_STRING_cmp(a->issuerNameHash,b->issuerNameHash), iVar1 == 0)) {
    iVar1 = ASN1_OCTET_STRING_cmp(a->issuerKeyHash,b->issuerKeyHash);
    return iVar1;
  }
  return iVar1;
}

