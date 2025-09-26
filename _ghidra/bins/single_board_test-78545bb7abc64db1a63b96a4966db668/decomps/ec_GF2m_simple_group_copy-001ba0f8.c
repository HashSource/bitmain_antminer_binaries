
undefined4 ec_GF2m_simple_group_copy(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  BIGNUM *pBVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x28),*(BIGNUM **)(param_2 + 0x28));
  if (((pBVar1 != (BIGNUM *)0x0) &&
      (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x44),*(BIGNUM **)(param_2 + 0x44)),
      pBVar1 != (BIGNUM *)0x0)) &&
     (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x48),*(BIGNUM **)(param_2 + 0x48)),
     pBVar1 != (BIGNUM *)0x0)) {
    iVar4 = *(int *)(param_2 + 0x2c);
    *(int *)(param_1 + 0x2c) = iVar4;
    uVar3 = *(undefined4 *)(param_2 + 0x30);
    iVar2 = iVar4 + 0x7e;
    if (-1 < iVar4 + 0x3f) {
      iVar2 = iVar4 + 0x3f;
    }
    *(undefined4 *)(param_1 + 0x30) = uVar3;
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_2 + 0x38);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
    uVar5 = *(undefined4 *)(param_2 + 0x40);
    *(undefined4 *)(param_1 + 0x40) = uVar5;
    iVar2 = bn_wexpand(*(undefined4 *)(param_1 + 0x44),iVar2 >> 6,uVar3,uVar5,param_4);
    if (iVar2 != 0) {
      iVar4 = *(int *)(param_1 + 0x2c) + 0x3f;
      iVar2 = *(int *)(param_1 + 0x2c) + 0x7e;
      if (-1 < iVar4) {
        iVar2 = iVar4;
      }
      iVar2 = bn_wexpand(*(undefined4 *)(param_1 + 0x48),iVar2 >> 6);
      if (iVar2 != 0) {
        bn_set_all_zero(*(undefined4 *)(param_1 + 0x44));
        bn_set_all_zero(*(undefined4 *)(param_1 + 0x48));
        return 1;
      }
    }
  }
  return 0;
}

