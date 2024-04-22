
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  _STACK **pp_Var1;
  int iVar2;
  char *pcVar3;
  int *data;
  uint uVar4;
  _STACK *st;
  int local_3c [8];
  
  uVar4 = id - 1;
  if (uVar4 < 9) {
LAB_000cbb12:
    if ((int)uVar4 < 9) {
      data = (int *)(DAT_000cbbf4 + uVar4 * 0x1c);
    }
    else {
      data = (int *)sk_value(*DAT_000cbbf0,uVar4 - 9);
    }
LAB_000cbb20:
    if (data[2] << 0x1e < 0) {
      CRYPTO_free((void *)data[4]);
      CRYPTO_free((void *)data[5]);
    }
LAB_000cbb32:
    pcVar3 = BUF_strdup(name);
    data[4] = (int)pcVar3;
    pcVar3 = BUF_strdup(sname);
    data[5] = (int)pcVar3;
    if ((data[4] == 0) || (pcVar3 == (char *)0x0)) {
      iVar2 = 0xe7;
LAB_000cbbc8:
      ERR_put_error(0x22,0x89,0x41,DAT_000cbbf8,iVar2);
      return 0;
    }
    *data = id;
    data[1] = trust;
    data[3] = (int)ck;
    data[6] = (int)arg;
    data[2] = data[2] & 1U | 2 | flags & 0xfffffffeU;
    pp_Var1 = DAT_000cbbf0;
    if (uVar4 == 0xffffffff) {
      st = *DAT_000cbbf0;
      if (st == (_STACK *)0x0) {
        st = sk_new(DAT_000cbbfc);
        iVar2 = 0xf7;
        *pp_Var1 = st;
        if (st == (_STACK *)0x0) goto LAB_000cbbc8;
      }
      iVar2 = sk_push(st,data);
      if (iVar2 == 0) {
        iVar2 = 0xfb;
        data = (int *)0x0;
        goto LAB_000cbbb4;
      }
    }
    data = (int *)0x1;
  }
  else {
    local_3c[0] = id;
    if (((*DAT_000cbbf0 != (_STACK *)0x0) && (iVar2 = sk_find(*DAT_000cbbf0,local_3c), iVar2 != -1))
       && (uVar4 = iVar2 + 9, iVar2 != -10)) {
      if (-1 < (int)uVar4) goto LAB_000cbb12;
      data = (int *)0x0;
      goto LAB_000cbb20;
    }
    data = (int *)CRYPTO_malloc(0x1c,DAT_000cbbf8,0xd6);
    iVar2 = 0xd7;
    if (data != (int *)0x0) {
      uVar4 = 0xffffffff;
      data[2] = 1;
      goto LAB_000cbb32;
    }
LAB_000cbbb4:
    ERR_put_error(0x22,0x89,0x41,DAT_000cbbf8,iVar2);
  }
  return (int)data;
}

