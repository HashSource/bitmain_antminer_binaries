
undefined4 add_attribute(_STACK **param_1,int param_2,int param_3,void *param_4)

{
  _STACK *p_Var1;
  int iVar2;
  X509_ATTRIBUTE *pXVar3;
  void *pvVar4;
  int iVar5;
  
  p_Var1 = *param_1;
  if (p_Var1 == (_STACK *)0x0) {
    p_Var1 = sk_new_null();
    *param_1 = p_Var1;
    if (p_Var1 == (_STACK *)0x0) {
      return 0;
    }
  }
  else {
    for (iVar5 = 0; iVar2 = sk_num(p_Var1), iVar5 < iVar2; iVar5 = iVar5 + 1) {
      pXVar3 = (X509_ATTRIBUTE *)sk_value(*param_1,iVar5);
      iVar2 = OBJ_obj2nid(pXVar3->object);
      if (iVar2 == param_2) {
        X509_ATTRIBUTE_free(pXVar3);
        pXVar3 = X509_ATTRIBUTE_create(param_2,param_3,param_4);
        if (pXVar3 == (X509_ATTRIBUTE *)0x0) {
          return 0;
        }
        pvVar4 = sk_set(*param_1,iVar5,pXVar3);
        if (pvVar4 != (void *)0x0) {
          return 1;
        }
        X509_ATTRIBUTE_free(pXVar3);
        return 0;
      }
      p_Var1 = *param_1;
    }
  }
  pXVar3 = X509_ATTRIBUTE_create(param_2,param_3,param_4);
  if (pXVar3 == (X509_ATTRIBUTE *)0x0) {
    return 0;
  }
  iVar5 = sk_push(*param_1,pXVar3);
  if (iVar5 != 0) {
    return 1;
  }
  X509_ATTRIBUTE_free(pXVar3);
  return 0;
}

