
undefined4
ec_GF2m_simple_point_get_affine_coordinates
          (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  undefined4 uVar3;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xa2,0x6a,"crypto/ec/ec2_smpl.c",0x140);
    return 0;
  }
  a = *(BIGNUM **)(param_2 + 0x10);
  pBVar2 = BN_value_one();
  iVar1 = BN_cmp(a,pBVar2);
  if (iVar1 == 0) {
    uVar3 = 0;
    if (param_3 != (BIGNUM *)0x0) {
      pBVar2 = BN_copy(param_3,*(BIGNUM **)(param_2 + 8));
      if (pBVar2 == (BIGNUM *)0x0) {
        return 0;
      }
      BN_set_negative(param_3,0);
    }
    if (param_4 == (BIGNUM *)0x0) {
      uVar3 = 1;
    }
    else {
      pBVar2 = BN_copy(param_4,*(BIGNUM **)(param_2 + 0xc));
      if (pBVar2 != (BIGNUM *)0x0) {
        uVar3 = 1;
        BN_set_negative(param_4,0);
      }
    }
    return uVar3;
  }
  ERR_put_error(0x10,0xa2,0x42,"crypto/ec/ec2_smpl.c",0x146);
  return 0;
}

