
int ec_GF2m_simple_add(EC_GROUP *param_1,EC_POINT *param_2,EC_POINT *param_3,EC_POINT *param_4)

{
  int iVar1;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_3);
  if (iVar1 != 0) {
    iVar1 = EC_POINT_copy(param_2,param_4);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_4);
  if (iVar1 == 0) {
    iVar1 = ec_GF2m_simple_add_part_5(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  iVar1 = EC_POINT_copy(param_2,param_3);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

