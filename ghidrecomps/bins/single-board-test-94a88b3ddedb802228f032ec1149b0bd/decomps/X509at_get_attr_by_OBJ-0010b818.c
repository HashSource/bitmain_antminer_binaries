
int X509at_get_attr_by_OBJ(stack_st_X509_ATTRIBUTE *sk,ASN1_OBJECT *obj,int lastpos)

{
  uint uVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  uint uVar4;
  
  if (sk != (stack_st_X509_ATTRIBUTE *)0x0) {
    uVar4 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
    uVar1 = sk_num(&sk->stack);
    if ((int)uVar4 < (int)uVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&sk->stack,uVar4);
        iVar3 = OBJ_cmp(*ppAVar2,obj);
        if (iVar3 == 0) {
          return uVar4;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != uVar1);
    }
  }
  return -1;
}

