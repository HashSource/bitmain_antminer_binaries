
X509_NAME_ENTRY * X509_NAME_delete_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  void *pvVar3;
  _STACK *st;
  int iVar4;
  
  if (((name != (X509_NAME *)0x0) && (iVar1 = sk_num(&name->entries->stack), loc < iVar1)) &&
     (-1 < loc)) {
    st = &name->entries->stack;
    pXVar2 = (X509_NAME_ENTRY *)sk_delete(st,loc);
    iVar1 = sk_num(st);
    name->modified = 1;
    if (loc != iVar1) {
      if (loc == 0) {
        iVar4 = pXVar2->set + -1;
      }
      else {
        pvVar3 = sk_value(st,loc + -1);
        iVar4 = *(int *)((int)pvVar3 + 8);
      }
      pvVar3 = sk_value(st,loc);
      if ((iVar4 + 1 < *(int *)((int)pvVar3 + 8)) && (loc < iVar1)) {
        do {
          pvVar3 = sk_value(st,loc);
          loc = loc + 1;
          *(int *)((int)pvVar3 + 8) = *(int *)((int)pvVar3 + 8) + -1;
        } while (loc != iVar1);
      }
    }
    return pXVar2;
  }
  return (X509_NAME_ENTRY *)0x0;
}

