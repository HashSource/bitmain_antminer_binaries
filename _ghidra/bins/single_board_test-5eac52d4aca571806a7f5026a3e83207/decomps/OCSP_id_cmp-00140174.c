
int OCSP_id_cmp(OCSP_CERTID *a,OCSP_CERTID *b)

{
  int iVar1;
  
  iVar1 = OCSP_id_issuer_cmp(a,b);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = ASN1_INTEGER_cmp((ASN1_INTEGER *)&a[2].issuerKeyHash,(ASN1_INTEGER *)&b[2].issuerKeyHash);
  return iVar1;
}

