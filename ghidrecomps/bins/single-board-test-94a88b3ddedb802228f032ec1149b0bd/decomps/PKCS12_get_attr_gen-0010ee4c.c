
ASN1_TYPE * PKCS12_get_attr_gen(stack_st_X509_ATTRIBUTE *attrs,int attr_nid)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  ASN1_TYPE *pAVar4;
  
  if (attrs != (stack_st_X509_ATTRIBUTE *)0x0) {
    iVar3 = 0;
    do {
      iVar2 = sk_num(&attrs->stack);
      if (iVar2 <= iVar3) {
        return (ASN1_TYPE *)0x0;
      }
      ppAVar1 = (ASN1_OBJECT **)sk_value(&attrs->stack,iVar3);
      iVar2 = OBJ_obj2nid(*ppAVar1);
      iVar3 = iVar3 + 1;
    } while (iVar2 != attr_nid);
    iVar3 = sk_num((_STACK *)ppAVar1[2]);
    if (iVar3 != 0) {
      pAVar4 = (ASN1_TYPE *)sk_value((_STACK *)ppAVar1[2],0);
      return pAVar4;
    }
  }
  return (ASN1_TYPE *)0x0;
}

