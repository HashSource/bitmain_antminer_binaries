
ASN1_OCTET_STRING * PKCS7_digest_from_attributes(stack_st_X509_ATTRIBUTE *sk)

{
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  b = OBJ_nid2obj(0x33);
  if (sk != (stack_st_X509_ATTRIBUTE *)0x0 && b != (ASN1_OBJECT *)0x0) {
    iVar3 = 0;
    do {
      iVar2 = sk_num(&sk->stack);
      if (iVar2 <= iVar3) {
        return (ASN1_OCTET_STRING *)0x0;
      }
      ppAVar1 = (ASN1_OBJECT **)sk_value(&sk->stack,iVar3);
      iVar2 = OBJ_cmp(*ppAVar1,b);
      iVar3 = iVar3 + 1;
    } while (iVar2 != 0);
    if ((ppAVar1[1] == (ASN1_OBJECT *)0x0) && (iVar3 = sk_num((_STACK *)ppAVar1[2]), iVar3 != 0)) {
      pvVar4 = sk_value((_STACK *)ppAVar1[2],0);
      if (pvVar4 != (void *)0x0) {
        return *(ASN1_OCTET_STRING **)((int)pvVar4 + 4);
      }
      return (ASN1_OCTET_STRING *)0x0;
    }
  }
  return (ASN1_OCTET_STRING *)0x0;
}

