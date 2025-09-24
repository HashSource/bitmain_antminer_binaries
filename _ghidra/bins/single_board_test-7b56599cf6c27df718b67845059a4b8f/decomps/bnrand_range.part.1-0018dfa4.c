
undefined4 bnrand_range_part_1(undefined4 param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = BN_num_bits(param_3);
  if (iVar1 == 1) {
    BN_set_word(param_2,0);
  }
  else {
    iVar2 = BN_is_bit_set(param_3,iVar1 + -2);
    if ((iVar2 == 0) && (iVar2 = BN_is_bit_set(param_3,iVar1 + -3), iVar2 == 0)) {
      iVar1 = iVar1 + 1;
      iVar2 = 100;
      do {
        if (iVar1 == 0) {
          BN_set_word(param_2,0);
        }
        else {
          if (iVar1 < 0) {
            ERR_put_error(3,0x7f,0x76,"crypto/bn/bn_rand.c",0x5d);
            return 0;
          }
          iVar3 = bnrand_part_0(param_1,param_2,iVar1,0xffffffff,0);
          if (iVar3 == 0) {
            return 0;
          }
        }
        iVar3 = BN_cmp(param_2,param_3);
        if (-1 < iVar3) {
          iVar3 = BN_sub(param_2,param_2,param_3);
          if (iVar3 == 0) {
            return 0;
          }
          iVar3 = BN_cmp(param_2,param_3);
          if ((-1 < iVar3) && (iVar3 = BN_sub(param_2,param_2,param_3), iVar3 == 0)) {
            return 0;
          }
        }
        iVar2 = iVar2 + -1;
        if (iVar2 == 0) {
          ERR_put_error(3,0x8a,0x71,"crypto/bn/bn_rand.c",0x99);
          return 0;
        }
        iVar3 = BN_cmp(param_2,param_3);
      } while (-1 < iVar3);
    }
    else if (iVar1 == 0) {
      iVar1 = 100;
      do {
        BN_set_word(param_2,0);
        iVar1 = iVar1 + -1;
        if (iVar1 == 0) goto LAB_0018e0de;
        iVar2 = BN_cmp(param_2,param_3);
      } while (-1 < iVar2);
    }
    else {
      if (iVar1 < 0) {
        ERR_put_error(3,0x7f,0x76,"crypto/bn/bn_rand.c",0x5d);
        return 0;
      }
      iVar2 = 100;
      do {
        iVar3 = bnrand_part_0(param_1,param_2,iVar1,0xffffffff,0);
        if (iVar3 == 0) {
          return 0;
        }
        iVar2 = iVar2 + -1;
        if (iVar2 == 0) {
LAB_0018e0de:
          ERR_put_error(3,0x8a,0x71,"crypto/bn/bn_rand.c",0xa6);
          return 0;
        }
        iVar3 = BN_cmp(param_2,param_3);
      } while (-1 < iVar3);
    }
  }
  return 1;
}

