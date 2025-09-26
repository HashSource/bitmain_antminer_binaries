
int ec_GF2m_simple_points_mul
              (EC_GROUP *param_1,EC_POINT *param_2,int param_3,uint param_4,undefined4 *param_5,
              int *param_6,BN_CTX *param_7)

{
  int iVar1;
  EC_POINT *a;
  uint uVar2;
  undefined4 uVar3;
  
  if (((1 < param_4) || (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 8)), iVar1 != 0)) ||
     (iVar1 = BN_is_zero(*(undefined4 *)(param_1 + 0xc)), iVar1 != 0)) {
    iVar1 = ec_wNAF_mul(param_1,param_2,param_3,param_4);
    return iVar1;
  }
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_4 ^ 1) & 1;
  }
  if (uVar2 == 0) {
    if (param_3 == 0) {
      param_4 = param_4 & 1;
    }
    else {
      param_4 = 0;
    }
    if (param_4 == 0) {
      a = EC_POINT_new(param_1);
      if (a == (EC_POINT *)0x0) {
        ERR_put_error(0x10,0x121,0x41,"crypto/ec/ec2_smpl.c",0x36b);
        iVar1 = 0;
      }
      else {
        iVar1 = ec_scalar_mul_ladder(param_1,a,param_3,0,param_7);
        if ((iVar1 == 0) ||
           (iVar1 = ec_scalar_mul_ladder(param_1,param_2,*param_6,*param_5,param_7), iVar1 == 0)) {
          iVar1 = 0;
        }
        else {
          iVar1 = EC_POINT_add(param_1,param_2,a,param_2,param_7);
          if (iVar1 != 0) {
            iVar1 = 1;
          }
        }
        EC_POINT_free(a);
      }
      return iVar1;
    }
    uVar3 = *param_5;
    param_3 = *param_6;
  }
  else {
    uVar3 = 0;
  }
  iVar1 = ec_scalar_mul_ladder(param_1,param_2,param_3,uVar3);
  return iVar1;
}

