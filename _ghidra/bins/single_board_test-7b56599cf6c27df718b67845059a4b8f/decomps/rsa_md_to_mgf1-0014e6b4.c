
int rsa_md_to_mgf1(int *param_1,EVP_MD *param_2)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *aobj;
  X509_ALGOR *alg_00;
  ASN1_OCTET_STRING *local_1c [2];
  
  alg_00 = (X509_ALGOR *)0x0;
  *param_1 = 0;
  local_1c[0] = (ASN1_STRING *)0x0;
  if ((param_2 == (EVP_MD *)0x0) || (iVar1 = EVP_MD_type(param_2), iVar1 == 0x40)) {
    return 1;
  }
  iVar1 = EVP_MD_type(param_2);
  if (iVar1 != 0x40) {
    alg_00 = X509_ALGOR_new();
    if (alg_00 == (X509_ALGOR *)0x0) goto LAB_0014e726;
    X509_ALGOR_set_md(alg_00,param_2);
  }
  pAVar2 = ASN1_item_pack(alg_00,(ASN1_ITEM *)X509_ALGOR_it,local_1c);
  if (pAVar2 != (ASN1_STRING *)0x0) {
    alg = X509_ALGOR_new();
    *param_1 = (int)alg;
    if (alg != (X509_ALGOR *)0x0) {
      aobj = OBJ_nid2obj(0x38f);
      X509_ALGOR_set0(alg,aobj,0x10,local_1c[0]);
      local_1c[0] = (ASN1_STRING *)0x0;
    }
  }
LAB_0014e726:
  ASN1_STRING_free(local_1c[0]);
  X509_ALGOR_free(alg_00);
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

