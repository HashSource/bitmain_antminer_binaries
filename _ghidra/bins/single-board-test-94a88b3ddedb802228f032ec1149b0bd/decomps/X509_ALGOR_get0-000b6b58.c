
void X509_ALGOR_get0(ASN1_OBJECT **paobj,int *pptype,void **ppval,X509_ALGOR *algor)

{
  ASN1_TYPE *pAVar1;
  
  if (paobj != (ASN1_OBJECT **)0x0) {
    *paobj = algor->algorithm;
  }
  if (pptype != (int *)0x0) {
    pAVar1 = algor->parameter;
    if (pAVar1 == (ASN1_TYPE *)0x0) {
      *pptype = -1;
    }
    else {
      *pptype = pAVar1->type;
      if (ppval != (void **)0x0) {
        *ppval = (void *)pAVar1->value;
      }
    }
  }
  return;
}

