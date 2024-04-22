
void * X509at_get0_data_by_OBJ(stack_st_X509_ATTRIBUTE *x,ASN1_OBJECT *obj,int lastpos,int type)

{
  uint uVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  ASN1_TYPE *a;
  uint uVar6;
  
  if (x == (stack_st_X509_ATTRIBUTE *)0x0) {
    return (void *)0x0;
  }
  uVar5 = lastpos + 1U & ~((int)(lastpos + 1U) >> 0x1f);
  uVar1 = sk_num(&x->stack);
  if ((int)uVar1 <= (int)uVar5) {
    return (void *)0x0;
  }
  while( true ) {
    ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,uVar5);
    iVar3 = OBJ_cmp(*ppAVar2,obj);
    if (iVar3 == 0) break;
    uVar5 = uVar5 + 1;
    if (uVar5 == uVar1) {
      return (void *)0x0;
    }
  }
  if (lastpos < -1) {
    uVar6 = uVar5 + 1 & ~((int)(uVar5 + 1) >> 0x1f);
    uVar1 = sk_num(&x->stack);
    if ((int)uVar6 < (int)uVar1) {
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(&x->stack,uVar6);
        uVar6 = uVar6 + 1;
        iVar3 = OBJ_cmp(*ppAVar2,obj);
        if (iVar3 == 0) {
          return (void *)0x0;
        }
      } while (uVar6 != uVar1);
    }
  }
  iVar3 = sk_num(&x->stack);
  if ((int)uVar5 < iVar3) {
    pvVar4 = sk_value(&x->stack,uVar5);
  }
  else {
    pvVar4 = (void *)0x0;
  }
  if (lastpos + 2 < 0 == SCARRY4(lastpos,2)) {
    if (pvVar4 == (void *)0x0) {
      return (void *)0x0;
    }
LAB_0010b990:
    iVar3 = *(int *)((int)pvVar4 + 4);
  }
  else {
    iVar3 = *(int *)((int)pvVar4 + 4);
    if (iVar3 == 0) {
      iVar3 = sk_num(*(_STACK **)((int)pvVar4 + 8));
      if (iVar3 != 1) {
        return (void *)0x0;
      }
      goto LAB_0010b990;
    }
    if (*(int *)((int)pvVar4 + 8) == 0) {
      return (void *)0x0;
    }
  }
  if (iVar3 == 0) {
    iVar3 = sk_num(*(_STACK **)((int)pvVar4 + 8));
    if (0 < iVar3) {
      if (*(int *)((int)pvVar4 + 4) == 0) {
        a = (ASN1_TYPE *)sk_value(*(_STACK **)((int)pvVar4 + 8),0);
      }
      else {
        a = *(ASN1_TYPE **)((int)pvVar4 + 8);
      }
      if (a == (ASN1_TYPE *)0x0) {
        return (void *)0x0;
      }
      goto LAB_0010b99a;
    }
  }
  else {
    a = *(ASN1_TYPE **)((int)pvVar4 + 8);
    if (a != (ASN1_TYPE *)0x0) {
LAB_0010b99a:
      iVar3 = ASN1_TYPE_get(a);
      if (type == iVar3) {
        return (a->value).ptr;
      }
      ERR_put_error(0xb,0x8b,0x7a,DAT_0010ba38,0x170);
      return (void *)0x0;
    }
  }
  return (void *)0x0;
}

