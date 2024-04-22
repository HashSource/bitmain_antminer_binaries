
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find(ENGINE **pe,int type)

{
  _STACK **pp_Var1;
  cmp *cmp;
  EVP_PKEY_ASN1_METHOD **ppEVar2;
  int iVar3;
  EVP_PKEY_ASN1_METHOD *pEVar4;
  ENGINE *e;
  _STACK *st;
  int *local_90;
  int local_8c [27];
  
  cmp = DAT_000bbf9c;
  pp_Var1 = DAT_000bbf94;
  do {
    st = *pp_Var1;
    local_90 = local_8c;
    local_8c[0] = type;
    if ((st == (_STACK *)0x0) || (iVar3 = sk_find(st,local_8c), iVar3 < 0)) {
      ppEVar2 = (EVP_PKEY_ASN1_METHOD **)OBJ_bsearch_(&local_90,DAT_000bbf98,0xc,4,cmp);
      if ((ppEVar2 == (EVP_PKEY_ASN1_METHOD **)0x0) ||
         (pEVar4 = *ppEVar2, pEVar4 == (EVP_PKEY_ASN1_METHOD *)0x0)) {
        pEVar4 = (EVP_PKEY_ASN1_METHOD *)0x0;
LAB_000bbf6c:
        if (pe != (ENGINE **)0x0) {
          e = ENGINE_get_pkey_asn1_meth_engine(type);
          *pe = e;
          if (e != (ENGINE *)0x0) {
            pEVar4 = ENGINE_get_pkey_asn1_meth(e,type);
          }
        }
        return pEVar4;
      }
    }
    else {
      pEVar4 = (EVP_PKEY_ASN1_METHOD *)sk_value(*pp_Var1,iVar3);
      if (pEVar4 == (EVP_PKEY_ASN1_METHOD *)0x0) goto LAB_000bbf6c;
    }
    if (-1 < *(int *)(pEVar4 + 8) << 0x1f) goto LAB_000bbf6c;
    type = *(int *)(pEVar4 + 4);
  } while( true );
}

