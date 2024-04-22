
int X509V3_add1_i2d(stack_st_X509_EXTENSION **x,int nid,void *value,int crit,ulong flags)

{
  int iVar1;
  X509_EXTENSION *pXVar2;
  X509_EXTENSION *a;
  void *pvVar3;
  _STACK *st;
  uint uVar4;
  
  uVar4 = flags & 0xf;
  if (uVar4 == 1) {
LAB_000c6a84:
    pXVar2 = X509V3_EXT_i2d(nid,crit,value);
    if (pXVar2 == (X509_EXTENSION *)0x0) {
LAB_000c6ab4:
      ERR_put_error(0x22,0x8c,0x90,DAT_000c6ad4,0x151);
      return 0;
    }
    st = &(*x)->stack;
    if (st != (_STACK *)0x0) {
LAB_000c6a96:
      pvVar3 = (void *)sk_push(st,pXVar2);
      goto joined_r0x000c6a9c;
    }
    st = sk_new_null();
    *x = (stack_st_X509_EXTENSION *)st;
    if (st != (_STACK *)0x0) goto LAB_000c6a96;
LAB_000c6aae:
    iVar1 = -1;
  }
  else {
    iVar1 = X509v3_get_ext_by_NID(*x,nid,-1);
    if (iVar1 < 0) {
      if ((uVar4 == 5) || (uVar4 == 3)) {
        iVar1 = 0x66;
LAB_000c6a20:
        if ((flags & 0x10) == 0) {
          ERR_put_error(0x22,0x8c,iVar1,DAT_000c6ad4,0x167);
          return 0;
        }
        return 0;
      }
      goto LAB_000c6a84;
    }
    if (uVar4 != 4) {
      if (uVar4 == 0) {
        iVar1 = 0x91;
        goto LAB_000c6a20;
      }
      if (uVar4 != 5) {
        pXVar2 = X509V3_EXT_i2d(nid,crit,value);
        if (pXVar2 == (X509_EXTENSION *)0x0) goto LAB_000c6ab4;
        a = (X509_EXTENSION *)sk_value(&(*x)->stack,iVar1);
        X509_EXTENSION_free(a);
        pvVar3 = sk_set(&(*x)->stack,iVar1,pXVar2);
        if (pvVar3 != (void *)0x0) goto LAB_000c6a4a;
        goto LAB_000c6aae;
      }
      pvVar3 = sk_delete(&(*x)->stack,iVar1);
joined_r0x000c6a9c:
      if (pvVar3 == (void *)0x0) goto LAB_000c6aae;
    }
LAB_000c6a4a:
    iVar1 = 1;
  }
  return iVar1;
}

