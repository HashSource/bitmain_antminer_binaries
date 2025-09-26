
int ec_GF2m_simple_dbl(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if ((iVar1 == 0) && (iVar1 = EC_POINT_is_at_infinity(param_1,param_3), iVar1 == 0)) {
    iVar1 = ec_GF2m_simple_add_part_5(param_1,param_2,param_3,param_3,param_4);
  }
  else {
    iVar1 = EC_POINT_copy(param_2,param_3);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

