
int X509_PURPOSE_add(int id,int trust,int flags,ck *ck,char *name,char *sname,void *arg)

{
  int iVar1;
  char *pcVar2;
  int *data;
  uint uVar3;
  int local_3c [8];
  
  uVar3 = id - 1;
  if (uVar3 < 9) {
LAB_0016c412:
    if ((int)uVar3 < 9) {
      data = (int *)(&xstandard + uVar3 * 0x1c);
    }
    else {
      data = (int *)sk_value(xptable,uVar3 - 9);
    }
LAB_0016c420:
    if (data[2] << 0x1e < 0) {
      CRYPTO_free((void *)data[4]);
      CRYPTO_free((void *)data[5]);
    }
LAB_0016c432:
    pcVar2 = BUF_strdup(name);
    data[4] = (int)pcVar2;
    pcVar2 = BUF_strdup(sname);
    data[5] = (int)pcVar2;
    if ((data[4] == 0) || (pcVar2 == (char *)0x0)) {
      iVar1 = 0xe7;
LAB_0016c4c8:
      ERR_put_error(0x22,0x89,0x41,"v3_purp.c",iVar1);
      return 0;
    }
    *data = id;
    data[1] = trust;
    data[3] = (int)ck;
    data[6] = (int)arg;
    data[2] = data[2] & 1U | 2 | flags & 0xfffffffeU;
    if (uVar3 == 0xffffffff) {
      if (xptable == (_STACK *)0x0) {
        xptable = sk_new((cmp *)0x16b9c1);
        iVar1 = 0xf7;
        if (xptable == (_STACK *)0x0) goto LAB_0016c4c8;
      }
      iVar1 = sk_push(xptable,data);
      if (iVar1 == 0) {
        iVar1 = 0xfb;
        data = (int *)0x0;
        goto LAB_0016c4b4;
      }
    }
    data = (int *)0x1;
  }
  else {
    local_3c[0] = id;
    if (((xptable != (_STACK *)0x0) && (iVar1 = sk_find(xptable,local_3c), iVar1 != -1)) &&
       (uVar3 = iVar1 + 9, iVar1 != -10)) {
      if (-1 < (int)uVar3) goto LAB_0016c412;
      data = (int *)0x0;
      goto LAB_0016c420;
    }
    data = (int *)CRYPTO_malloc(0x1c,"v3_purp.c",0xd6);
    iVar1 = 0xd7;
    if (data != (int *)0x0) {
      uVar3 = 0xffffffff;
      data[2] = 1;
      goto LAB_0016c432;
    }
LAB_0016c4b4:
    ERR_put_error(0x22,0x89,0x41,"v3_purp.c",iVar1);
  }
  return (int)data;
}

