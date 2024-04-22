
void * X509V3_get_d2i(stack_st_X509_EXTENSION *x,int nid,int *crit,int *idx)

{
  int iVar1;
  X509_EXTENSION *ex;
  void *pvVar2;
  X509_EXTENSION *pXVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  if (x != (stack_st_X509_EXTENSION *)0x0) {
    if (idx == (int *)0x0) {
      iVar5 = 0;
      ex = (X509_EXTENSION *)0x0;
      while( true ) {
        iVar1 = sk_num(&x->stack);
        iVar4 = iVar5 + 1;
        if (iVar1 <= iVar5) break;
        pXVar3 = (X509_EXTENSION *)sk_value(&x->stack,iVar5);
        iVar1 = OBJ_obj2nid(pXVar3->object);
        iVar5 = iVar4;
        if ((iVar1 == nid) && (bVar6 = ex != (X509_EXTENSION *)0x0, ex = pXVar3, bVar6)) {
          if (crit == (int *)0x0) {
            return (void *)0x0;
          }
          *crit = -2;
          return (void *)0x0;
        }
      }
      if (ex != (X509_EXTENSION *)0x0) {
LAB_000c696e:
        if (crit != (int *)0x0) {
          iVar5 = X509_EXTENSION_get_critical(ex);
          *crit = iVar5;
        }
        pvVar2 = X509V3_EXT_d2i(ex);
        return pvVar2;
      }
      goto LAB_000c6990;
    }
    iVar5 = *idx + 1;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    for (; iVar1 = sk_num(&x->stack), iVar5 < iVar1; iVar5 = iVar5 + 1) {
      ex = (X509_EXTENSION *)sk_value(&x->stack,iVar5);
      iVar1 = OBJ_obj2nid(ex->object);
      if (iVar1 == nid) {
        *idx = iVar5;
        goto LAB_000c696e;
      }
    }
  }
  if (idx != (int *)0x0) {
    *idx = -1;
  }
LAB_000c6990:
  if (crit != (int *)0x0) {
    *crit = -1;
  }
  return (void *)0x0;
}

