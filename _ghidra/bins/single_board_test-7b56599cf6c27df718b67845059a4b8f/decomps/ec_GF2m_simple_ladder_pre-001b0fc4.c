
undefined4
ec_GF2m_simple_ladder_pre(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_4 + 0x14) != 0) {
    do {
      uVar2 = *(undefined4 *)(param_3 + 0x10);
      iVar1 = BN_num_bits((BIGNUM *)param_1[10]);
      iVar1 = BN_priv_rand(uVar2,iVar1 + -1,0xffffffff,0);
      if (iVar1 == 0) {
        iVar1 = 0x2bd;
        goto LAB_001b1004;
      }
      iVar1 = BN_is_zero(*(undefined4 *)(param_3 + 0x10));
    } while (iVar1 != 0);
    iVar1 = *param_1;
    if (*(code **)(iVar1 + 0x98) != (code *)0x0) {
      iVar1 = (**(code **)(iVar1 + 0x98))
                        (param_1,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x10),
                         param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar1 = *param_1;
    }
    iVar1 = (**(code **)(iVar1 + 0x88))
                      (param_1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_4 + 8),
                       *(undefined4 *)(param_3 + 0x10),param_5);
    if (iVar1 != 0) {
      do {
        uVar2 = *(undefined4 *)(param_2 + 0xc);
        iVar1 = BN_num_bits((BIGNUM *)param_1[10]);
        iVar1 = BN_priv_rand(uVar2,iVar1 + -1,0xffffffff,0);
        if (iVar1 == 0) {
          iVar1 = 0x2cc;
LAB_001b1004:
          ERR_put_error(0x10,0x120,3,"crypto/ec/ec2_smpl.c",iVar1);
          return 0;
        }
        iVar1 = BN_is_zero(*(undefined4 *)(param_2 + 0xc));
      } while (iVar1 != 0);
      iVar1 = *param_1;
      if (*(code **)(iVar1 + 0x98) != (code *)0x0) {
        iVar1 = (**(code **)(iVar1 + 0x98))
                          (param_1,*(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0xc),
                           param_5);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = *param_1;
      }
      iVar1 = (**(code **)(iVar1 + 0x8c))
                        (param_1,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_4 + 8),
                         param_5);
      if ((((iVar1 != 0) &&
           (iVar1 = (**(code **)(*param_1 + 0x8c))
                              (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10),
                               param_5), iVar1 != 0)) &&
          (iVar1 = BN_GF2m_add(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),
                               param_1[0x12]), iVar1 != 0)) &&
         ((iVar1 = (**(code **)(*param_1 + 0x88))
                             (param_1,*(undefined4 *)(param_2 + 0x10),
                              *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc),param_5
                             ), iVar1 != 0 &&
          (iVar1 = (**(code **)(*param_1 + 0x88))
                             (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 8),
                              *(undefined4 *)(param_2 + 0xc),param_5), iVar1 != 0)))) {
        *(undefined4 *)(param_3 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x14) = 0;
        return 1;
      }
    }
  }
  return 0;
}

