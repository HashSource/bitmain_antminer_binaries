
undefined4
rsa_item_sign(int param_1,undefined4 param_2,undefined4 param_3,X509_ALGOR *param_4,
             X509_ALGOR *param_5)

{
  int iVar1;
  ASN1_STRING *a;
  ASN1_STRING *pval;
  ASN1_OBJECT *pAVar2;
  EVP_PKEY_CTX *ctx;
  int local_14;
  
  ctx = *(EVP_PKEY_CTX **)(param_1 + 0x10);
  iVar1 = EVP_PKEY_CTX_ctrl(ctx,6,-1,0x1006,0,&local_14);
  if (0 < iVar1) {
    if ((local_14 == 1) || (local_14 != 6)) {
      return 2;
    }
    a = (ASN1_STRING *)rsa_ctx_to_pss(ctx);
    if (a != (ASN1_STRING *)0x0) {
      if (param_5 != (X509_ALGOR *)0x0) {
        pval = ASN1_STRING_dup(a);
        if (pval == (ASN1_STRING *)0x0) {
          ASN1_STRING_free(a);
          return 0;
        }
        pAVar2 = OBJ_nid2obj(0x390);
        X509_ALGOR_set0(param_5,pAVar2,0x10,pval);
      }
      pAVar2 = OBJ_nid2obj(0x390);
      X509_ALGOR_set0(param_4,pAVar2,0x10,a);
      return 3;
    }
  }
  return 0;
}

