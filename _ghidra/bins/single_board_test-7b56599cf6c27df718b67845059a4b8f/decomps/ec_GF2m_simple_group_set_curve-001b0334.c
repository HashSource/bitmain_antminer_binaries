
undefined4
ec_GF2m_simple_group_set_curve(int param_1,BIGNUM *param_2,undefined4 param_3,undefined4 param_4)

{
  BIGNUM *pBVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x28),param_2);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar5 = param_1 + 0x2c;
    uVar2 = BN_GF2m_poly2arr(*(undefined4 *)(param_1 + 0x28),iVar5,6);
    if ((uVar2 & 0xfffffffd) == 4) {
      iVar3 = BN_GF2m_mod_arr(*(undefined4 *)(param_1 + 0x44),param_3,iVar5);
      if (iVar3 != 0) {
        iVar4 = *(int *)(param_1 + 0x2c) + 0x3f;
        iVar3 = *(int *)(param_1 + 0x2c) + 0x7e;
        if (-1 < iVar4) {
          iVar3 = iVar4;
        }
        iVar3 = bn_wexpand(*(undefined4 *)(param_1 + 0x44),iVar3 >> 6);
        if (iVar3 != 0) {
          bn_set_all_zero(*(undefined4 *)(param_1 + 0x44));
          iVar5 = BN_GF2m_mod_arr(*(undefined4 *)(param_1 + 0x48),param_4,iVar5);
          if (iVar5 != 0) {
            iVar3 = *(int *)(param_1 + 0x2c) + 0x3f;
            iVar5 = *(int *)(param_1 + 0x2c) + 0x7e;
            if (-1 < iVar3) {
              iVar5 = iVar3;
            }
            iVar5 = bn_wexpand(*(undefined4 *)(param_1 + 0x48),iVar5 >> 6);
            if (iVar5 != 0) {
              bn_set_all_zero(*(undefined4 *)(param_1 + 0x48));
              return 1;
            }
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xc3,0x83,"crypto/ec/ec2_smpl.c",0x6a);
    }
  }
  return 0;
}

