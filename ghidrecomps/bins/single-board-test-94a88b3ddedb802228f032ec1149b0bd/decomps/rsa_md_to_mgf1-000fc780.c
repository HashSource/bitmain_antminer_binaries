
X509_ALGOR * rsa_md_to_mgf1(X509_ALGOR **param_1,EVP_MD *param_2)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *aobj;
  X509_ALGOR *pXVar3;
  ASN1_STRING *local_14;
  
  pXVar3 = (X509_ALGOR *)0x0;
  *param_1 = (X509_ALGOR *)0x0;
  local_14 = (ASN1_STRING *)0x0;
  iVar1 = EVP_MD_type(param_2);
  if (iVar1 == 0x40) {
    return (X509_ALGOR *)0x1;
  }
  iVar1 = EVP_MD_type(param_2);
  if (iVar1 == 0x40) {
LAB_000fc7b6:
    pAVar2 = ASN1_item_pack(pXVar3,DAT_000fc804,&local_14);
    if (pAVar2 != (ASN1_STRING *)0x0) {
      alg = X509_ALGOR_new();
      *param_1 = alg;
      if (alg != (X509_ALGOR *)0x0) {
        aobj = OBJ_nid2obj(0x38f);
        X509_ALGOR_set0(alg,aobj,0x10,local_14);
        local_14 = (ASN1_STRING *)0x0;
        goto LAB_000fc7e4;
      }
    }
  }
  else {
    pXVar3 = X509_ALGOR_new();
    if (pXVar3 != (X509_ALGOR *)0x0) {
      X509_ALGOR_set_md(pXVar3,param_2);
      goto LAB_000fc7b6;
    }
  }
  if (local_14 != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(local_14);
  }
LAB_000fc7e4:
  if (pXVar3 != (X509_ALGOR *)0x0) {
    X509_ALGOR_free(pXVar3);
  }
  pXVar3 = *param_1;
  if (pXVar3 != (X509_ALGOR *)0x0) {
    pXVar3 = (X509_ALGOR *)0x1;
  }
  return pXVar3;
}

