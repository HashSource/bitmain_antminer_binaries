
undefined4
X509v3_addr_validate_path(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((((*(int *)(param_1 + 0x50) != 0) && (iVar1 = OPENSSL_sk_num(), iVar1 != 0)) &&
      (*(int *)(param_1 + 0x1c) != 0)) &&
     (((iVar1 = *(int *)(param_1 + 0x50), iVar1 != 0 && (iVar2 = OPENSSL_sk_num(iVar1), 0 < iVar2))
      && (*(int *)(param_1 + 0x1c) != 0)))) {
    uVar3 = addr_validate_path_internal_part_4(param_1,iVar1,0,param_4);
    return uVar3;
  }
  *(undefined4 *)(param_1 + 0x60) = 1;
  return 0;
}

