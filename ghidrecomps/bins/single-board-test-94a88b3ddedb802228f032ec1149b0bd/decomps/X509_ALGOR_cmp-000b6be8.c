
int X509_ALGOR_cmp(X509_ALGOR *a,X509_ALGOR *b)

{
  int iVar1;
  
  iVar1 = OBJ_cmp(a->algorithm,b->algorithm);
  if (iVar1 == 0) {
    if ((a->parameter != (ASN1_TYPE *)0x0) || (b->parameter != (ASN1_TYPE *)0x0)) {
      iVar1 = ASN1_TYPE_cmp(a->parameter,b->parameter);
      return iVar1;
    }
  }
  return iVar1;
}

