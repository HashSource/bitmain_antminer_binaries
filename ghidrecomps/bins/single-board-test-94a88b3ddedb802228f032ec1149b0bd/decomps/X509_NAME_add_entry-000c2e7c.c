
int X509_NAME_add_entry(X509_NAME *name,X509_NAME_ENTRY *ne,int loc,int set)

{
  bool bVar1;
  uint uVar2;
  X509_NAME_ENTRY *a;
  int iVar3;
  void *pvVar4;
  _STACK *sk;
  uint uVar5;
  
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  sk = &name->entries->stack;
  uVar2 = sk_num(sk);
  name->modified = 1;
  if (((int)uVar2 < loc) || (loc < 0)) {
    loc = uVar2;
    if (set == -1) goto LAB_000c2ee8;
LAB_000c2eac:
    loc = uVar2;
    if (uVar2 != 0) {
      pvVar4 = sk_value(sk,uVar2 - 1);
      uVar5 = *(int *)((int)pvVar4 + 8) + 1;
      uVar2 = (uint)(*(int *)((int)pvVar4 + 8) == -1);
      goto LAB_000c2eb6;
    }
  }
  else {
    if (set != -1) {
      bVar1 = loc < (int)uVar2;
      uVar2 = loc;
      if (bVar1) {
        pvVar4 = sk_value(sk,loc);
        uVar5 = *(uint *)((int)pvVar4 + 8);
        uVar2 = 1 - uVar5;
        if (1 < uVar5) {
          uVar2 = 0;
        }
        goto LAB_000c2eb6;
      }
      goto LAB_000c2eac;
    }
LAB_000c2ee8:
    if (loc != 0) {
      pvVar4 = sk_value(sk,loc - 1);
      uVar2 = 0;
      uVar5 = *(uint *)((int)pvVar4 + 8);
      goto LAB_000c2eb6;
    }
  }
  uVar2 = 1;
  uVar5 = loc;
LAB_000c2eb6:
  a = X509_NAME_ENTRY_dup(ne);
  if (a == (X509_NAME_ENTRY *)0x0) {
    return 0;
  }
  a->set = uVar5;
  iVar3 = sk_insert(sk,a,loc);
  if (iVar3 == 0) {
    ERR_put_error(0xb,0x71,0x41,DAT_000c2f70,0x10d);
    X509_NAME_ENTRY_free(a);
    return 0;
  }
  if ((uVar2 != 0) && (iVar3 = sk_num(sk), (int)(loc + 1U) < iVar3)) {
    do {
      pvVar4 = sk_value(sk,loc);
      loc = loc + 1;
      *(int *)((int)pvVar4 + 8) = *(int *)((int)pvVar4 + 8) + 1;
    } while (loc != iVar3 - 1U);
  }
  return 1;
}

