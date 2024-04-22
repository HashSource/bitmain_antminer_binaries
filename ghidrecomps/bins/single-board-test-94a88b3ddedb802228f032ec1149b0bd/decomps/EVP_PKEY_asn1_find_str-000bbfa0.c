
EVP_PKEY_ASN1_METHOD * EVP_PKEY_asn1_find_str(ENGINE **pe,char *str,int len)

{
  _STACK **pp_Var1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  size_t sVar4;
  _STACK *p_Var5;
  int iVar6;
  int iVar7;
  char *__s;
  ENGINE *local_24;
  
  if (len == -1) {
    len = strlen(str);
  }
  if (pe != (ENGINE **)0x0) {
    pEVar2 = ENGINE_pkey_asn1_find_str(&local_24,str,len);
    if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) {
      iVar3 = ENGINE_init(local_24);
      if (iVar3 == 0) {
        pEVar2 = (EVP_PKEY_ASN1_METHOD *)0x0;
      }
      ENGINE_free(local_24);
      *pe = local_24;
      return pEVar2;
    }
    *pe = (ENGINE *)0x0;
  }
  iVar3 = DAT_000bc058;
  pp_Var1 = DAT_000bc054;
  iVar7 = 0;
  do {
    p_Var5 = *pp_Var1;
    if (p_Var5 == (_STACK *)0x0) {
      if (0xb < iVar7) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
    else {
      iVar6 = sk_num(p_Var5);
      if (iVar6 + 0xc <= iVar7) {
        return (EVP_PKEY_ASN1_METHOD *)0x0;
      }
    }
    if (iVar7 < 0) {
      pEVar2 = (EVP_PKEY_ASN1_METHOD *)0x0;
    }
    else if (iVar7 < 0xc) {
      pEVar2 = *(EVP_PKEY_ASN1_METHOD **)(iVar3 + iVar7 * 4);
    }
    else {
      pEVar2 = (EVP_PKEY_ASN1_METHOD *)sk_value(*pp_Var1,iVar7 + -0xc);
    }
    if (-1 < *(int *)(pEVar2 + 8) << 0x1f) {
      __s = *(char **)(pEVar2 + 0xc);
      sVar4 = strlen(__s);
      if ((sVar4 == len) && (iVar6 = strncasecmp(__s,str,len), iVar6 == 0)) {
        return pEVar2;
      }
    }
    iVar7 = iVar7 + 1;
  } while( true );
}

