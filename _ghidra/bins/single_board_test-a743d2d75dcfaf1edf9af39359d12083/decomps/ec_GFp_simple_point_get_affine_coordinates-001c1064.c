
BIGNUM * ec_GFp_simple_point_get_affine_coordinates
                   (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *ret;
  BIGNUM *r;
  BIGNUM *r_00;
  BN_CTX *c;
  BIGNUM *n;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xa7,0x6a,"ecp_smpl.c",0x224);
    return (BIGNUM *)0x0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return (BIGNUM *)0x0;
  }
  BN_CTX_start(param_5);
  pBVar2 = BN_CTX_get(param_5);
  ret = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  if (r_00 != (BIGNUM *)0x0) {
    if (*(code **)(*(int *)param_1 + 0x94) == (code *)0x0) {
      pBVar2 = (BIGNUM *)(param_2 + 0x2c);
    }
    else {
      iVar1 = (**(code **)(*(int *)param_1 + 0x94))(param_1,pBVar2,param_2 + 0x2c,param_5);
      if (iVar1 == 0) goto LAB_001c1144;
    }
    if (((pBVar2->top == 1) && (*pBVar2->d == 1)) && (pBVar2->neg == 0)) {
      if (*(code **)(*(int *)param_1 + 0x94) == (code *)0x0) {
        if ((param_3 != (BIGNUM *)0x0) &&
           (pBVar2 = BN_copy(param_3,(BIGNUM *)(param_2 + 4)), pBVar2 == (BIGNUM *)0x0))
        goto LAB_001c1144;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar2 = BN_copy(param_4,(BIGNUM *)(param_2 + 0x18));
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          goto LAB_001c1146;
        }
      }
      else {
        if ((param_3 != (BIGNUM *)0x0) &&
           (iVar1 = (**(code **)(*(int *)param_1 + 0x94))(param_1,param_3,param_2 + 4,param_5),
           iVar1 == 0)) goto LAB_001c1144;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)
                   (**(code **)(*(int *)param_1 + 0x94))(param_1,param_4,param_2 + 0x18,param_5);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          goto LAB_001c1146;
        }
      }
LAB_001c1224:
      pBVar2 = (BIGNUM *)0x1;
      goto LAB_001c1146;
    }
    n = (BIGNUM *)(param_1 + 0x48);
    pBVar2 = BN_mod_inverse(ret,pBVar2,n,param_5);
    if (pBVar2 == (BIGNUM *)0x0) {
      ERR_put_error(0x10,0xa7,3,"ecp_smpl.c",599);
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_001c1146;
    }
    if (*(int *)(*(int *)param_1 + 0x90) == 0) {
      iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,r,ret,param_5);
    }
    else {
      iVar1 = BN_mod_sqr(r,ret,n,param_5);
    }
    if ((iVar1 != 0) &&
       ((param_3 == (BIGNUM *)0x0 ||
        (iVar1 = (**(code **)(*(int *)param_1 + 0x84))(param_1,param_3,param_2 + 4,r,param_5),
        iVar1 != 0)))) {
      if (param_4 == (BIGNUM *)0x0) goto LAB_001c1224;
      if (*(int *)(*(int *)param_1 + 0x90) == 0) {
        iVar1 = (**(code **)(*(int *)param_1 + 0x84))(param_1,r_00,r,ret);
      }
      else {
        iVar1 = BN_mod_mul(r_00,r,ret,n,param_5);
      }
      if (iVar1 != 0) {
        pBVar2 = (BIGNUM *)
                 (**(code **)(*(int *)param_1 + 0x84))(param_1,param_4,param_2 + 0x18,r_00,param_5);
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
        goto LAB_001c1146;
      }
    }
  }
LAB_001c1144:
  pBVar2 = (BIGNUM *)0x0;
LAB_001c1146:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return pBVar2;
}

