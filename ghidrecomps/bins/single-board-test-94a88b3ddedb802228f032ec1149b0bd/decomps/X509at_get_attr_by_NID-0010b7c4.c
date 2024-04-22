
int X509at_get_attr_by_NID(stack_st_X509_ATTRIBUTE *x,int nid,int lastpos)

{
  ASN1_OBJECT *b;
  uint uVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  uint uVar4;
  
  b = OBJ_nid2obj(nid);
  if (b == (ASN1_OBJECT *)0x0) {
    return -2;
  }
  if (x != (stack_st_X509_ATTRIBUTE *)0x0) {
    uVar4 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
    uVar1 = sk_num(&x->stack);
    if ((int)uVar4 < (int)uVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,uVar4);
        iVar3 = OBJ_cmp(*ppAVar2,b);
        if (iVar3 == 0) {
          return uVar4;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != uVar1);
    }
  }
  return -1;
}

