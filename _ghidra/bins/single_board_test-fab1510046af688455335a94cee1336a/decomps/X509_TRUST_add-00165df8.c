
int X509_TRUST_add(int id,int flags,ck *ck,char *name,int arg1,void *arg2)

{
  int iVar1;
  char *pcVar2;
  int *data;
  uint uVar3;
  int local_38 [7];
  
  uVar3 = id - 1;
  if (uVar3 < 8) {
LAB_00165e2e:
    if ((int)uVar3 < 8) {
      data = (int *)(trstandard + uVar3 * 0x18);
    }
    else {
      data = (int *)sk_value(trtable,uVar3 - 8);
    }
LAB_00165e3c:
    if (data[1] << 0x1e < 0) {
      CRYPTO_free((void *)data[3]);
    }
LAB_00165e48:
    pcVar2 = BUF_strdup(name);
    iVar1 = 0xce;
    data[3] = (int)pcVar2;
    if (pcVar2 == (char *)0x0) {
LAB_00165ee4:
      ERR_put_error(0xb,0x85,0x41,"x509_trs.c",iVar1);
      return (int)pcVar2;
    }
    *data = id;
    data[4] = arg1;
    data[2] = (int)ck;
    data[5] = (int)arg2;
    data[1] = data[1] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar3 == 0xffffffff) {
      if ((trtable == (_STACK *)0x0) &&
         (trtable = sk_new((cmp *)0x165a99), trtable == (_STACK *)0x0)) {
        iVar1 = 0xde;
        pcVar2 = (char *)0x0;
        trtable = (_STACK *)0x0;
        goto LAB_00165ee4;
      }
      iVar1 = sk_push(trtable,data);
      if (iVar1 == 0) {
        iVar1 = 0xe2;
        data = (int *)0x0;
        goto LAB_00165ec2;
      }
    }
    data = (int *)0x1;
  }
  else {
    local_38[0] = id;
    if (((trtable != (_STACK *)0x0) && (iVar1 = sk_find(trtable,local_38), iVar1 != -1)) &&
       (uVar3 = iVar1 + 8, iVar1 != -9)) {
      if (-1 < (int)uVar3) goto LAB_00165e2e;
      data = (int *)0x0;
      goto LAB_00165e3c;
    }
    data = (int *)CRYPTO_malloc(0x18,"x509_trs.c",0xc1);
    iVar1 = 0xc2;
    if (data != (int *)0x0) {
      uVar3 = 0xffffffff;
      data[1] = 1;
      goto LAB_00165e48;
    }
LAB_00165ec2:
    ERR_put_error(0xb,0x85,0x41,"x509_trs.c",iVar1);
  }
  return (int)data;
}

