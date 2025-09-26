
undefined4 X509v3_addr_subset(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int extraout_r1;
  undefined8 uVar5;
  
  if (param_1 == param_2 || param_1 == 0) {
    return 1;
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = X509v3_addr_inherits();
  if ((iVar1 != 0) || (iVar1 = X509v3_addr_inherits(param_2), iVar1 != 0)) {
    return 0;
  }
  OPENSSL_sk_set_cmp_func(param_2,0x179455);
  iVar1 = 0;
  iVar4 = extraout_r1;
  do {
    iVar4 = OPENSSL_sk_num(param_1,iVar4);
    if (iVar4 <= iVar1) {
      return 1;
    }
    iVar4 = OPENSSL_sk_value(param_1,iVar1);
    uVar2 = OPENSSL_sk_find(param_2,iVar4);
    iVar3 = OPENSSL_sk_value(param_2,uVar2);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4);
    iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4);
    X509v3_addr_get_afi();
    if (iVar3 != iVar4 && iVar4 != 0) {
      if (iVar3 == 0) {
        return 0;
      }
      uVar5 = addr_contains_part_1(iVar3);
      iVar4 = (int)((ulonglong)uVar5 >> 0x20);
      if ((int)uVar5 == 0) {
        return 0;
      }
    }
    iVar1 = iVar1 + 1;
  } while( true );
}

