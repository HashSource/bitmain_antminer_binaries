
undefined4 bn_rand_range(int param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  pcVar5 = DAT_000f2298;
  if (param_1 == 0) {
    pcVar5 = DAT_000f2294;
  }
  if ((param_3->neg == 0) && (param_3->top != 0)) {
    iVar2 = BN_num_bits(param_3);
    if (iVar2 == 1) {
      BN_set_word(param_2,0);
      uVar1 = 1;
    }
    else {
      iVar3 = BN_is_bit_set(param_3,iVar2 + -2);
      if ((iVar3 == 0) && (iVar3 = BN_is_bit_set(param_3,iVar2 + -3), iVar3 == 0)) {
        iVar3 = 100;
        do {
          iVar4 = (*pcVar5)(param_2,iVar2 + 1,0xffffffff,0);
          if ((iVar4 == 0) ||
             ((iVar4 = BN_cmp(param_2,param_3), -1 < iVar4 &&
              ((iVar4 = BN_sub(param_2,param_2,param_3), iVar4 == 0 ||
               ((iVar4 = BN_cmp(param_2,param_3), -1 < iVar4 &&
                (iVar4 = BN_sub(param_2,param_2,param_3), iVar4 == 0)))))))) {
            return 0;
          }
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            iVar2 = 0x107;
LAB_000f227a:
            ERR_put_error(3,0x7a,0x71,DAT_000f229c,iVar2);
            return 0;
          }
          iVar4 = BN_cmp(param_2,param_3);
        } while (-1 < iVar4);
      }
      else {
        iVar3 = 100;
        do {
          iVar4 = (*pcVar5)(param_2,iVar2,0xffffffff,0);
          if (iVar4 == 0) {
            return 0;
          }
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            iVar2 = 0x114;
            goto LAB_000f227a;
          }
          iVar4 = BN_cmp(param_2,param_3);
        } while (-1 < iVar4);
      }
      uVar1 = 1;
    }
  }
  else {
    ERR_put_error(3,0x7a,0x73,DAT_000f229c,0xe6);
    uVar1 = 0;
  }
  return uVar1;
}

