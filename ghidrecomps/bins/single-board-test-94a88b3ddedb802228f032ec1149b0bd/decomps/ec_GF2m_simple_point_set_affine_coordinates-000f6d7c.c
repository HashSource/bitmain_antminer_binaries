
undefined4
ec_GF2m_simple_point_set_affine_coordinates
          (undefined4 param_1,int param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  BIGNUM *pBVar1;
  
  if (param_3 == (BIGNUM *)0x0 || param_4 == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xa3,0x43,DAT_000f6dfc,0x18c);
  }
  else {
    pBVar1 = BN_copy((BIGNUM *)(param_2 + 4),param_3);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_set_negative((BIGNUM *)(param_2 + 4),0);
      pBVar1 = BN_copy((BIGNUM *)(param_2 + 0x18),param_4);
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_set_negative((BIGNUM *)(param_2 + 0x18),0);
        pBVar1 = BN_value_one();
        pBVar1 = BN_copy((BIGNUM *)(param_2 + 0x2c),pBVar1);
        if (pBVar1 != (BIGNUM *)0x0) {
          BN_set_negative((BIGNUM *)(param_2 + 0x2c),0);
          *(undefined4 *)(param_2 + 0x40) = 1;
          return 1;
        }
      }
    }
  }
  return 0;
}

