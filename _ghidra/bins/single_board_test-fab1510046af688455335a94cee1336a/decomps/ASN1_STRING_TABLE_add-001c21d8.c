
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  int *data;
  int iVar2;
  int iVar3;
  int local_3c [6];
  
  if (stable == (_STACK *)0x0) {
    stable = sk_new((cmp *)0x1c2011);
    if (stable != (_STACK *)0x0) goto LAB_001c21f4;
    iVar3 = 0xf2;
LAB_001c228c:
    iVar2 = 0;
    ERR_put_error(0xd,0x81,0x41,"a_strnid.c",iVar3);
  }
  else {
LAB_001c21f4:
    local_3c[0] = param_1;
    data = (int *)OBJ_bsearch_(local_3c,&tbl_standard,0x13,0x14,(cmp *)0x1c201d);
    if ((data == (int *)0x0) &&
       (((stable == (_STACK *)0x0 || (iVar3 = sk_find(stable,local_3c), iVar3 < 0)) ||
        (data = (int *)sk_value(stable,iVar3), data == (int *)0x0)))) {
      data = (int *)CRYPTO_malloc(0x14,"a_strnid.c",0xf6);
      if (data == (int *)0x0) {
        iVar3 = 0xf8;
        goto LAB_001c228c;
      }
      *data = param_1;
      data[4] = param_5 & 0xfffffffe | 1;
      bVar1 = true;
    }
    else {
      bVar1 = false;
      data[4] = param_5 & 0xfffffffe | data[4] & 1U;
    }
    data[3] = param_4;
    if (param_2 != -1) {
      data[1] = param_2;
    }
    if (param_3 != -1) {
      data[2] = param_3;
    }
    iVar2 = 1;
    if (bVar1) {
      sk_push(stable,data);
      iVar2 = 1;
    }
  }
  return iVar2;
}

