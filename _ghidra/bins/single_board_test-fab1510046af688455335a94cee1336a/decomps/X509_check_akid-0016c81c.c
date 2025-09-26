
int X509_check_akid(X509 *issuer,AUTHORITY_KEYID *akid)

{
  int iVar1;
  ASN1_INTEGER *x;
  int *piVar2;
  int iVar3;
  X509_NAME *b;
  X509_NAME *a;
  _STACK *p_Var4;
  
  if (akid != (AUTHORITY_KEYID *)0x0) {
    if (((akid->keyid != (ASN1_STRING *)0x0) && (issuer->skid != (ASN1_STRING *)0x0)) &&
       (iVar1 = ASN1_OCTET_STRING_cmp(akid->keyid,issuer->skid), iVar1 != 0)) {
      return 0x1e;
    }
    if (akid->serial != (ASN1_INTEGER *)0x0) {
      x = X509_get_serialNumber(issuer);
      iVar1 = ASN1_INTEGER_cmp(x,akid->serial);
      if (iVar1 != 0) {
        return 0x1f;
      }
    }
    p_Var4 = &akid->issuer->stack;
    if (p_Var4 != (_STACK *)0x0) {
      iVar1 = 0;
      do {
        iVar3 = sk_num(p_Var4);
        if (iVar3 <= iVar1) {
          return 0;
        }
        piVar2 = (int *)sk_value(p_Var4,iVar1);
        iVar1 = iVar1 + 1;
      } while (*piVar2 != 4);
      a = (X509_NAME *)piVar2[1];
      if (a != (X509_NAME *)0x0) {
        b = X509_get_issuer_name(issuer);
        iVar1 = X509_NAME_cmp(a,b);
        if (iVar1 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0x1f;
        }
        return iVar1;
      }
    }
  }
  return 0;
}

