
int X509_ALGOR_set0(X509_ALGOR *alg,ASN1_OBJECT *aobj,int ptype,void *pval)

{
  ASN1_TYPE *pAVar1;
  
  if (alg == (X509_ALGOR *)0x0) {
    return 0;
  }
  if ((ptype != -1) && (alg->parameter == (ASN1_TYPE *)0x0)) {
    pAVar1 = ASN1_TYPE_new();
    alg->parameter = pAVar1;
    if (pAVar1 == (ASN1_TYPE *)0x0) {
      return 0;
    }
  }
  if (alg->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(alg->algorithm);
  }
  alg->algorithm = aobj;
  if (ptype != 0) {
    pAVar1 = alg->parameter;
    if (ptype != -1) {
      ASN1_TYPE_set(pAVar1,ptype,pval);
      return 1;
    }
    if (pAVar1 != (ASN1_TYPE *)0x0) {
      ASN1_TYPE_free(pAVar1);
      alg->parameter = (ASN1_TYPE *)0x0;
      return 1;
    }
  }
  return 1;
}

