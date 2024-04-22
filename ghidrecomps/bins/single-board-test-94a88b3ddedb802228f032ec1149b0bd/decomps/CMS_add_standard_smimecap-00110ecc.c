
int CMS_add_standard_smimecap(stack_st_X509_ALGOR **smcap)

{
  char *pcVar1;
  EVP_CIPHER *pEVar2;
  X509_ALGOR *alg;
  ASN1_OBJECT *pAVar3;
  _STACK *p_Var4;
  int iVar5;
  EVP_MD *pEVar6;
  
  pcVar1 = OBJ_nid2sn(0x1ab);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1ab);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x329);
  pEVar6 = EVP_get_digestbyname(pcVar1);
  if (pEVar6 != (EVP_MD *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x329);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x32d);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x32d);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x1a7);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1a7);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x1a3);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1a3);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x2c);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x2c);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) goto LAB_00110f0c;
  }
  pcVar1 = OBJ_nid2sn(0x25);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if ((pEVar2 != (EVP_CIPHER *)0x0) &&
     (iVar5 = CMS_add_simple_smimecap(smcap,0x25,0x80), iVar5 == 0)) {
    return 0;
  }
  pcVar1 = OBJ_nid2sn(0x25);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if ((pEVar2 != (EVP_CIPHER *)0x0) &&
     (iVar5 = CMS_add_simple_smimecap(smcap,0x25,0x40), iVar5 == 0)) {
    return 0;
  }
  pcVar1 = OBJ_nid2sn(0x1f);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    alg = X509_ALGOR_new();
    if (alg == (X509_ALGOR *)0x0) {
      return 0;
    }
    pAVar3 = OBJ_nid2obj(0x1f);
    X509_ALGOR_set0(alg,pAVar3,-1,(void *)0x0);
    p_Var4 = &(*smcap)->stack;
    if (p_Var4 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *smcap = (stack_st_X509_ALGOR *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_00110f0c;
    }
    iVar5 = sk_push(p_Var4,alg);
    if (iVar5 == 0) {
LAB_00110f0c:
      X509_ALGOR_free(alg);
      return 0;
    }
  }
  pcVar1 = OBJ_nid2sn(0x25);
  pEVar2 = EVP_get_cipherbyname(pcVar1);
  if (pEVar2 != (EVP_CIPHER *)0x0) {
    iVar5 = CMS_add_simple_smimecap(smcap,0x25,0x28);
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    return iVar5;
  }
  return 1;
}

