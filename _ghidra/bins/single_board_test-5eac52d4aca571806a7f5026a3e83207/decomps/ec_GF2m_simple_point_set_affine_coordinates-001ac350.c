
undefined4
ec_GF2m_simple_point_set_affine_coordinates
          (undefined4 param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *a;
  
  if (param_4 == (BIGNUM *)0x0 || param_3 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xa3,0x43,"crypto/ec/ec2_smpl.c",0x11f);
    return 0;
  }
  pBVar1 = BN_copy(*(BIGNUM **)(param_2 + 8),param_3);
  if (pBVar1 != (BIGNUM *)0x0) {
    BN_set_negative(*(BIGNUM **)(param_2 + 8),0);
    pBVar1 = BN_copy(*(BIGNUM **)(param_2 + 0xc),param_4);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_set_negative(*(BIGNUM **)(param_2 + 0xc),0);
      a = *(BIGNUM **)(param_2 + 0x10);
      pBVar1 = BN_value_one();
      pBVar1 = BN_copy(a,pBVar1);
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_set_negative(*(BIGNUM **)(param_2 + 0x10),0);
        *(undefined4 *)(param_2 + 0x14) = 1;
        return 1;
      }
    }
  }
  return 0;
}

