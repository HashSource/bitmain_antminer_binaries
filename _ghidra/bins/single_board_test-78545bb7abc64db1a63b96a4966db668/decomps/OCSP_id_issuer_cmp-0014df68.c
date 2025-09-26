
int OCSP_id_issuer_cmp(OCSP_CERTID *a,OCSP_CERTID *b)

{
  int iVar1;
  
  iVar1 = OBJ_cmp((ASN1_OBJECT *)a->hashAlgorithm,(ASN1_OBJECT *)b->hashAlgorithm);
  if ((iVar1 == 0) &&
     (iVar1 = ASN1_OCTET_STRING_cmp
                        ((ASN1_STRING *)&a->issuerKeyHash,(ASN1_STRING *)&b->issuerKeyHash),
     iVar1 == 0)) {
    iVar1 = ASN1_OCTET_STRING_cmp
                      ((ASN1_STRING *)&a[1].issuerKeyHash,(ASN1_STRING *)&b[1].issuerKeyHash);
    return iVar1;
  }
  return iVar1;
}

