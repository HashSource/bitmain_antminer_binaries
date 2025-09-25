
BIGNUM * ec_GFp_simple_point_get_affine_coordinates
                   (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4,
                   BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *r_00;
  BN_CTX *c;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    ERR_put_error(0x10,0xa7,0x6a,"crypto/ec/ecp_smpl.c",0x1fb);
    return (BIGNUM *)0x0;
  }
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return (BIGNUM *)0x0;
  }
  BN_CTX_start(param_5);
  pBVar2 = BN_CTX_get(param_5);
  a = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  if (r_00 != (BIGNUM *)0x0) {
    if (*(code **)(*(int *)param_1 + 0x9c) == (code *)0x0) {
      pBVar2 = *(BIGNUM **)(param_2 + 0x10);
    }
    else {
      iVar1 = (**(code **)(*(int *)param_1 + 0x9c))
                        (param_1,pBVar2,*(undefined4 *)(param_2 + 0x10),param_5);
      if (iVar1 == 0) goto LAB_0011ec6e;
    }
    iVar1 = BN_is_one(pBVar2);
    if (iVar1 != 0) {
      if (*(code **)(*(int *)param_1 + 0x9c) == (code *)0x0) {
        if ((param_3 != (BIGNUM *)0x0) &&
           (pBVar2 = BN_copy(param_3,*(BIGNUM **)(param_2 + 8)), pBVar2 == (BIGNUM *)0x0))
        goto LAB_0011ec6e;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar2 = BN_copy(param_4,*(BIGNUM **)(param_2 + 0xc));
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          goto LAB_0011ec70;
        }
      }
      else {
        if ((param_3 != (BIGNUM *)0x0) &&
           (iVar1 = (**(code **)(*(int *)param_1 + 0x9c))
                              (param_1,param_3,*(undefined4 *)(param_2 + 8),param_5), iVar1 == 0))
        goto LAB_0011ec6e;
        if (param_4 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)
                   (**(code **)(*(int *)param_1 + 0x9c))
                             (param_1,param_4,*(undefined4 *)(param_2 + 0xc),param_5);
          if (pBVar2 != (BIGNUM *)0x0) {
            pBVar2 = (BIGNUM *)0x1;
          }
          goto LAB_0011ec70;
        }
      }
LAB_0011ecb6:
      pBVar2 = (BIGNUM *)0x1;
      goto LAB_0011ec70;
    }
    iVar1 = (**(code **)(*(int *)param_1 + 0x94))(param_1,a,pBVar2,param_5);
    if (iVar1 == 0) {
      ERR_put_error(0x10,0xa7,3,"crypto/ec/ecp_smpl.c",0x22e);
      pBVar2 = (BIGNUM *)0x0;
      goto LAB_0011ec70;
    }
    if (*(int *)(*(int *)param_1 + 0x98) == 0) {
      iVar1 = (**(code **)(*(int *)param_1 + 0x8c))(param_1,r,a,param_5);
    }
    else {
      iVar1 = BN_mod_sqr(r,a,*(BIGNUM **)(param_1 + 0x28),param_5);
    }
    if ((iVar1 != 0) &&
       ((param_3 == (BIGNUM *)0x0 ||
        (iVar1 = (**(code **)(*(int *)param_1 + 0x88))
                           (param_1,param_3,*(undefined4 *)(param_2 + 8),r,param_5), iVar1 != 0))))
    {
      if (param_4 == (BIGNUM *)0x0) goto LAB_0011ecb6;
      if (*(int *)(*(int *)param_1 + 0x98) == 0) {
        iVar1 = (**(code **)(*(int *)param_1 + 0x88))(param_1,r_00,r,a,param_5);
      }
      else {
        iVar1 = BN_mod_mul(r_00,r,a,*(BIGNUM **)(param_1 + 0x28),param_5);
      }
      if (iVar1 != 0) {
        pBVar2 = (BIGNUM *)
                 (**(code **)(*(int *)param_1 + 0x88))
                           (param_1,param_4,*(undefined4 *)(param_2 + 0xc),r_00,param_5);
        if (pBVar2 != (BIGNUM *)0x0) {
          pBVar2 = (BIGNUM *)0x1;
        }
        goto LAB_0011ec70;
      }
    }
  }
LAB_0011ec6e:
  pBVar2 = (BIGNUM *)0x0;
LAB_0011ec70:
  BN_CTX_end(param_5);
  BN_CTX_free(c);
  return pBVar2;
}

