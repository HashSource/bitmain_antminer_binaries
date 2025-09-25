
int X509_ALGOR_set0(X509_ALGOR *alg,ASN1_OBJECT *aobj,int ptype,void *pval)

{
  ASN1_TYPE *pAVar1;
  
  if (alg == (X509_ALGOR *)0x0) {
    return 0;
  }
  if (ptype != -1) {
    if (alg->parameter == (ASN1_TYPE *)0x0) {
      pAVar1 = ASN1_TYPE_new();
      alg->parameter = pAVar1;
      if (pAVar1 == (ASN1_TYPE *)0x0) {
        return 0;
      }
    }
    ASN1_OBJECT_free(alg->algorithm);
    alg->algorithm = aobj;
    if (ptype != 0) {
      ASN1_TYPE_set(alg->parameter,ptype,pval);
    }
    return 1;
  }
  ASN1_OBJECT_free(alg->algorithm);
  alg->algorithm = aobj;
  ASN1_TYPE_free(alg->parameter);
  alg->parameter = (ASN1_TYPE *)0x0;
  return 1;
}

