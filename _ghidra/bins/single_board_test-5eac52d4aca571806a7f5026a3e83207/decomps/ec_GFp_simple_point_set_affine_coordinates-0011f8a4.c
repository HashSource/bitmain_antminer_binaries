
int ec_GFp_simple_point_set_affine_coordinates
              (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  BIGNUM *z;
  int iVar1;
  
  if (param_4 != (BIGNUM *)0x0 && param_3 != (BIGNUM *)0x0) {
    z = BN_value_one();
    iVar1 = EC_POINT_set_Jprojective_coordinates_GFp(param_1,param_2,param_3,param_4,z,param_5);
    return iVar1;
  }
  ERR_put_error(0x10,0xa8,0x43,"crypto/ec/ecp_smpl.c",0x1e7);
  return 0;
}

