
int X509_check_issued(X509 *issuer,X509 *subject)

{
  X509_NAME *pXVar1;
  X509_NAME *pXVar2;
  int iVar3;
  ASN1_INTEGER *x;
  uint uVar4;
  int *piVar5;
  int iVar6;
  AUTHORITY_KEYID *pAVar7;
  _STACK *p_Var8;
  
  pXVar1 = X509_get_subject_name(issuer);
  pXVar2 = X509_get_issuer_name(subject);
  iVar3 = X509_NAME_cmp(pXVar1,pXVar2);
  if (iVar3 != 0) {
    return 0x1d;
  }
  if (-1 < (int)(issuer->ex_flags << 0x17)) {
    x509v3_cache_extensions_part_7(issuer);
  }
  if (-1 < (int)(subject->ex_flags << 0x17)) {
    x509v3_cache_extensions_part_7(subject);
  }
  pAVar7 = subject->akid;
  if (pAVar7 != (AUTHORITY_KEYID *)0x0) {
    if (((pAVar7->keyid != (ASN1_STRING *)0x0) && (issuer->skid != (ASN1_STRING *)0x0)) &&
       (iVar3 = ASN1_OCTET_STRING_cmp(pAVar7->keyid,issuer->skid), iVar3 != 0)) {
      return 0x1e;
    }
    if (pAVar7->serial != (ASN1_INTEGER *)0x0) {
      x = X509_get_serialNumber(issuer);
      iVar3 = ASN1_INTEGER_cmp(x,pAVar7->serial);
      if (iVar3 != 0) {
        return 0x1f;
      }
    }
    p_Var8 = &pAVar7->issuer->stack;
    if (p_Var8 != (_STACK *)0x0) {
      iVar3 = 0;
      do {
        iVar6 = sk_num(p_Var8);
        if (iVar6 <= iVar3) goto LAB_000cbeb2;
        piVar5 = (int *)sk_value(p_Var8,iVar3);
        iVar3 = iVar3 + 1;
      } while (*piVar5 != 4);
      pXVar1 = (X509_NAME *)piVar5[1];
      if (pXVar1 != (X509_NAME *)0x0) {
        pXVar2 = X509_get_issuer_name(issuer);
        iVar3 = X509_NAME_cmp(pXVar1,pXVar2);
        if (iVar3 != 0) {
          return 0x1f;
        }
      }
    }
  }
LAB_000cbeb2:
  uVar4 = issuer->ex_flags;
  if ((int)(subject->ex_flags << 0x15) < 0) {
    if ((uVar4 & 2) != 0) {
      if ((issuer->ex_kusage & 0x80) == 0) {
        iVar3 = 0x27;
      }
      else {
        iVar3 = 0;
      }
      return iVar3;
    }
  }
  else if ((uVar4 & 2) != 0) {
    if ((issuer->ex_kusage & 4) == 0) {
      iVar3 = 0x20;
    }
    else {
      iVar3 = 0;
    }
    return iVar3;
  }
  return uVar4 & 2;
}

