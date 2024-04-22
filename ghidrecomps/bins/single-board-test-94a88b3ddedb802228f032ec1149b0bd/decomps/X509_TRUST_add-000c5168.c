
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  _STACK **pp_Var1;
  int iVar2;
  char *pcVar3;
  int *data;
  uint uVar4;
  _STACK *st;
  int local_38 [7];
  
  uVar4 = id - 1;
  if (uVar4 < 8) {
LAB_000c519e:
    if ((int)uVar4 < 8) {
      data = (int *)(DAT_000c5270 + uVar4 * 0x18);
    }
    else {
      data = (int *)sk_value(*DAT_000c526c,uVar4 - 8);
    }
LAB_000c51ac:
    if (data[1] << 0x1e < 0) {
      CRYPTO_free((void *)data[3]);
    }
LAB_000c51b8:
    pcVar3 = BUF_strdup(name);
    iVar2 = 0xce;
    data[3] = (int)pcVar3;
    if (pcVar3 == (char *)0x0) {
LAB_000c5254:
      ERR_put_error(0xb,0x85,0x41,DAT_000c5274,iVar2);
      return (int)pcVar3;
    }
    *data = id;
    data[4] = arg1;
    data[2] = (int)ck;
    data[5] = (int)arg2;
    data[1] = data[1] & 1U | 2 | flags & 0xfffffffeU;
    pp_Var1 = DAT_000c526c;
    if (uVar4 == 0xffffffff) {
      st = *DAT_000c526c;
      if (st == (_STACK *)0x0) {
        st = sk_new(DAT_000c5278);
        *pp_Var1 = st;
        if (st == (_STACK *)0x0) {
          iVar2 = 0xde;
          pcVar3 = (char *)0x0;
          goto LAB_000c5254;
        }
      }
      iVar2 = sk_push(st,data);
      if (iVar2 == 0) {
        iVar2 = 0xe2;
        data = (int *)0x0;
        goto LAB_000c5232;
      }
    }
    data = (int *)0x1;
  }
  else {
    local_38[0] = id;
    if (((*DAT_000c526c != (_STACK *)0x0) && (iVar2 = sk_find(*DAT_000c526c,local_38), iVar2 != -1))
       && (uVar4 = iVar2 + 8, iVar2 != -9)) {
      if (-1 < (int)uVar4) goto LAB_000c519e;
      data = (int *)0x0;
      goto LAB_000c51ac;
    }
    data = (int *)CRYPTO_malloc(0x18,DAT_000c5274,0xc1);
    iVar2 = 0xc2;
    if (data != (int *)0x0) {
      uVar4 = 0xffffffff;
      data[1] = 1;
      goto LAB_000c51b8;
    }
LAB_000c5232:
    ERR_put_error(0xb,0x85,0x41,DAT_000c5274,iVar2);
  }
  return (int)data;
}

