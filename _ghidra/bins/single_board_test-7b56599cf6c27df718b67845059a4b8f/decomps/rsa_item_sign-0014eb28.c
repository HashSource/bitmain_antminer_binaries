
undefined4 rsa_item_sign(void)

{
  undefined4 uVar1;
  int iVar2;
  ASN1_STRING *a;
  ASN1_STRING *pval;
  ASN1_OBJECT *pAVar3;
  X509_ALGOR *in_r3;
  X509_ALGOR *in_stack_00000000;
  int local_14;
  
  uVar1 = EVP_MD_CTX_pkey_ctx();
  iVar2 = RSA_pkey_ctx_ctrl(uVar1,0xffffffff,0x1006,0,&local_14);
  if (iVar2 < 1) {
    return 0;
  }
  if (local_14 == 6) {
    a = (ASN1_STRING *)rsa_ctx_to_pss_string(uVar1);
    if (a == (ASN1_STRING *)0x0) {
      return 0;
    }
    if (in_stack_00000000 != (X509_ALGOR *)0x0) {
      pval = ASN1_STRING_dup(a);
      if (pval == (ASN1_STRING *)0x0) {
        ASN1_STRING_free(a);
        return 0;
      }
      pAVar3 = OBJ_nid2obj(0x390);
      X509_ALGOR_set0(in_stack_00000000,pAVar3,0x10,pval);
    }
    pAVar3 = OBJ_nid2obj(0x390);
    X509_ALGOR_set0(in_r3,pAVar3,0x10,a);
    uVar1 = 3;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

