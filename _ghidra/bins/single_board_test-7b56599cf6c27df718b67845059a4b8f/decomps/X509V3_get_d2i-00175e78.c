
void * X509V3_get_d2i(stack_st_X509_EXTENSION *x,int nid,int *crit,int *idx)

{
  int iVar1;
  X509_EXTENSION *ex;
  ASN1_OBJECT *pAVar2;
  X509_EXTENSION *ex_00;
  void *pvVar3;
  uint uVar4;
  int *piVar5;
  bool bVar6;
  
  if (x == (stack_st_X509_EXTENSION *)0x0) {
    if (idx == (int *)0x0) goto LAB_00175f10;
  }
  else {
    ex = (X509_EXTENSION *)idx;
    if (idx == (int *)0x0) {
      while( true ) {
        iVar1 = OPENSSL_sk_num(x);
        piVar5 = (int *)((int)idx + 1);
        if (iVar1 <= (int)idx) break;
        ex_00 = (X509_EXTENSION *)OPENSSL_sk_value(x,idx);
        pAVar2 = X509_EXTENSION_get_object(ex_00);
        iVar1 = OBJ_obj2nid(pAVar2);
        idx = piVar5;
        if ((nid == iVar1) && (bVar6 = ex != (X509_EXTENSION *)0x0, ex = ex_00, bVar6)) {
          if (crit == (int *)0x0) {
            return (void *)0x0;
          }
          *crit = -2;
          return (void *)0x0;
        }
      }
      if (ex != (X509_EXTENSION *)0x0) {
        if (crit != (int *)0x0) {
LAB_00175ef4:
          iVar1 = X509_EXTENSION_get_critical(ex);
          *crit = iVar1;
        }
LAB_00175efe:
        pvVar3 = X509V3_EXT_d2i(ex);
        return pvVar3;
      }
      goto LAB_00175f10;
    }
    for (uVar4 = *idx + 1U & ~((int)(*idx + 1U) >> 0x1f); iVar1 = OPENSSL_sk_num(x),
        (int)uVar4 < iVar1; uVar4 = uVar4 + 1) {
      ex = (X509_EXTENSION *)OPENSSL_sk_value(x,uVar4);
      pAVar2 = X509_EXTENSION_get_object(ex);
      iVar1 = OBJ_obj2nid(pAVar2);
      if (iVar1 == nid) {
        *idx = uVar4;
        if (ex != (X509_EXTENSION *)0x0) {
          if (crit == (int *)0x0) goto LAB_00175efe;
          goto LAB_00175ef4;
        }
        break;
      }
    }
  }
  *idx = -1;
LAB_00175f10:
  if (crit != (int *)0x0) {
    *crit = -1;
  }
  return (void *)0x0;
}

