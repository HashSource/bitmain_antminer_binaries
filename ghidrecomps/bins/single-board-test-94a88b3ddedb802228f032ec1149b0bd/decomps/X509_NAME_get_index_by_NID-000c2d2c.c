
int X509_NAME_get_index_by_NID(X509_NAME *name,int nid,int lastpos)

{
  ASN1_OBJECT *b;
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int iVar4;
  _STACK *p_Var5;
  
  b = OBJ_nid2obj(nid);
  if (b == (ASN1_OBJECT *)0x0) {
    return -2;
  }
  if (name != (X509_NAME *)0x0) {
    p_Var5 = &name->entries->stack;
    if (lastpos < 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = lastpos + 1;
    }
    iVar1 = sk_num(p_Var5);
    if (iVar4 < iVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var5,iVar4);
        iVar3 = OBJ_cmp(*ppAVar2,b);
        if (iVar3 == 0) {
          return iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != iVar1);
    }
  }
  return -1;
}

