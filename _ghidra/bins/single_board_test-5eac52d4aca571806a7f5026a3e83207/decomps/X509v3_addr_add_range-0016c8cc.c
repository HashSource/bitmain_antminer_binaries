
undefined4
X509v3_addr_add_range(undefined4 param_1,int param_2,undefined4 param_3,void *param_4,void *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  size_t __n;
  IPAddressOrRange *local_1c [2];
  
  iVar1 = make_IPAddressFamily();
  if (iVar1 == 0) {
    return 0;
  }
  piVar3 = *(int **)(iVar1 + 4);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  if (*piVar3 == 0) {
    if (piVar3[1] != 0) {
      return 0;
    }
LAB_0016c8e8:
    iVar2 = OPENSSL_sk_new_null();
    if (iVar2 == 0) {
      return 0;
    }
    if (param_2 == 1) {
      OPENSSL_sk_set_cmp_func(iVar2,0x16b651);
    }
    else if (param_2 == 2) {
      OPENSSL_sk_set_cmp_func(iVar2,0x16b7dd);
    }
    puVar4 = *(undefined4 **)(iVar1 + 4);
    *puVar4 = 1;
    puVar4[1] = iVar2;
  }
  else if ((*piVar3 != 1) || (iVar2 = piVar3[1], iVar2 == 0)) goto LAB_0016c8e8;
  if (param_2 == 1) {
    __n = 4;
  }
  else {
    if (param_2 != 2) {
      __n = 0;
      goto LAB_0016c93c;
    }
    __n = 0x10;
  }
  iVar1 = memcmp(param_4,param_5,__n);
  if (0 < iVar1) {
    return 0;
  }
LAB_0016c93c:
  iVar1 = range_should_be_prefix(param_4,param_5,__n);
  if (iVar1 < 0) {
    iVar1 = make_addressRange_part_2(local_1c,param_4,param_5,__n);
  }
  else {
    iVar1 = make_addressPrefix(local_1c);
  }
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = OPENSSL_sk_push(iVar2,local_1c[0]);
  if (iVar1 == 0) {
    IPAddressOrRange_free(local_1c[0]);
    return 0;
  }
  return 1;
}

