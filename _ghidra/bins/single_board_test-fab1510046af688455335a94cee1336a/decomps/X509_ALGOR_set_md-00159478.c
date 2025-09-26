
void X509_ALGOR_set_md(X509_ALGOR *alg,EVP_MD *md)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_TYPE *pAVar3;
  
  if ((int)(md->flags << 0x1c) < 0) {
    iVar1 = EVP_MD_type(md);
    pAVar2 = OBJ_nid2obj(iVar1);
    if (alg == (X509_ALGOR *)0x0) {
      return;
    }
    iVar1 = -1;
  }
  else {
    iVar1 = EVP_MD_type(md);
    pAVar2 = OBJ_nid2obj(iVar1);
    if (alg == (X509_ALGOR *)0x0) {
      return;
    }
    if (alg->parameter == (ASN1_TYPE *)0x0) {
      pAVar3 = ASN1_TYPE_new();
      alg->parameter = pAVar3;
      if (pAVar3 == (ASN1_TYPE *)0x0) {
        return;
      }
    }
    iVar1 = 5;
  }
  if (alg->algorithm != (ASN1_OBJECT *)0x0) {
    ASN1_OBJECT_free(alg->algorithm);
  }
  alg->algorithm = pAVar2;
  pAVar3 = alg->parameter;
  if (iVar1 == -1) {
    if (pAVar3 == (ASN1_TYPE *)0x0) {
      return;
    }
    ASN1_TYPE_free(pAVar3);
    alg->parameter = (ASN1_TYPE *)0x0;
    return;
  }
  ASN1_TYPE_set(pAVar3,iVar1,(void *)0x0);
  return;
}

